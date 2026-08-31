#include <hammy/utils.h>

void hammy_to_uppercase(char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void hammy_to_lowercase(char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}
