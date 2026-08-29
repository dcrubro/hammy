#ifndef HAMMY_EMBEDS_H
#define HAMMY_EMBEDS_H

#include <concord/discord.h>

// Constructs a generic error embed and writes it into out. Returns true on success and false on failure.
// You must allocate space for exactly one embed in the out array. This function cannot check this so please make sure yourself.
static inline bool hammy_embeds_genericerror(struct discord *client, struct discord_embed *out) {
    if (!out || !client) { return false; }

    static struct discord_embed_footer footer = { .text = "Hammy Bot" };

    out[0] = (struct discord_embed){
        .title = "An Error Occurred",
        .description = "An error occurred while processing your request.",
        .color = 0xFF0000,
        .timestamp = discord_timestamp(client),
        .footer = &footer,
    };

    return true;
}

// Constructs a custom error embed and writes it into out. Returns true on success and false on failure.
// You must allocate space for exactly one embed in the out array. This function cannot check this so please make sure yourself.
static inline bool hammy_embeds_customerror(struct discord *client,
                                            struct discord_embed *out,
                                            struct discord_embed_fields *fieldsOut,
                                            char *title,
                                            char *description,
                                            struct discord_embed_field *fields,
                                            int fieldCount)
{
    if (!out || !client || !title || !description) { return false; }
    if (fieldCount < 0 || (fieldCount > 0 && !fields)) { return false; }
    if (fieldCount > 0 && !fieldsOut) { return false; }

    static struct discord_embed_footer footer = { .text = "Hammy Bot" };

    if (fieldCount > 0) {
        *fieldsOut = (struct discord_embed_fields){
            .size = fieldCount,
            .array = fields,
        };
    }

    out[0] = (struct discord_embed){
        .title = title,
        .description = description,
        .color = 0xFF0000,
        .timestamp = discord_timestamp(client),
        .footer = &footer,
        .fields = (fieldCount > 0) ? fieldsOut : NULL,
    };

    return true;
}

// Constructs a custom generic embed and writes it into out. Returns true on success and false on failure.
// You must allocate space for exactly one embed in the out array. This function cannot check this so please make sure yourself.
static inline bool hammy_embeds_customembed(struct discord *client,
                                              struct discord_embed *out,
                                              struct discord_embed_fields *fieldsOut,
                                              char *title,
                                              char *description,
                                              struct discord_embed_field *fields,
                                              int fieldCount,
                                              int color)
{
    if (!out || !client || !title || !description) { return false; }
    if (fieldCount < 0 || (fieldCount > 0 && !fields)) { return false; }
    if (fieldCount > 0 && !fieldsOut) { return false; }

    static struct discord_embed_footer footer = { .text = "Hammy Bot" };

    if (fieldCount > 0) {
        *fieldsOut = (struct discord_embed_fields){
            .size = fieldCount,
            .array = fields,
        };
    }

    out[0] = (struct discord_embed){
        .title = title,
        .description = description,
        .color = color,
        .timestamp = discord_timestamp(client),
        .footer = &footer,
        .fields = (fieldCount > 0) ? fieldsOut : NULL,
    };

    return true;
}

#endif
