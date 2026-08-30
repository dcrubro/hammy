# C23 requires CMake 3.21 or newer for CMAKE_C_STANDARD 23; 3.24 also gives
# FetchContent the git submodule and progress behaviour Concord needs.
cmake_minimum_required(VERSION 3.24)

project(hammy
    VERSION 0.1.0
    LANGUAGES C
)

# C23 needs GCC 13+, Clang 18+ or MSVC 17.9+. Extensions are off, so anything
# outside the standard (POSIX, BSD) has to be requested by feature-test macro;
# see the target_compile_definitions block at the bottom.
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ---------------------------------------------------------
# Build configuration
#
#   cmake -S . -B build          -DCMAKE_BUILD_TYPE=Debug     # -Og -g3, ASan + UBSan
#   cmake -S . -B build-strict   -DCMAKE_BUILD_TYPE=Strict    # Debug plus -Werror
#   cmake -S . -B build-analyzer -DCMAKE_BUILD_TYPE=Analyzer  # -Og -g3, GCC -fanalyzer
#   cmake -S . -B build-release  -DCMAKE_BUILD_TYPE=Release   # -O3, _FORTIFY_SOURCE
#
# Debug finds memory bugs at run time, Analyzer finds them at compile time,
# Release survives them. Strict is Debug with warnings promoted to errors — the
# configuration CI should gate on, kept separate so a new warning never blocks
# someone mid-debugging. The warning set is identical in all four; only the
# instrumentation and the error policy differ.
#
# Debug and Analyzer are separate configurations rather than one Debug build
# with everything switched on, because the two tools actively interfere: ASan's
# instrumentation inflates the CFG enough that -fanalyzer exhausts its
# exploration budget and silently stops reporting.
#
# ThreadSanitizer is deliberately absent: it cannot be combined with ASan, so it
# would need a third configuration of its own.
# ---------------------------------------------------------
set(HAMMY_CUSTOM_CONFIGS Strict Analyzer)
set(HAMMY_BUILD_TYPES Debug Strict Analyzer Release RelWithDebInfo MinSizeRel)

get_property(HAMMY_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(HAMMY_MULTI_CONFIG)
    foreach(_cfg IN LISTS HAMMY_CUSTOM_CONFIGS)
        if(NOT "${_cfg}" IN_LIST CMAKE_CONFIGURATION_TYPES)
            list(APPEND CMAKE_CONFIGURATION_TYPES ${_cfg})
        endif()
    endforeach()
elseif(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
    message(STATUS "No CMAKE_BUILD_TYPE specified; defaulting to Debug")
endif()
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${HAMMY_BUILD_TYPES})

# Strict and Analyzer are custom configurations, so CMake has no built-in flags
# for them. Both inherit Debug's, and imported targets (CURL::libcurl) need a
# mapping because they only ship Debug/Release/NOCONFIG.
foreach(_cfg IN LISTS HAMMY_CUSTOM_CONFIGS)
    string(TOUPPER ${_cfg} _cfg_upper)
    set(CMAKE_C_FLAGS_${_cfg_upper} "${CMAKE_C_FLAGS_DEBUG}"
        CACHE STRING "Flags used by the C compiler during ${_cfg} builds.")
    mark_as_advanced(CMAKE_C_FLAGS_${_cfg_upper})
    foreach(_linker EXE SHARED MODULE STATIC)
        set(CMAKE_${_linker}_LINKER_FLAGS_${_cfg_upper} "${CMAKE_${_linker}_LINKER_FLAGS_DEBUG}"
            CACHE STRING "Flags used by the linker during ${_cfg} builds.")
        mark_as_advanced(CMAKE_${_linker}_LINKER_FLAGS_${_cfg_upper})
    endforeach()
    set(CMAKE_MAP_IMPORTED_CONFIG_${_cfg_upper} Debug "" Release RelWithDebInfo)
endforeach()

# Debug, Strict and Analyzer share the developer flag set (-Og -g3, warnings).
set(HAMMY_IS_DEBUGLIKE "$<OR:$<CONFIG:Debug>,$<CONFIG:Strict>,$<CONFIG:Analyzer>>")
# Debug and Strict are the runtime-instrumented pair; Analyzer must stay clean
# of sanitizers or -fanalyzer goes quiet (see above).
set(HAMMY_IS_SANITIZED "$<OR:$<CONFIG:Debug>,$<CONFIG:Strict>>")

# The Strict configuration always errors on warnings; this option additionally
# promotes them in Debug and Analyzer. OFF until src/ is clean under the warning
# set below — until then, build Strict when you want the gate.
option(HAMMY_WERROR "Debug/Analyzer: treat warnings as errors (always on in Strict)" OFF)
option(HAMMY_ENABLE_SANITIZERS "Debug config: AddressSanitizer + UndefinedBehaviorSanitizer" ON)
option(HAMMY_ENABLE_ANALYZER "Analyzer config: the compiler's static analyzer (GCC -fanalyzer)" ON)

# How much of the control-flow path -fanalyzer prints per report. 1 lists only
# the state transitions (opened here / first close here / leaks here), which is
# what you want while triaging; raise it when a report needs the branch-by-branch
# path that explains how it got there. GCC silently accepts out-of-range values,
# so validate here instead.
set(ANALYZER_VERBOSITY 1 CACHE STRING "Analyzer config: -fanalyzer path detail, 0 (terse) to 5 (full)")
set_property(CACHE ANALYZER_VERBOSITY PROPERTY STRINGS 0 1 2 3 4 5)
if(NOT ANALYZER_VERBOSITY MATCHES "^[0-5]$")
    message(FATAL_ERROR "ANALYZER_VERBOSITY must be an integer from 0 to 5, got '${ANALYZER_VERBOSITY}'")
endif()
option(HAMMY_ENABLE_HARDENING "All configs: stack protector, _FORTIFY_SOURCE, RELRO/NOW, CFI" ON)
option(HAMMY_ENABLE_LTO "Optimized configs: link-time optimization" OFF)

include(CheckCCompilerFlag)
include(CheckLinkerFlag)

# Most of the interesting memory diagnostics below only exist from a certain
# GCC/Clang version onwards, and several are architecture specific. Probe every
# flag instead of gating on compiler version, so an older or foreign toolchain
# silently gets the subset it understands rather than failing to configure.
#
# A flag the driver merely tolerates is not a flag that does anything (Clang
# accepts -fstack-clash-protection on arm64 and then ignores it), so the probe
# promotes "argument unused" to an error where the compiler supports that.
check_c_compiler_flag(-Werror=unused-command-line-argument HAMMY_HAS_WERROR_UNUSED_ARG)
if(HAMMY_HAS_WERROR_UNUSED_ARG)
    set(HAMMY_FLAG_PROBE_STRICT "-Werror=unused-command-line-argument")
else()
    set(HAMMY_FLAG_PROBE_STRICT "")
endif()

function(hammy_append_supported_c_flags out_var)
    set(_accepted ${${out_var}})
    set(CMAKE_REQUIRED_FLAGS "${HAMMY_FLAG_PROBE_STRICT}")
    foreach(_flag IN LISTS ARGN)
        string(MAKE_C_IDENTIFIER "HAMMY_HAS_CFLAG_${_flag}" _cache_var)
        check_c_compiler_flag("${_flag}" ${_cache_var})
        if(${_cache_var})
            list(APPEND _accepted "${_flag}")
        endif()
    endforeach()
    set(${out_var} "${_accepted}" PARENT_SCOPE)
endfunction()

# Instrumentation such as -fsanitize=address has to reach the linker as well,
# and is only usable if the matching runtime library actually exists, so the
# probe hands the flag to both halves of the try-compile.
#
# Flags are also probed cumulatively, in the order given: some are only legal in
# the presence of an earlier one (-fsanitize=pointer-compare is rejected unless
# -fsanitize=address is already on the command line), and probing it alone would
# quietly drop it.
function(hammy_append_supported_instrument_flags out_var)
    set(_accepted ${${out_var}})
    set(_context "")
    foreach(_flag IN LISTS ARGN)
        string(MAKE_C_IDENTIFIER "HAMMY_HAS_INSTRUMENT_${_flag}" _cache_var)
        string(JOIN " " CMAKE_REQUIRED_FLAGS ${HAMMY_FLAG_PROBE_STRICT} ${_context})
        set(CMAKE_REQUIRED_LINK_OPTIONS ${_context} "${_flag}")
        check_c_compiler_flag("${_flag}" ${_cache_var})
        if(${_cache_var})
            list(APPEND _accepted "${_flag}")
            list(APPEND _context "${_flag}")
        endif()
    endforeach()
    set(${out_var} "${_accepted}" PARENT_SCOPE)
endfunction()

function(hammy_append_supported_link_flags out_var)
    set(_accepted ${${out_var}})
    foreach(_flag IN LISTS ARGN)
        string(MAKE_C_IDENTIFIER "HAMMY_HAS_LDFLAG_${_flag}" _cache_var)
        check_linker_flag(C "${_flag}" ${_cache_var})
        if(${_cache_var})
            list(APPEND _accepted "${_flag}")
        endif()
    endforeach()
    set(${out_var} "${_accepted}" PARENT_SCOPE)
endfunction()

# Warnings for our own C code; the per-config flag sets are applied through
# generator expressions so multi-config generators (Xcode, VS) work too.
set(HAMMY_C_WARNINGS "")
set(HAMMY_C_FLAGS_DEBUGLIKE "")
set(HAMMY_C_FLAGS_OPTIMIZED "")
# The two instrumentation sets, each owned by one configuration and never both.
set(HAMMY_SANITIZER_FLAGS "")
set(HAMMY_ANALYZER_FLAGS "")
# Instrumentation that must be handed to the linker as well, and that also
# covers the third-party code we link in.
set(HAMMY_INSTRUMENT_COMPILE "")
set(HAMMY_INSTRUMENT_LINK "")

if(MSVC)
    set(HAMMY_WERROR_FLAG /WX)
    list(APPEND HAMMY_C_WARNINGS /W4 /permissive- /sdl)
    list(APPEND HAMMY_C_FLAGS_DEBUGLIKE /Od /RTC1 /GS)
    list(APPEND HAMMY_C_FLAGS_OPTIMIZED /O2 /GS /guard:cf)
    if(HAMMY_WERROR)
        list(APPEND HAMMY_C_FLAGS_DEBUGLIKE ${HAMMY_WERROR_FLAG})
    endif()
    if(HAMMY_ENABLE_ANALYZER)
        list(APPEND HAMMY_ANALYZER_FLAGS /analyze)
    endif()
    if(HAMMY_ENABLE_SANITIZERS)
        list(APPEND HAMMY_SANITIZER_FLAGS /fsanitize=address)
    endif()
else()
    set(HAMMY_WERROR_FLAG -Werror)
    # Portable warning set, memory-safety first.
    hammy_append_supported_c_flags(HAMMY_C_WARNINGS
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Wsign-conversion
        #-Wcast-qual
        -Wcast-align
        -Wstrict-prototypes
        -Wmissing-prototypes
        -Wold-style-definition
        -Wbad-function-cast
        -Wwrite-strings
        -Wformat=2
        -Wnull-dereference
        -Wdouble-promotion
        -Wfloat-equal
        -Wvla
        -Wstack-protector
        -Wpointer-arith
        -Wundef
        -Winit-self
        -Wmissing-include-dirs
        -Wno-discarded-qualifiers # Temp
    )

    if(CMAKE_C_COMPILER_ID MATCHES "GNU")
        # GCC-only diagnostics. The -W*=N forms ask for the strictest level:
        # more false positives, but they catch out-of-bounds writes, dangling
        # pointers and double frees that -Wall/-Wextra walk straight past.
        hammy_append_supported_c_flags(HAMMY_C_WARNINGS
            -Warray-bounds=2
            -Wstringop-overflow=4
            -Wstringop-truncation
            -Wformat-overflow=2
            -Wformat-truncation=2
            -Wuse-after-free=3
            -Wdangling-pointer=2
            -Wfree-nonheap-object
            -Walloc-zero
            -Walloca
            -Wduplicated-cond
            -Wduplicated-branches
            -Wlogical-op
            -Wjump-misses-init
            -Wtrampolines
            -Wflex-array-member-not-at-end
        )
        # -fanalyzer is a whole-path symbolic execution pass (leaks, double
        # free, use-after-free, NULL derefs across function boundaries).
        if(HAMMY_ENABLE_ANALYZER)
            hammy_append_supported_c_flags(HAMMY_ANALYZER_FLAGS
                -fanalyzer-verbosity=${ANALYZER_VERBOSITY}
                -fanalyzer
            )
        endif()
    elseif(CMAKE_C_COMPILER_ID MATCHES "Clang")
        # Clang-only diagnostics. Clang has no in-compiler equivalent of
        # -fanalyzer, so the Analyzer config is simply an uninstrumented Debug
        # build here — which is exactly the base `scan-build cmake --build
        # build-analyzer` wants.
        hammy_append_supported_c_flags(HAMMY_C_WARNINGS
            -Warray-bounds-pointer-arithmetic
            -Wconditional-uninitialized
            -Wshift-sign-overflow
            -Wassign-enum
            -Wcomma
            -Wloop-analysis
            -Wthread-safety
            -Wover-aligned
        )
    endif()

    # -Og keeps the code steppable while still running the optimizer passes
    # that -Wmaybe-uninitialized / -Wstringop-* rely on; at -O0 those warnings
    # go quiet. -fno-omit-frame-pointer buys readable sanitizer backtraces.
    hammy_append_supported_c_flags(HAMMY_C_FLAGS_DEBUGLIKE
        -Og
        -g3
        -fno-omit-frame-pointer
    )
    if(HAMMY_WERROR)
        list(APPEND HAMMY_C_FLAGS_DEBUGLIKE ${HAMMY_WERROR_FLAG})
    endif()

    if(HAMMY_ENABLE_HARDENING)
        hammy_append_supported_c_flags(HAMMY_C_FLAGS_DEBUGLIKE
            -fstack-protector-strong
        )
        # _FORTIFY_SOURCE needs an optimized build to see through the buffer
        # sizes, and it fights ASan's interceptors, so it is Release-only.
        hammy_append_supported_c_flags(HAMMY_C_FLAGS_OPTIMIZED
            -U_FORTIFY_SOURCE
            -D_FORTIFY_SOURCE=3
            -fstack-protector-strong
            -fstack-clash-protection
        )
        hammy_append_supported_instrument_flags(HAMMY_INSTRUMENT_COMPILE
            -fcf-protection=full         # x86_64 CET
            -mbranch-protection=standard # aarch64 BTI/PAC
        )
        hammy_append_supported_link_flags(HAMMY_INSTRUMENT_LINK
            "LINKER:-z,relro"
            "LINKER:-z,now"
            "LINKER:-z,noexecstack"
        )
    endif()

    if(HAMMY_ENABLE_SANITIZERS)
        # Everything that composes with ASan. LeakSanitizer is not listed
        # because ASan already includes it where it is supported, and
        # -fsanitize=leak cannot be combined with -fsanitize=address.
        # -fno-sanitize-recover makes UB abort instead of printing and
        # continuing, so a bad shift or overflow cannot be ignored in CI.
        # pointer-compare/pointer-subtract additionally need
        # ASAN_OPTIONS=detect_invalid_pointer_pairs=2 at run time.
        hammy_append_supported_instrument_flags(HAMMY_SANITIZER_FLAGS
            -fsanitize=address
            -fsanitize-address-use-after-scope
            -fsanitize=pointer-compare
            -fsanitize=pointer-subtract
            -fsanitize=undefined
            -fsanitize=bounds-strict
            -fno-sanitize-recover=undefined
            -fno-omit-frame-pointer
            -fno-sanitize=function
        )
    endif()
endif()

# Each instrumentation set belongs to exactly one configuration. Keeping them in
# separate configs is the point of the Analyzer build, so never emit both.
if(HAMMY_SANITIZER_FLAGS)
    list(APPEND HAMMY_INSTRUMENT_COMPILE "$<${HAMMY_IS_SANITIZED}:${HAMMY_SANITIZER_FLAGS}>")
    list(APPEND HAMMY_INSTRUMENT_LINK "$<${HAMMY_IS_SANITIZED}:${HAMMY_SANITIZER_FLAGS}>")
endif()

if(HAMMY_ENABLE_LTO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT HAMMY_IPO_SUPPORTED OUTPUT HAMMY_IPO_ERROR)
    if(NOT HAMMY_IPO_SUPPORTED)
        message(WARNING "LTO requested but unsupported by this toolchain: ${HAMMY_IPO_ERROR}")
    endif()
endif()

# ---------------------------------------------------------
# Concord (Discord API wrapper), pinned to the v3.0.1 release
#
# Pinned rather than tracking dev: dev reverted the notifier's portable fcntl
# setup back to ioctl(FIONBIO), cast to int. macOS FIONBIO is 0x8004667E, so the
# cast goes negative, sign-extends into ioctl's unsigned long parameter and the
# call fails -- ccord_global_init() then dies before the client is ever built.
# The release tags still carry the fcntl version. Check that the regression is
# gone before moving this back to a branch.
#
# Concord ships a hand-written Makefile, not a CMake build, so this is a
# two-stage arrangement: FetchContent clones it at configure time (recursively,
# because its cog-utils/carray dependencies are submodules), and ExternalProject
# drives `make` / `make install` at build time into a private prefix. If a
# future dev branch grows a CMakeLists.txt, FetchContent_MakeAvailable picks it
# up on its own and the Makefile path below is skipped.
#
# libcurl and pthreads are Concord's own dependencies, not ours; they are found
# here only so the static library has something to resolve against.
# ---------------------------------------------------------
find_package(Threads REQUIRED)
find_package(CURL REQUIRED)

include(FetchContent)
include(ExternalProject)

FetchContent_Declare(
    concord
    GIT_REPOSITORY https://github.com/Cogmasters/concord.git
    GIT_TAG v3.0.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
# Populates concord_SOURCE_DIR, and calls add_subdirectory() only if upstream
# actually provides a CMakeLists.txt.
FetchContent_MakeAvailable(concord)

if(TARGET discord)
    add_library(concord::concord ALIAS discord)
    set(HAMMY_CONCORD_EXTERNAL "")
elseif(TARGET concord)
    add_library(concord::concord ALIAS concord)
    set(HAMMY_CONCORD_EXTERNAL "")
else()
    if(MSVC)
        message(FATAL_ERROR
            "Concord's Makefile build needs a POSIX toolchain (make, sh). "
            "Build under MinGW/MSYS2 or WSL, or point CMake at a prebuilt libdiscord.")
    endif()
    find_program(HAMMY_MAKE_EXECUTABLE NAMES gmake make REQUIRED
        DOC "make(1) used to build the vendored Concord")

    set(CONCORD_PREFIX "${CMAKE_BINARY_DIR}/_deps/concord-install")
    set(CONCORD_INCLUDE_DIR "${CONCORD_PREFIX}/include")
    set(CONCORD_LIBRARY "${CONCORD_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}discord${CMAKE_STATIC_LIBRARY_SUFFIX}")
    # An imported target's include directory has to exist when CMake generates,
    # which is before Concord has been built.
    file(MAKE_DIRECTORY "${CONCORD_INCLUDE_DIR}")

    # Upstream's `make install` is three shell globs relative to the working
    # directory, fed to install(1). When one matches nothing the shell passes it
    # through literally and install reports `cannot stat 'include/*.h'`, which
    # says nothing about which glob mattered or why. Do the copy ourselves with
    # absolute paths and name the two failure modes that actually occur.
    #
    # The globs run at install time rather than configure time because
    # generated/discord_codecs.h does not exist until the build has emitted it.
    #
    # Keep the directory list below in step with the `install:` target in
    # upstream's Makefile; v3.0.1 renamed gencodecs/ to generated/ and split
    # reflect-c.h out into its own directory.
    set(CONCORD_INSTALL_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/concord_install.cmake")
    file(CONFIGURE
        OUTPUT "${CONCORD_INSTALL_SCRIPT}"
        @ONLY
        CONTENT [[
file(MAKE_DIRECTORY "@CONCORD_INCLUDE_DIR@/concord" "@CONCORD_PREFIX@/lib")

# Upstream flattens all three header directories into one include/concord. Check
# them one at a time: a single empty directory is the interesting failure, and a
# combined glob would hide it behind whichever siblings still matched.
set(_hdrs "")
foreach(_dir include core generated)
    file(GLOB _found "@concord_SOURCE_DIR@/${_dir}/*.h")
    if(NOT _found)
        message(FATAL_ERROR
            "Concord: no headers in @concord_SOURCE_DIR@/${_dir} -- the source "
            "tree is incomplete; remove build/_deps and reconfigure to re-clone")
    endif()
    list(APPEND _hdrs ${_found})
endforeach()

# Not part of any of the three directories, but generated/discord_codecs.h
# includes it, so discord.h does not parse without it.
if(NOT EXISTS "@concord_SOURCE_DIR@/reflect-c/reflect-c.h")
    message(FATAL_ERROR
        "Concord: missing @concord_SOURCE_DIR@/reflect-c/reflect-c.h -- the "
        "reflect-c submodule was not cloned; remove build/_deps and reconfigure")
endif()
list(APPEND _hdrs "@concord_SOURCE_DIR@/reflect-c/reflect-c.h")

file(COPY ${_hdrs} DESTINATION "@CONCORD_INCLUDE_DIR@/concord")

# third_party/concord is a checked-in mirror of the headers just installed. It
# exists so an editor has something to resolve <concord/*.h> against in a fresh
# clone, before anything has been built -- build/ is gitignored, so the copy
# above is not there yet.
#
# It is refreshed from the same file list on every build rather than left to be
# updated by hand, because it also sits FIRST on hammy's include path
# (-isystem third_party precedes the installed headers). A stale mirror would
# not merely confuse the editor, it would be what the compiler actually reads --
# hammy would build against one version of Concord and link another. Keeping the
# two byte-identical makes the ordering irrelevant. Moving GIT_TAG therefore
# shows up as a diff under third_party/concord; commit it along with the bump.
#
# Prune first: a version bump can retire a header, and one left behind in the
# mirror would still be found by the compiler. Only files that vanished upstream
# are removed -- file(COPY) preserves timestamps and skips files already
# matching, so mirroring costs one stat per header on a build that changed
# nothing. The exception is discord_codecs.h, which Concord's own build
# regenerates every time (BUILD_ALWAYS re-runs make); its mtime moves, so it is
# recopied. That does not add a rebuild -- the regenerated original already
# forces one -- and its contents are deterministic, so git stays clean.
set(_want "")
foreach(_hdr IN LISTS _hdrs)
    get_filename_component(_name "${_hdr}" NAME)
    list(APPEND _want "${_name}")
endforeach()
file(GLOB _mirrored "@CMAKE_CURRENT_SOURCE_DIR@/third_party/concord/*.h")
foreach(_old IN LISTS _mirrored)
    get_filename_component(_name "${_old}" NAME)
    if(NOT "${_name}" IN_LIST _want)
        file(REMOVE "${_old}")
    endif()
endforeach()
file(COPY ${_hdrs} DESTINATION "@CMAKE_CURRENT_SOURCE_DIR@/third_party/concord")

file(GLOB _libs "@concord_SOURCE_DIR@/lib/libdiscord.*")
if(NOT _libs)
    message(FATAL_ERROR "Concord: build produced no library in @concord_SOURCE_DIR@/lib")
endif()
file(COPY ${_libs} DESTINATION "@CONCORD_PREFIX@/lib")
]])

    # Concord gets our instrumentation but not our warning set: ASan only sees a
    # bug if the translation unit that owns the memory was compiled with it, and
    # Concord allocates plenty that our code then touches. CFLAGS goes through
    # the environment rather than the make command line because Concord's
    # Makefile appends its own -I flags to it; a command-line assignment would
    # override those and break the build.
    # ... with one carve-out. chash.h's string hash is djb2-style:
    #   (hash) = (((hash) << 1) + (hash)) + key[i];
    # on a signed accumulator, so it deliberately relies on wraparound. That is
    # two counts of UB per character -- the shift of a negative value and the
    # overflowing add -- plus a third in the __chash_abs() that follows. With
    # -fno-sanitize-recover it aborts the first time a ratelimit key hashes past
    # LONG_MAX, which a guild command endpoint manages immediately.
    #
    # The wraparound is benign and the code is not ours to fix, so drop these
    # two checks for Concord's build only. Everything else UBSan looks at stays
    # on, and our own translation units keep the full set -- these flags are not
    # in HAMMY_SANITIZER_FLAGS, only here.
    set(CONCORD_UB_CARVEOUTS "-fno-sanitize=signed-integer-overflow -fno-sanitize=shift")
    set(CONCORD_CFLAGS "-O2 -g $<JOIN:${HAMMY_INSTRUMENT_COMPILE}, > $<${HAMMY_IS_SANITIZED}:${CONCORD_UB_CARVEOUTS}>")

    # gencodecs/Makefile hardcodes CC/HOSTCC/CPP to "cc" for its host-side code
    # generator, with plain '=' assignments that the environment cannot override.
    # On a system where cc is GCC and we build with Clang, the generator is then
    # handed our Clang-only flags (-fno-sanitize=function) and dies. Command-line
    # assignments do beat makefile assignments, so force the compiler there --
    # while leaving CFLAGS in the environment, per the note above.
    #
    # gencodecs-pp is a build-time text filter, run as `cpp ... | ./gencodecs-pp`.
    # ASan's exit-time leak check would turn a leak in that throwaway tool into a
    # build failure reported as a broken pipeline, so switch it off for the
    # duration of Concord's build only; our own binary is unaffected.
    ExternalProject_Add(concord_external
        SOURCE_DIR "${concord_SOURCE_DIR}"
        DOWNLOAD_COMMAND ""     # FetchContent already cloned it
        UPDATE_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_IN_SOURCE TRUE    # upstream's Makefile has no out-of-tree mode
        # Upstream tracks nothing we can express as a byproduct, so the stamp
        # would happily report "built" after a `make clean` emptied lib/.
        BUILD_ALWAYS TRUE
        BUILD_COMMAND ${CMAKE_COMMAND} -E env
                      "CC=${CMAKE_C_COMPILER}"
                      "CFLAGS=${CONCORD_CFLAGS}"
                      "ASAN_OPTIONS=detect_leaks=0"
                      ${HAMMY_MAKE_EXECUTABLE}
                      "CC=${CMAKE_C_COMPILER}"
                      "HOSTCC=${CMAKE_C_COMPILER}"
                      "CPP=${CMAKE_C_COMPILER} -E"
        INSTALL_COMMAND ${CMAKE_COMMAND} -P "${CONCORD_INSTALL_SCRIPT}"
        BUILD_BYPRODUCTS "${CONCORD_LIBRARY}"
        # USES_TERMINAL_BUILD would silently disable LOG_BUILD; with
        # LOG_OUTPUT_ON_FAILURE we get the full log exactly when it matters.
        LOG_BUILD TRUE
        LOG_INSTALL TRUE
        LOG_OUTPUT_ON_FAILURE TRUE
    )

    add_library(concord::concord STATIC IMPORTED GLOBAL)
    set_target_properties(concord::concord PROPERTIES
        IMPORTED_LOCATION "${CONCORD_LIBRARY}"
        # Imported targets' interface includes are -isystem by default, so
        # Concord's headers never trip our warning set.
        INTERFACE_INCLUDE_DIRECTORIES "${CONCORD_INCLUDE_DIR}"
    )
    target_link_libraries(concord::concord INTERFACE CURL::libcurl Threads::Threads)
    # Imported targets cannot carry add_dependencies(); the consumer does.
    set(HAMMY_CONCORD_EXTERNAL concord_external)
endif()

# ---------------------------------------------------------
# SQLite3 (hammy's own dependency, unlike the Concord ones above)
#
# CMake's bundled FindSQLite3 module (3.14+) exports the SQLite::SQLite3
# imported target and covers both a system package and a manually-specified
# SQLITE3_INCLUDE_DIR/SQLITE3_LIBRARY, so no vendoring is needed here.
# ---------------------------------------------------------
find_package(SQLite3 REQUIRED)

# ---------------------------------------------------------
# Output directories
# ---------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

foreach(OUTPUTCONFIG IN LISTS HAMMY_BUILD_TYPES)
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/lib)
endforeach()

# ---------------------------------------------------------
# hammy
# ---------------------------------------------------------
file(GLOB_RECURSE HAMMY_SRC CONFIGURE_DEPENDS src/*.c)
add_executable(hammy ${HAMMY_SRC})

target_include_directories(hammy PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(hammy SYSTEM PRIVATE
    ${PROJECT_SOURCE_DIR}/third_party
)

# Concord's headers arrive through concord::concord. CMake passes an imported
# target's interface includes as -isystem, so upstream's headers never trip our
# warning set and no second copy under third_party/ is needed.

target_link_libraries(hammy PRIVATE concord::concord SQLite::SQLite3)
if(HAMMY_CONCORD_EXTERNAL)
    add_dependencies(hammy ${HAMMY_CONCORD_EXTERNAL})
endif()

target_compile_options(hammy PRIVATE
    "${HAMMY_C_WARNINGS}"
    "${HAMMY_INSTRUMENT_COMPILE}"
    "$<${HAMMY_IS_DEBUGLIKE}:${HAMMY_C_FLAGS_DEBUGLIKE}>"
    "$<$<NOT:${HAMMY_IS_DEBUGLIKE}>:${HAMMY_C_FLAGS_OPTIMIZED}>"
    # The static analyzer runs on our C sources only, and never alongside the
    # sanitizers.
    "$<$<CONFIG:Analyzer>:${HAMMY_ANALYZER_FLAGS}>"
    # Strict is Debug with the warning set turned into a build gate.
    "$<$<CONFIG:Strict>:${HAMMY_WERROR_FLAG}>"
)
target_link_options(hammy PRIVATE "${HAMMY_INSTRUMENT_LINK}")

if(HAMMY_ENABLE_LTO AND HAMMY_IPO_SUPPORTED)
    set_target_properties(hammy PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE ON
        INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO ON
        INTERPROCEDURAL_OPTIMIZATION_MINSIZEREL ON
    )
endif()

# CMAKE_C_EXTENSIONS is OFF, so -std=c23 hides everything outside the standard;
# Concord's headers and our own use of POSIX threads and sockets need these.
target_compile_definitions(hammy PRIVATE
    _POSIX_C_SOURCE=200809L
    _DEFAULT_SOURCE
)

set_target_properties(hammy PROPERTIES OUTPUT_NAME "hammy")

# ---------------------------------------------------------
# Configuration summary
# ---------------------------------------------------------
message(STATUS "hammy: build type      ${CMAKE_BUILD_TYPE}")
message(STATUS "hammy: compiler        ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION} (C${CMAKE_C_STANDARD})")
message(STATUS "hammy: warnings-as-err ${HAMMY_WERROR} (always on in Strict)")
message(STATUS "hammy: sanitizers      [Debug/Strict] ${HAMMY_SANITIZER_FLAGS}")
message(STATUS "hammy: static analyzer [Analyzer]     ${HAMMY_ANALYZER_FLAGS}")
message(STATUS "hammy: hardening       ${HAMMY_ENABLE_HARDENING}")
message(STATUS "hammy: LTO             ${HAMMY_ENABLE_LTO}")
message(STATUS "hammy: concord         ${concord_SOURCE_DIR} (v3.0.1)")
message(STATUS "hammy: sqlite3         ${SQLite3_LIBRARIES} (v${SQLite3_VERSION})")
if(CMAKE_BUILD_TYPE STREQUAL "Analyzer" AND NOT HAMMY_ANALYZER_FLAGS)
    message(STATUS "hammy: NOTE - Analyzer config has no static analyzer on "
                   "${CMAKE_C_COMPILER_ID}; use scan-build over this build tree")
endif()
