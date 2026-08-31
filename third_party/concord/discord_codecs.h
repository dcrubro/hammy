#ifndef REFLECT_C_GENERATED_H
#define REFLECT_C_GENERATED_H



#define DISCORD_APPLICATION_GATEWAY_PRESENCE (1 << 12)
#define DISCORD_APPLICATION_GATEWAY_PRESENCE_LIMITED (1 << 13)
#define DISCORD_APPLICATION_GATEWAY_GUILD_MEMBERS (1 << 14)
#define DISCORD_APPLICATION_GATEWAY_GUILD_MEMBERS_LIMITED (1 << 15)
#define DISCORD_APPLICATION_VERIFICATION_PENDING_GUILD_LIMIT (1 << 16)
#define DISCORD_APPLICATION_EMBEDDED (1 << 17)
#define DISCORD_APPLICATION_GATEWAY_MESSAGE_CONTENT (1 << 18)
#define DISCORD_APPLICATION_GATEWAY_MESSAGE_CONTENT_LIMITED (1 << 19)
















































#define DISCORD_CHANNEL_PINNED (1 << 1)
#define DISCORD_CHANNEL_REQUIRE_TAG (1 << 4)
#define DISCORD_CHANNEL_HIDE_MEDIA_DOWNLOAD_OPTIONS (1 << 5)
#define DISCORD_MESSAGE_CROSSPOSTED (1 << 0)
#define DISCORD_MESSAGE_IS_CROSSPOST (1 << 1)
#define DISCORD_MESSAGE_SUPPRESS_EMBEDS (1 << 2)
#define DISCORD_MESSAGE_SOURCE_MESSAGE_DELETED (1 << 3)
#define DISCORD_MESSAGE_URGENT (1 << 4)
#define DISCORD_MESSAGE_HAS_THREAD (1 << 5)
#define DISCORD_MESSAGE_EPHEMERAL (1 << 6)
#define DISCORD_MESSAGE_LOADING (1 << 7)
#define DISCORD_MESSAGE_FAILED_TO_MENTION_SOME_ROLES_IN_THREAD (1 << 8)
#define DISCORD_MESSAGE_SUPPRESS_NOTIFICATIONS (1 << 12)
#define DISCORD_MESSAGE_IS_VOICE_MESSAGE (1 << 13)
#define DISCORD_MESSAGE_HAS_COMPONENTS_V2 (1 << 15)
#define DISCORD_ATTACHMENT_IS_REMIX (1 << 2)





























































#include <inttypes.h>
#include <stdbool.h>
#include "carray.h"
#include "cog-utils.h"
#include "types.h"
#include "concord-error.h"
#define CONCORD_OPTIONAL (1 << 0ull)
#define CONCORD_NO_JSON  (1 << 1ull)













#define DISCORD_GATEWAY_GUILDS (1 << 0)
#define DISCORD_GATEWAY_GUILD_MEMBERS (1 << 1)
#define DISCORD_GATEWAY_GUILD_BANS (1 << 2)
#define DISCORD_GATEWAY_GUILD_EMOJIS_AND_STICKERS (1 << 3)
#define DISCORD_GATEWAY_GUILD_INTEGRATIONS (1 << 4)
#define DISCORD_GATEWAY_GUILD_WEBHOOKS (1 << 5)
#define DISCORD_GATEWAY_GUILD_INVITES (1 << 6)
#define DISCORD_GATEWAY_GUILD_VOICE_STATES (1 << 7)
#define DISCORD_GATEWAY_GUILD_PRESENCES (1 << 8)
#define DISCORD_GATEWAY_GUILD_MESSAGES (1 << 9)
#define DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS (1 << 10)
#define DISCORD_GATEWAY_GUILD_MESSAGE_TYPING (1 << 11)
#define DISCORD_GATEWAY_DIRECT_MESSAGES (1 << 12)
#define DISCORD_GATEWAY_DIRECT_MESSAGE_REACTIONS (1 << 13)
#define DISCORD_GATEWAY_DIRECT_MESSAGE_TYPING (1 << 14)
#define DISCORD_GATEWAY_MESSAGE_CONTENT (1 << 15)
#define DISCORD_GATEWAY_GUILD_SCHEDULED_EVENTS (1 << 16)
#define DISCORD_GATEWAY_AUTO_MODERATION_CONFIGURATION (1 << 20)
#define DISCORD_GATEWAY_AUTO_MODERATION_EXECUTION (1 << 21)
#define DISCORD_ACTIVITY_INSTANCE (1 << 0)
#define DISCORD_ACTIVITY_JOIN (1 << 1)
#define DISCORD_ACTIVITY_SPECTATE (1 << 2)
#define DISCORD_ACTIVITY_JOIN_REQUEST (1 << 3)
#define DISCORD_ACTIVITY_SYNC (1 << 4)
#define DISCORD_ACTIVITY_PLAY (1 << 5)
#define DISCORD_ACTIVITY_PARTY_PRIVACY_FRIENDS (1 << 6)
#define DISCORD_ACTIVITY_PARTY_PRIVACY_VOICE_CHANNEL (1 << 7)
#define DISCORD_ACTIVITY_EMBEDDED (1 << 8)






















































#define DISCORD_SYSTEM_SUPPRESS_JOIN_NOTIFICATIONS (1 << 0)
#define DISCORD_SYSTEM_SUPPRESS_PREMIUM_NOTIFICATIONS (1 << 1)
#define DISCORD_SYSTEM_SUPPRESS_GUILD_REMINDER_NOTIFICATIONS (1 << 2)
#define DISCORD_SYSTEM_SUPPRESS_JOIN_NOTIFICATION_REPLIES (1 << 3)







































































































#define DISCORD_PERM_CREATE_INSTANT_INVITE (1 << 0)
#define DISCORD_PERM_KICK_MEMBERS (1 << 1)
#define DISCORD_PERM_BAN_MEMBERS (1 << 2)
#define DISCORD_PERM_ADMINISTRATOR (1 << 3)
#define DISCORD_PERM_MANAGE_CHANNELS (1 << 4)
#define DISCORD_PERM_MANAGE_GUILD (1 << 5)
#define DISCORD_PERM_ADD_REACTIONS (1 << 6)
#define DISCORD_PERM_VIEW_AUDIT_LOG (1 << 7)
#define DISCORD_PERM_PRIORITY_SPEAKER (1 << 8)
#define DISCORD_PERM_STREAM (1 << 9)
#define DISCORD_PERM_VIEW_CHANNEL (1 << 10)
#define DISCORD_PERM_SEND_MESSAGES (1 << 11)
#define DISCORD_PERM_SEND_TTS_MESSAGES (1 << 12)
#define DISCORD_PERM_MANAGE_MESSAGES (1 << 13)
#define DISCORD_PERM_EMBED_LINKS (1 << 14)
#define DISCORD_PERM_ATTACH_FILES (1 << 15)
#define DISCORD_PERM_READ_MESSAGE_HISTORY (1 << 16)
#define DISCORD_PERM_MENTION_EVERYONE (1 << 17)
#define DISCORD_PERM_USE_EXTERNAL_EMOJIS (1 << 18)
#define DISCORD_PERM_VIEW_GUILD_INSIGHTS (1 << 19)
#define DISCORD_PERM_CONNECT (1 << 20)
#define DISCORD_PERM_SPEAK (1 << 21)
#define DISCORD_PERM_MUTE_MEMBERS (1 << 22)
#define DISCORD_PERM_DEAFEN_MEMBERS (1 << 23)
#define DISCORD_PERM_MOVE_MEMBERS (1 << 24)
#define DISCORD_PERM_USE_VAD (1 << 25)
#define DISCORD_PERM_CHANGE_NICKNAME (1 << 26)
#define DISCORD_PERM_MANAGE_NICKNAMES (1 << 27)
#define DISCORD_PERM_MANAGE_ROLES (1 << 28)
#define DISCORD_PERM_MANAGE_WEBHOOKS (1 << 29)
#define DISCORD_PERM_MANAGE_EMOJIS_AND_STICKERS (1 << 30)
#define DISCORD_PERM_USE_APPLICATION_COMMANDS (1 << 31)
#define DISCORD_PERM_REQUEST_TO_SPEAK (1 << 32)
#define DISCORD_PERM_MANAGE_EVENTS (1 << 33)
#define DISCORD_PERM_MANAGE_THREADS (1 << 34)
#define DISCORD_PERM_CREATE_PUBLIC_THREADS (1 << 35)
#define DISCORD_PERM_CREATE_PRIVATE_THREADS (1 << 36)
#define DISCORD_PERM_USE_EXTERNAL_STICKERS (1 << 37)
#define DISCORD_PERM_SEND_MESSAGES_IN_THREADS (1 << 38)
#define DISCORD_PERM_START_EMBEDDED_ACTIVITIES (1 << 39)
#define DISCORD_PERM_MODERATE_MEMBERS (1 << 40)




























#define DISCORD_USER_NONE (0)
#define DISCORD_USER_STAFF (1 << 0)
#define DISCORD_USER_PARTNER (1 << 1)
#define DISCORD_USER_HYPESQUAD (1 << 2)
#define DISCORD_USER_BUG_HUNTER_LEVEL_1 (1 << 3)
#define DISCORD_USER_HYPESQUAD_ONLINE_HOUSE_1 (1 << 6)
#define DISCORD_USER_HYPESQUAD_ONLINE_HOUSE_2 (1 << 7)
#define DISCORD_USER_HYPESQUAD_ONLINE_HOUSE_3 (1 << 8)
#define DISCORD_USER_PREMIUM_EARLY_SUPPORTER (1 << 9)
#define DISCORD_USER_TEAM_PSEUDO_USER (1 << 10)
#define DISCORD_USER_BUG_HUNTER_LEVEL_2 (1 << 14)
#define DISCORD_USER_VERIFIED_BOT (1 << 16)
#define DISCORD_USER_VERIFIED_DEVELOPER (1 << 17)
#define DISCORD_USER_CERTIFIED_MODERATOR (1 << 18)
#define DISCORD_USER_BOT_HTTP_INTERACTIONS (1 << 19)

















#define DISCORD_VOICE_MICROPHONE (1 << 0)
#define DISCORD_VOICE_SOUNDSHARE (1 << 1)
#define DISCORD_VOICE_PRIORITY (1 << 2)
















#include "reflect-c.h"

#define _


 #define  REFLECTC_DEFINED__discord_application

 #define  REFLECTC_DEFINED__discord_install_params

 #define  REFLECTC_DEFINED__discord_application_command_types

 #define  REFLECTC_DEFINED__discord_application_command_option_types

 #define  REFLECTC_DEFINED__discord_application_command_permission_types

 #define  REFLECTC_DEFINED__discord_application_command

 #define  REFLECTC_DEFINED__discord_application_commands

 #define  REFLECTC_DEFINED__discord_application_command_option

 #define  REFLECTC_DEFINED__discord_application_command_options

 #define  REFLECTC_DEFINED__discord_application_command_option_choice

 #define  REFLECTC_DEFINED__discord_application_command_option_choices

 #define  REFLECTC_DEFINED__discord_application_command_interaction_data_option

 #define  REFLECTC_DEFINED__discord_application_command_interaction_data_options

 #define  REFLECTC_DEFINED__discord_guild_application_command_permission

 #define  REFLECTC_DEFINED__discord_guild_application_command_permissions

 #define  REFLECTC_DEFINED__discord_application_command_permission

 #define  REFLECTC_DEFINED__discord_application_command_permissions

 #define  REFLECTC_DEFINED__discord_create_global_application_command

 #define  REFLECTC_DEFINED__discord_edit_global_application_command

 #define  REFLECTC_DEFINED__discord_create_guild_application_command

 #define  REFLECTC_DEFINED__discord_edit_guild_application_command

 #define  REFLECTC_DEFINED__discord_bulk_overwrite_guild_application_command

 #define  REFLECTC_DEFINED__discord_bulk_overwrite_guild_application_commands

 #define  REFLECTC_DEFINED__discord_audit_log_events

 #define  REFLECTC_DEFINED__discord_audit_log

 #define  REFLECTC_DEFINED__discord_audit_log_entry

 #define  REFLECTC_DEFINED__discord_audit_log_entries

 #define  REFLECTC_DEFINED__discord_optional_audit_entry_info

 #define  REFLECTC_DEFINED__discord_optional_audit_entry_infos

 #define  REFLECTC_DEFINED__discord_audit_log_change

 #define  REFLECTC_DEFINED__discord_audit_log_changes

 #define  REFLECTC_DEFINED__discord_get_guild_audit_log

 #define  REFLECTC_DEFINED__discord_auto_moderation_trigger_types

 #define  REFLECTC_DEFINED__discord_auto_moderation_keyword_preset_types

 #define  REFLECTC_DEFINED__discord_auto_moderation_event_types

 #define  REFLECTC_DEFINED__discord_auto_moderation_action_types

 #define  REFLECTC_DEFINED__discord_auto_moderation_trigger_metadata

 #define  REFLECTC_DEFINED__discord_auto_moderation_action

 #define  REFLECTC_DEFINED__discord_auto_moderation_actions

 #define  REFLECTC_DEFINED__discord_auto_moderation_action_metadata

 #define  REFLECTC_DEFINED__discord_auto_moderation_rule

 #define  REFLECTC_DEFINED__discord_auto_moderation_rules

 #define  REFLECTC_DEFINED__discord_create_auto_moderation_rule

 #define  REFLECTC_DEFINED__discord_modify_auto_moderation_rule

 #define  REFLECTC_DEFINED__discord_delete_auto_moderation_rule

 #define  REFLECTC_DEFINED__discord_channel_types

 #define  REFLECTC_DEFINED__discord_video_quality_modes

 #define  REFLECTC_DEFINED__discord_sort_order_types

 #define  REFLECTC_DEFINED__discord_forum_layout_types

 #define  REFLECTC_DEFINED__discord_message_types

 #define  REFLECTC_DEFINED__discord_message_activity_types

 #define  REFLECTC_DEFINED__discord_channel

 #define  REFLECTC_DEFINED__discord_channels

 #define  REFLECTC_DEFINED__discord_message_activity

 #define  REFLECTC_DEFINED__discord_message_reference

 #define  REFLECTC_DEFINED__discord_message

 #define  REFLECTC_DEFINED__discord_messages

 #define  REFLECTC_DEFINED__discord_followed_channel

 #define  REFLECTC_DEFINED__discord_reaction_count_details

 #define  REFLECTC_DEFINED__discord_reaction

 #define  REFLECTC_DEFINED__discord_reactions

 #define  REFLECTC_DEFINED__discord_overwrite

 #define  REFLECTC_DEFINED__discord_overwrites

 #define  REFLECTC_DEFINED__discord_thread_metadata

 #define  REFLECTC_DEFINED__discord_thread_member

 #define  REFLECTC_DEFINED__discord_thread_members

 #define  REFLECTC_DEFINED__discord_thread_default_reaction

 #define  REFLECTC_DEFINED__discord_thread_tag

 #define  REFLECTC_DEFINED__discord_thread_tags

 #define  REFLECTC_DEFINED__discord_embed_thumbnail

 #define  REFLECTC_DEFINED__discord_embed_video

 #define  REFLECTC_DEFINED__discord_embed_image

 #define  REFLECTC_DEFINED__discord_embed_provider

 #define  REFLECTC_DEFINED__discord_embed_author

 #define  REFLECTC_DEFINED__discord_embed_footer

 #define  REFLECTC_DEFINED__discord_embed_field

 #define  REFLECTC_DEFINED__discord_embed_fields

 #define  REFLECTC_DEFINED__discord_embed

 #define  REFLECTC_DEFINED__discord_embeds

 #define  REFLECTC_DEFINED__discord_attachment

 #define  REFLECTC_DEFINED__discord_attachments

 #define  REFLECTC_DEFINED__discord_channel_mention

 #define  REFLECTC_DEFINED__discord_allowed_mention

 #define  REFLECTC_DEFINED__discord_role_subscription_data

 #define  REFLECTC_DEFINED__discord_thread_response_body

 #define  REFLECTC_DEFINED__discord_modify_channel

 #define  REFLECTC_DEFINED__discord_delete_channel

 #define  REFLECTC_DEFINED__discord_get_channel_messages

 #define  REFLECTC_DEFINED__discord_create_message

 #define  REFLECTC_DEFINED__discord_get_reactions

 #define  REFLECTC_DEFINED__discord_edit_message

 #define  REFLECTC_DEFINED__discord_delete_message

 #define  REFLECTC_DEFINED__discord_bulk_delete_messages

 #define  REFLECTC_DEFINED__discord_edit_channel_permissions

 #define  REFLECTC_DEFINED__discord_create_channel_invite

 #define  REFLECTC_DEFINED__discord_delete_channel_permission

 #define  REFLECTC_DEFINED__discord_follow_news_channel

 #define  REFLECTC_DEFINED__discord_pin_message

 #define  REFLECTC_DEFINED__discord_unpin_message

 #define  REFLECTC_DEFINED__discord_group_dm_add_recipient

 #define  REFLECTC_DEFINED__discord_start_thread_with_message

 #define  REFLECTC_DEFINED__discord_start_thread_without_message

 #define  REFLECTC_DEFINED__discord_list_active_threads

 #define  REFLECTC_DEFINED__strings

 #define  REFLECTC_DEFINED__json_values

 #define  REFLECTC_DEFINED__snowflakes

 #define  REFLECTC_DEFINED__bitmasks

 #define  REFLECTC_DEFINED__integers

 #define  REFLECTC_DEFINED__discord_emoji

 #define  REFLECTC_DEFINED__discord_emojis

 #define  REFLECTC_DEFINED__discord_create_guild_emoji

 #define  REFLECTC_DEFINED__discord_modify_guild_emoji

 #define  REFLECTC_DEFINED__discord_delete_guild_emoji

 #define  REFLECTC_DEFINED__discord_gateway_close_opcodes

 #define  REFLECTC_DEFINED__discord_gateway_opcodes

 #define  REFLECTC_DEFINED__discord_activity_types

 #define  REFLECTC_DEFINED__discord_activity

 #define  REFLECTC_DEFINED__discord_activities

 #define  REFLECTC_DEFINED__discord_activity_timestamps

 #define  REFLECTC_DEFINED__discord_activity_emoji

 #define  REFLECTC_DEFINED__discord_activity_party

 #define  REFLECTC_DEFINED__discord_activity_assets

 #define  REFLECTC_DEFINED__discord_activity_secrets

 #define  REFLECTC_DEFINED__discord_activity_button

 #define  REFLECTC_DEFINED__discord_activity_buttons

 #define  REFLECTC_DEFINED__discord_presence_update

 #define  REFLECTC_DEFINED__discord_client_status

 #define  REFLECTC_DEFINED__discord_presence_updates

 #define  REFLECTC_DEFINED__discord_identify

 #define  REFLECTC_DEFINED__discord_identify_connection

 #define  REFLECTC_DEFINED__discord_resume

 #define  REFLECTC_DEFINED__discord_request_guild_members

 #define  REFLECTC_DEFINED__discord_update_voice_state

 #define  REFLECTC_DEFINED__discord_ready

 #define  REFLECTC_DEFINED__discord_auto_moderation_action_execution

 #define  REFLECTC_DEFINED__discord_thread_list_sync

 #define  REFLECTC_DEFINED__discord_thread_members_update

 #define  REFLECTC_DEFINED__discord_channel_pins_update

 #define  REFLECTC_DEFINED__discord_guild_ban_add

 #define  REFLECTC_DEFINED__discord_guild_ban_remove

 #define  REFLECTC_DEFINED__discord_guild_emojis_update

 #define  REFLECTC_DEFINED__discord_guild_stickers_update

 #define  REFLECTC_DEFINED__discord_guild_integrations_update

 #define  REFLECTC_DEFINED__discord_guild_member_remove

 #define  REFLECTC_DEFINED__discord_guild_member_update

 #define  REFLECTC_DEFINED__discord_guild_members_chunk

 #define  REFLECTC_DEFINED__discord_guild_role_create

 #define  REFLECTC_DEFINED__discord_guild_role_update

 #define  REFLECTC_DEFINED__discord_guild_role_delete

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_user_add

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_user_remove

 #define  REFLECTC_DEFINED__discord_integration_delete

 #define  REFLECTC_DEFINED__discord_invite_create

 #define  REFLECTC_DEFINED__discord_invite_delete

 #define  REFLECTC_DEFINED__discord_message_delete

 #define  REFLECTC_DEFINED__discord_message_delete_bulk

 #define  REFLECTC_DEFINED__discord_message_reaction_add

 #define  REFLECTC_DEFINED__discord_message_reaction_remove

 #define  REFLECTC_DEFINED__discord_message_reaction_remove_all

 #define  REFLECTC_DEFINED__discord_message_reaction_remove_emoji

 #define  REFLECTC_DEFINED__discord_typing_start

 #define  REFLECTC_DEFINED__discord_voice_server_update

 #define  REFLECTC_DEFINED__discord_webhooks_update

 #define  REFLECTC_DEFINED__discord_session_start_limit

 #define  REFLECTC_DEFINED__discord_message_notification_level

 #define  REFLECTC_DEFINED__discord_explicit_content_filter_level

 #define  REFLECTC_DEFINED__discord_mfa_level

 #define  REFLECTC_DEFINED__discord_verification_level

 #define  REFLECTC_DEFINED__discord_guild_nsfw_level

 #define  REFLECTC_DEFINED__discord_premium_tier

 #define  REFLECTC_DEFINED__discord_integration_expire_behaviors

 #define  REFLECTC_DEFINED__discord_guild

 #define  REFLECTC_DEFINED__discord_guilds

 #define  REFLECTC_DEFINED__discord_guild_preview

 #define  REFLECTC_DEFINED__discord_guild_widget_settings

 #define  REFLECTC_DEFINED__discord_guild_widget

 #define  REFLECTC_DEFINED__discord_guild_member

 #define  REFLECTC_DEFINED__discord_guild_members

 #define  REFLECTC_DEFINED__discord_integration

 #define  REFLECTC_DEFINED__discord_integrations

 #define  REFLECTC_DEFINED__discord_integration_account

 #define  REFLECTC_DEFINED__discord_integration_application

 #define  REFLECTC_DEFINED__discord_ban

 #define  REFLECTC_DEFINED__discord_bans

 #define  REFLECTC_DEFINED__discord_welcome_screen

 #define  REFLECTC_DEFINED__discord_welcome_screen_channel

 #define  REFLECTC_DEFINED__discord_welcome_screen_channels

 #define  REFLECTC_DEFINED__discord_prune_count

 #define  REFLECTC_DEFINED__discord_create_guild

 #define  REFLECTC_DEFINED__discord_modify_guild

 #define  REFLECTC_DEFINED__discord_create_guild_channel

 #define  REFLECTC_DEFINED__discord_modify_guild_channel_position

 #define  REFLECTC_DEFINED__discord_modify_guild_channel_positions

 #define  REFLECTC_DEFINED__discord_list_active_guild_threads

 #define  REFLECTC_DEFINED__discord_list_guild_members

 #define  REFLECTC_DEFINED__discord_search_guild_members

 #define  REFLECTC_DEFINED__discord_add_guild_member

 #define  REFLECTC_DEFINED__discord_modify_guild_member

 #define  REFLECTC_DEFINED__discord_modify_current_member

 #define  REFLECTC_DEFINED__discord_modify_current_user_nick

 #define  REFLECTC_DEFINED__discord_add_guild_member_role

 #define  REFLECTC_DEFINED__discord_remove_guild_member_role

 #define  REFLECTC_DEFINED__discord_remove_guild_member

 #define  REFLECTC_DEFINED__discord_create_guild_ban

 #define  REFLECTC_DEFINED__discord_remove_guild_ban

 #define  REFLECTC_DEFINED__discord_create_guild_role

 #define  REFLECTC_DEFINED__discord_modify_guild_role_position

 #define  REFLECTC_DEFINED__discord_modify_guild_role_positions

 #define  REFLECTC_DEFINED__discord_modify_guild_role

 #define  REFLECTC_DEFINED__discord_delete_guild_role

 #define  REFLECTC_DEFINED__discord_get_guild_prune_count

 #define  REFLECTC_DEFINED__discord_begin_guild_prune

 #define  REFLECTC_DEFINED__discord_delete_guild_integrations

 #define  REFLECTC_DEFINED__discord_get_guild_widget_image

 #define  REFLECTC_DEFINED__discord_modify_guild_welcome_screen

 #define  REFLECTC_DEFINED__discord_modify_current_user_voice_state

 #define  REFLECTC_DEFINED__discord_modify_user_voice_state

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_privacy_level

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_entity_types

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_status

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_entity_metadata

 #define  REFLECTC_DEFINED__discord_guild_scheduled_events

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_user

 #define  REFLECTC_DEFINED__discord_guild_scheduled_event_users

 #define  REFLECTC_DEFINED__discord_list_guild_scheduled_events

 #define  REFLECTC_DEFINED__discord_create_guild_scheduled_event

 #define  REFLECTC_DEFINED__discord_get_guild_scheduled_event

 #define  REFLECTC_DEFINED__discord_modify_guild_scheduled_event

 #define  REFLECTC_DEFINED__discord_get_guild_scheduled_event_users

 #define  REFLECTC_DEFINED__discord_guild_template

 #define  REFLECTC_DEFINED__discord_guild_templates

 #define  REFLECTC_DEFINED__discord_create_guild_from_guild_template

 #define  REFLECTC_DEFINED__discord_create_guild_template

 #define  REFLECTC_DEFINED__discord_modify_guild_template

 #define  REFLECTC_DEFINED__discord_interaction_types

 #define  REFLECTC_DEFINED__discord_interaction_callback_types

 #define  REFLECTC_DEFINED__discord_interaction

 #define  REFLECTC_DEFINED__discord_interaction_data

 #define  REFLECTC_DEFINED__discord_resolved_data

 #define  REFLECTC_DEFINED__discord_message_interaction

 #define  REFLECTC_DEFINED__discord_interaction_response

 #define  REFLECTC_DEFINED__discord_interaction_callback_data

 #define  REFLECTC_DEFINED__discord_edit_original_interaction_response

 #define  REFLECTC_DEFINED__discord_create_followup_message

 #define  REFLECTC_DEFINED__discord_edit_followup_message

 #define  REFLECTC_DEFINED__discord_invite_target_types

 #define  REFLECTC_DEFINED__discord_invite

 #define  REFLECTC_DEFINED__discord_invites

 #define  REFLECTC_DEFINED__discord_invite_metadata

 #define  REFLECTC_DEFINED__discord_invite_stage_instance

 #define  REFLECTC_DEFINED__discord_get_invite

 #define  REFLECTC_DEFINED__discord_delete_invite

 #define  REFLECTC_DEFINED__discord_component_types

 #define  REFLECTC_DEFINED__discord_component_styles

 #define  REFLECTC_DEFINED__discord_component_spacing

 #define  REFLECTC_DEFINED__discord_component

 #define  REFLECTC_DEFINED__discord_components

 #define  REFLECTC_DEFINED__discord_select_option

 #define  REFLECTC_DEFINED__discord_select_options

 #define  REFLECTC_DEFINED__discord_component_media

 #define  REFLECTC_DEFINED__discord_component_item

 #define  REFLECTC_DEFINED__discord_component_items

 #define  REFLECTC_DEFINED__discord_auth_response

 #define  REFLECTC_DEFINED__discord_role

 #define  REFLECTC_DEFINED__discord_roles

 #define  REFLECTC_DEFINED__discord_role_tag

 #define  REFLECTC_DEFINED__discord_privacy_level

 #define  REFLECTC_DEFINED__discord_stage_instance

 #define  REFLECTC_DEFINED__discord_stage_instances

 #define  REFLECTC_DEFINED__discord_create_stage_instance

 #define  REFLECTC_DEFINED__discord_modify_stage_instance

 #define  REFLECTC_DEFINED__discord_delete_stage_instance

 #define  REFLECTC_DEFINED__discord_sticker_types

 #define  REFLECTC_DEFINED__discord_sticker_format_types

 #define  REFLECTC_DEFINED__discord_sticker

 #define  REFLECTC_DEFINED__discord_stickers

 #define  REFLECTC_DEFINED__discord_sticker_item

 #define  REFLECTC_DEFINED__discord_sticker_items

 #define  REFLECTC_DEFINED__discord_sticker_pack

 #define  REFLECTC_DEFINED__discord_sticker_packs

 #define  REFLECTC_DEFINED__discord_list_nitro_sticker_packs

 #define  REFLECTC_DEFINED__discord_create_guild_sticker

 #define  REFLECTC_DEFINED__discord_modify_guild_sticker

 #define  REFLECTC_DEFINED__discord_delete_guild_sticker

 #define  REFLECTC_DEFINED__discord_membership_state

 #define  REFLECTC_DEFINED__discord_team

 #define  REFLECTC_DEFINED__discord_team_member

 #define  REFLECTC_DEFINED__discord_team_members

 #define  REFLECTC_DEFINED__discord_premium_types

 #define  REFLECTC_DEFINED__discord_visibility_types

 #define  REFLECTC_DEFINED__discord_user

 #define  REFLECTC_DEFINED__discord_users

 #define  REFLECTC_DEFINED__discord_connection

 #define  REFLECTC_DEFINED__discord_connections

 #define  REFLECTC_DEFINED__discord_modify_current_user

 #define  REFLECTC_DEFINED__discord_get_current_user_guilds

 #define  REFLECTC_DEFINED__discord_create_dm

 #define  REFLECTC_DEFINED__discord_create_group_dm

 #define  REFLECTC_DEFINED__discord_voice_state

 #define  REFLECTC_DEFINED__discord_voice_states

 #define  REFLECTC_DEFINED__discord_voice_region

 #define  REFLECTC_DEFINED__discord_voice_regions

 #define  REFLECTC_DEFINED__discord_voice_close_opcodes

 #define  REFLECTC_DEFINED__discord_voice_opcodes

 #define  REFLECTC_DEFINED__discord_webhook_types

 #define  REFLECTC_DEFINED__discord_webhook

 #define  REFLECTC_DEFINED__discord_webhooks

 #define  REFLECTC_DEFINED__discord_create_webhook

 #define  REFLECTC_DEFINED__discord_modify_webhook

 #define  REFLECTC_DEFINED__discord_delete_webhook

 #define  REFLECTC_DEFINED__discord_modify_webhook_with_token

 #define  REFLECTC_DEFINED__discord_execute_webhook

 #define  REFLECTC_DEFINED__discord_get_webhook_message

 #define  REFLECTC_DEFINED__discord_edit_webhook_message

 #define  REFLECTC_DEFINED__discord_delete_webhook_message


enum discord_application_command_types { DISCORD_APPLICATION_CHAT_INPUT = 1, DISCORD_APPLICATION_USER = 2, DISCORD_APPLICATION_MESSAGE = 3, __discord_application_command_types_MAX__ };
enum discord_application_command_option_types { DISCORD_APPLICATION_OPTION_SUB_COMMAND = 1, DISCORD_APPLICATION_OPTION_SUB_COMMAND_GROUP = 2, DISCORD_APPLICATION_OPTION_STRING = 3, DISCORD_APPLICATION_OPTION_INTEGER = 4, DISCORD_APPLICATION_OPTION_BOOLEAN = 5, DISCORD_APPLICATION_OPTION_USER = 6, DISCORD_APPLICATION_OPTION_CHANNEL = 7, DISCORD_APPLICATION_OPTION_ROLE = 8, DISCORD_APPLICATION_OPTION_MENTIONABLE = 9, DISCORD_APPLICATION_OPTION_NUMBER = 10, DISCORD_APPLICATION_OPTION_ATTACHMENT = 11, __discord_application_command_option_types_MAX__ };
enum discord_application_command_permission_types { DISCORD_APPLICATION_PERMISSION_ROLE = 1, DISCORD_APPLICATION_PERMISSION_USER = 2, DISCORD_APPLICATION_PERMISSION_CHANNEL = 3, __discord_application_command_permission_types_MAX__ };


















enum discord_audit_log_events { DISCORD_AUDIT_LOG_GUILD_UPDATE = 1, DISCORD_AUDIT_LOG_CHANNEL_CREATE = 10, DISCORD_AUDIT_LOG_CHANNEL_UPDATE = 11, DISCORD_AUDIT_LOG_CHANNEL_DELETE = 12, DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_CREATE = 13, DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_UPDATE = 14, DISCORD_AUDIT_LOG_CHANNEL_OVERWRITE_DELETE = 15, DISCORD_AUDIT_LOG_MEMBER_KICK = 20, DISCORD_AUDIT_LOG_MEMBER_PRUNE = 21, DISCORD_AUDIT_LOG_MEMBER_BAN_ADD = 22, DISCORD_AUDIT_LOG_MEMBER_BAN_REMOVE = 23, DISCORD_AUDIT_LOG_MEMBER_UPDATE = 24, DISCORD_AUDIT_LOG_MEMBER_ROLE_UPDATE = 25, DISCORD_AUDIT_LOG_MEMBER_MOVE = 26, DISCORD_AUDIT_LOG_MEMBER_DISCONNECT = 27, DISCORD_AUDIT_LOG_BOT_ADD = 28, DISCORD_AUDIT_LOG_ROLE_CREATE = 30, DISCORD_AUDIT_LOG_ROLE_UPDATE = 31, DISCORD_AUDIT_LOG_ROLE_DELETE = 32, DISCORD_AUDIT_LOG_INVITE_CREATE = 40, DISCORD_AUDIT_LOG_INVITE_UPDATE = 41, DISCORD_AUDIT_LOG_INVITE_DELETE = 42, DISCORD_AUDIT_LOG_WEBHOOK_CREATE = 50, DISCORD_AUDIT_LOG_WEBHOOK_UPDATE = 51, DISCORD_AUDIT_LOG_WEBHOOK_DELETE = 52, DISCORD_AUDIT_LOG_EMOJI_CREATE = 60, DISCORD_AUDIT_LOG_EMOJI_UPDATE = 61, DISCORD_AUDIT_LOG_EMOJI_DELETE = 62, DISCORD_AUDIT_LOG_MESSAGE_DELETE = 72, DISCORD_AUDIT_LOG_MESSAGE_BULK_DELETE = 73, DISCORD_AUDIT_LOG_MESSAGE_PIN = 74, DISCORD_AUDIT_LOG_MESSAGE_UNPIN = 75, DISCORD_AUDIT_LOG_INTEGRATION_CREATE = 80, DISCORD_AUDIT_LOG_INTEGRATION_UPDATE = 81, DISCORD_AUDIT_LOG_INTEGRATION_DELETE = 82, DISCORD_AUDIT_LOG_STAGE_INSTANCE_CREATE = 83, DISCORD_AUDIT_LOG_STAGE_INSTANCE_UPDATE = 84, DISCORD_AUDIT_LOG_STAGE_INSTANCE_DELETE = 85, DISCORD_AUDIT_LOG_STICKER_CREATE = 90, DISCORD_AUDIT_LOG_STICKER_UPDATE = 91, DISCORD_AUDIT_LOG_STICKER_DELETE = 92, DISCORD_AUDIT_LOG_GUILD_SCHEDULED_EVENT_CREATE = 100, DISCORD_AUDIT_LOG_GUILD_SCHEDULED_EVENT_UPDATE = 101, DISCORD_AUDIT_LOG_GUILD_SCHEDULED_EVENT_DELETE = 102, DISCORD_AUDIT_LOG_THREAD_CREATE = 110, DISCORD_AUDIT_LOG_THREAD_UPDATE = 111, DISCORD_AUDIT_LOG_THREAD_DELETE = 112, DISCORD_AUDIT_LOG_APPLICATION_COMMAND_PERMISSION_UPDATE = 121, DISCORD_AUDIT_LOG_AUTO_MODERATION_RULE_CREATE = 140, DISCORD_AUDIT_LOG_AUTO_MODERATION_RULE_UPDATE = 141, DISCORD_AUDIT_LOG_AUTO_MODERATION_RULE_DELETE = 142, DISCORD_AUDIT_LOG_AUTO_MODERATION_BLOCK_MESSAGE = 143, __discord_audit_log_events_MAX__ };








enum discord_auto_moderation_trigger_types { DISCORD_AUTO_MODERATION_KEYWORD = 1, DISCORD_AUTO_MODERATION_HARMFUL_LINK = 2, DISCORD_AUTO_MODERATION_SPAM = 3, DISCORD_AUTO_MODERATION_KEYWORD_PRESET = 4, __discord_auto_moderation_trigger_types_MAX__ };
enum discord_auto_moderation_keyword_preset_types { DISCORD_AUTO_MODERATION_PROFANITY = 1, DISCORD_AUTO_MODERATION_SEXUAL_CONTENT = 2, DISCORD_AUTO_MODERATION_SLURS = 3, __discord_auto_moderation_keyword_preset_types_MAX__ };
enum discord_auto_moderation_event_types { DISCORD_AUTO_MODERATION_MESSAGE_SEND = 1, __discord_auto_moderation_event_types_MAX__ };
enum discord_auto_moderation_action_types { DISCORD_AUTO_MODERATION_ACTION_BLOCK_MESSAGE = 1, DISCORD_AUTO_MODERATION_ACTION_SEND_ALERT_MESSAGE = 2, DISCORD_AUTO_MODERATION_ACTION_TIMEOUT = 3, __discord_auto_moderation_action_types_MAX__ };









enum discord_channel_types { DISCORD_CHANNEL_GUILD_TEXT = 0, DISCORD_CHANNEL_DM = 1, DISCORD_CHANNEL_GUILD_VOICE = 2, DISCORD_CHANNEL_GROUP_DM = 3, DISCORD_CHANNEL_GUILD_CATEGORY = 4, DISCORD_CHANNEL_GUILD_ANNOUNCEMENT = 5, DISCORD_CHANNEL_GUILD_NEWS = DISCORD_CHANNEL_GUILD_ANNOUNCEMENT, DISCORD_CHANNEL_GUILD_STORE = 6, DISCORD_CHANNEL_ANNOUNCEMENT_THREAD = 10, DISCORD_CHANNEL_GUILD_NEWS_THREAD = DISCORD_CHANNEL_ANNOUNCEMENT_THREAD, DISCORD_CHANNEL_GUILD_PUBLIC_THREAD = 11, DISCORD_CHANNEL_GUILD_PRIVATE_THREAD = 12, DISCORD_CHANNEL_GUILD_STAGE_VOICE = 13, DISCORD_CHANNEL_GUILD_DIRECTORY = 14, DISCORD_CHANNEL_GUILD_FORUM = 15, DISCORD_CHANNEL_GUILD_MEDIA = 16, __discord_channel_types_MAX__ };
enum discord_video_quality_modes { DISCORD_VIDEO_QUALITY_AUTO = 1, DISCORD_VIDEO_QUALITY_FULL = 2, __discord_video_quality_modes_MAX__ };
enum discord_sort_order_types { DISCORD_SORT_ORDER_LATEST_ACTIVITY = 0, DISCORD_SORT_ORDER_CREATION_DATE = 1, __discord_sort_order_types_MAX__ };
enum discord_forum_layout_types { DISCORD_FORUM_LAYOUT_NOT_SET = 0, DISCORD_FORUM_LAYOUT_LIST_VIEW = 1, DISCORD_FORUM_LAYOUT_GALLERY_VIEW = 1, __discord_forum_layout_types_MAX__ };
enum discord_message_types { DISCORD_MESSAGE_DEFAULT = 0, DISCORD_MESSAGE_RECIPIENT_ADD = 1, DISCORD_MESSAGE_RECIPIENT_REMOVE = 2, DISCORD_MESSAGE_CALL = 3, DISCORD_MESSAGE_CHANNEL_NAME_CHANGE = 4, DISCORD_MESSAGE_CHANNEL_ICON_CHANGE = 5, DISCORD_MESSAGE_CHANNEL_PINNED_MESSAGE = 6, DISCORD_MESSAGE_GUILD_MEMBER_JOIN = 7, DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION = 8, DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 = 9, DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 = 10, DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 = 11, DISCORD_MESSAGE_CHANNEL_FOLLOW_ADD = 12, DISCORD_MESSAGE_GUILD_DISCOVERY_DISQUALIFIED = 14, DISCORD_MESSAGE_GUILD_DISCOVERY_REQUALIFIED = 15, DISCORD_MESSAGE_GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING = 16, DISCORD_MESSAGE_GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING = 17, DISCORD_MESSAGE_THREAD_CREATED = 18, DISCORD_MESSAGE_REPLY = 19, DISCORD_MESSAGE_CHAT_INPUT_COMMAND = 20, DISCORD_MESSAGE_THREAD_STARTER_MESSAGE = 21, DISCORD_MESSAGE_GUILD_INVITE_REMINDER = 22, DISCORD_MESSAGE_CONTEXT_MENU_COMMAND = 23, DISCORD_MESSAGE_AUTO_MODERATION_ACTION = 24, DISCORD_MESSAGE_ROLE_SUBSCRIPTION_PURCHASE = 25, DISCORD_MESSAGE_INTERACTION_PREMIUM_UPSELL = 26, DISCORD_MESSAGE_STAGE_START = 27, DISCORD_MESSAGE_STAGE_END = 28, DISCORD_MESSAGE_STAGE_SPEAKER = 29, DISCORD_MESSAGE_STAGE_TOPIC = 31, DISCORD_MESSAGE_GUILD_APPLICATION_PREMIUM_SUBSCRIPTION = 32, __discord_message_types_MAX__ };
enum discord_message_activity_types { DISCORD_MESSAGE_ACTIVITY_JOIN = 1, DISCORD_MESSAGE_ACTIVITY_SPECTATE = 2, DISCORD_MESSAGE_ACTIVITY_LISTEN = 3, DISCORD_MESSAGE_ACTIVITY_JOIN_REQUEST = 5, __discord_message_activity_types_MAX__ };






























































enum discord_gateway_close_opcodes { DISCORD_GATEWAY_CLOSE_REASON_UNKNOWN_ERROR = 4000, DISCORD_GATEWAY_CLOSE_REASON_UNKNOWN_OPCODE = 4001, DISCORD_GATEWAY_CLOSE_REASON_DECODE_ERROR = 4002, DISCORD_GATEWAY_CLOSE_REASON_NOT_AUTHENTICATED = 4003, DISCORD_GATEWAY_CLOSE_REASON_AUTHENTICATION_FAILED = 4004, DISCORD_GATEWAY_CLOSE_REASON_ALREADY_AUTHENTICATED = 4005, DISCORD_GATEWAY_CLOSE_REASON_INVALID_SEQUENCE = 4007, DISCORD_GATEWAY_CLOSE_REASON_RATE_LIMITED = 4008, DISCORD_GATEWAY_CLOSE_REASON_SESSION_TIMED_OUT = 4009, DISCORD_GATEWAY_CLOSE_REASON_INVALID_SHARD = 4010, DISCORD_GATEWAY_CLOSE_REASON_SHARDING_REQUIRED = 4011, DISCORD_GATEWAY_CLOSE_REASON_INVALID_API_VERSION = 4012, DISCORD_GATEWAY_CLOSE_REASON_INVALID_INTENTS = 4013, DISCORD_GATEWAY_CLOSE_REASON_DISALLOWED_INTENTS = 4014, DISCORD_GATEWAY_CLOSE_REASON_RECONNECT = 4900, __discord_gateway_close_opcodes_MAX__ };
enum discord_gateway_opcodes { DISCORD_GATEWAY_DISPATCH = 0, DISCORD_GATEWAY_HEARTBEAT = 1, DISCORD_GATEWAY_IDENTIFY = 2, DISCORD_GATEWAY_PRESENCE_UPDATE = 3, DISCORD_GATEWAY_VOICE_STATE_UPDATE = 4, DISCORD_GATEWAY_RESUME = 6, DISCORD_GATEWAY_RECONNECT = 7, DISCORD_GATEWAY_REQUEST_GUILD_MEMBERS = 8, DISCORD_GATEWAY_INVALID_SESSION = 9, DISCORD_GATEWAY_HELLO = 10, DISCORD_GATEWAY_HEARTBEAT_ACK = 11, __discord_gateway_opcodes_MAX__ };
enum discord_activity_types { DISCORD_ACTIVITY_GAME = 0, DISCORD_ACTIVITY_STREAMING = 1, DISCORD_ACTIVITY_LISTENING = 2, DISCORD_ACTIVITY_WATCHING = 3, DISCORD_ACTIVITY_CUSTOM = 4, DISCORD_ACTIVITY_COMPETING = 5, __discord_activity_types_MAX__ };
















































enum discord_message_notification_level { DISCORD_MESSAGE_NOTIFICATION_ALL_MESSAGES = 0, DISCORD_MESSAGE_NOTIFICATION_ONLY_MESSAGES = 1, __discord_message_notification_level_MAX__ };
enum discord_explicit_content_filter_level { DISCORD_EXPLICIT_CONTENT_DISABLED = 0, DISCORD_EXPLICIT_CONTENT_MEMBERS_WITHOUT_ROLES = 1, DISCORD_MESSAGE_NOTIFICATION_ALL_MEMBERS = 2, __discord_explicit_content_filter_level_MAX__ };
enum discord_mfa_level { DISCORD_MFA_NONE = 0, DISCORD_MFA_ELEVATED = 1, __discord_mfa_level_MAX__ };
enum discord_verification_level { DISCORD_VERIFICATION_NONE = 0, DISCORD_VERIFICATION_LOW = 1, DISCORD_VERIFICATION_MEDIUM = 2, DISCORD_VERIFICATION_HIGH = 3, DISCORD_VERIFICATION_VERY_HIGH = 4, __discord_verification_level_MAX__ };
enum discord_guild_nsfw_level { DISCORD_GUILD_NSFW_DEFAULT = 0, DISCORD_GUILD_NSFW_EXPLICIT = 1, DISCORD_GUILD_NSFW_SAFE = 2, DISCORD_GUILD_NSFW_AGE_RESTRICTED = 3, __discord_guild_nsfw_level_MAX__ };
enum discord_premium_tier { DISCORD_PREMIUM_TIER_NONE = 0, DISCORD_PREMIUM_TIER_1 = 1, DISCORD_PREMIUM_TIER_2 = 2, DISCORD_PREMIUM_TIER_3 = 3, __discord_premium_tier_MAX__ };
enum discord_integration_expire_behaviors { DISCORD_INTEGRATION_REMOVE_ROLE = 0, DISCORD_INTEGRATION_KICK = 1, __discord_integration_expire_behaviors_MAX__ };














































enum discord_guild_scheduled_event_privacy_level { DISCORD_GUILD_SCHEDULED_EVENT_GUILD_ONLY = 2, __discord_guild_scheduled_event_privacy_level_MAX__ };
enum discord_guild_scheduled_event_entity_types { DISCORD_GUILD_SCHEDULED_EVENT_ENTITY_STAGE_INSTANCE = 1, DISCORD_GUILD_SCHEDULED_EVENT_ENTITY_VOICE = 2, DISCORD_GUILD_SCHEDULED_EVENT_ENTITY_EXTERNAL = 3, __discord_guild_scheduled_event_entity_types_MAX__ };
enum discord_guild_scheduled_event_status { DISCORD_GUILD_SCHEDULED_EVENT_SCHEDULED = 1, DISCORD_GUILD_SCHEDULED_EVENT_ACTIVE = 2, DISCORD_GUILD_SCHEDULED_EVENT_COMPLETED = 3, DISCORD_GUILD_SCHEDULED_EVENT_CANCELED = 4, __discord_guild_scheduled_event_status_MAX__ };















enum discord_interaction_types { DISCORD_INTERACTION_PING = 1, DISCORD_INTERACTION_APPLICATION_COMMAND = 2, DISCORD_INTERACTION_MESSAGE_COMPONENT = 3, DISCORD_INTERACTION_APPLICATION_COMMAND_AUTOCOMPLETE = 4, DISCORD_INTERACTION_MODAL_SUBMIT = 5, __discord_interaction_types_MAX__ };
enum discord_interaction_callback_types { DISCORD_INTERACTION_PONG = 1, DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE = 4, DISCORD_INTERACTION_DEFERRED_CHANNEL_MESSAGE_WITH_SOURCE = 5, DISCORD_INTERACTION_DEFERRED_UPDATE_MESSAGE = 6, DISCORD_INTERACTION_UPDATE_MESSAGE = 7, DISCORD_INTERACTION_APPLICATION_COMMAND_AUTOCOMPLETE_RESULT = 8, DISCORD_INTERACTION_MODAL = 9, __discord_interaction_callback_types_MAX__ };









enum discord_invite_target_types { DISCORD_INVITE_TARGET_STREAM = 1, DISCORD_INVITE_TARGET_EMBEDDED_APPLICATION = 2, __discord_invite_target_types_MAX__ };






enum discord_component_types { DISCORD_COMPONENT_ACTION_ROW = 1, DISCORD_COMPONENT_BUTTON = 2, DISCORD_COMPONENT_SELECT_MENU = 3, DISCORD_COMPONENT_TEXT_INPUT = 4, DISCORD_COMPONENT_USER_SELECT = 5, DISCORD_COMPONENT_ROLE_SELECT = 6, DISCORD_COMPONENT_MENTION_SELECT = 7, DISCORD_COMPONENT_CHANNEL_SELECT = 8, DISCORD_COMPONENT_SECTION = 9, DISCORD_COMPONENT_TEXT_DISPLAY = 10, DISCORD_COMPONENT_THUMBNAIL = 11, DISCORD_COMPONENT_MEDIA_GALLERY = 12, DISCORD_COMPONENT_FILE = 13, DISCORD_COMPONENT_SEPARATOR = 14, DISCORD_COMPONENT_CONTENT_INVENTORY_ENTRY = 16, DISCORD_COMPONENT_CONTAINER = 17, __discord_component_types_MAX__ };
enum discord_component_styles { DISCORD_BUTTON_PRIMARY = 1, DISCORD_BUTTON_SECONDARY = 2, DISCORD_BUTTON_SUCCESS = 3, DISCORD_BUTTON_DANGER = 4, DISCORD_BUTTON_LINK = 5, DISCORD_TEXT_SHORT = 1, DISCORD_TEXT_PARAGRAPH = 2, __discord_component_styles_MAX__ };
enum discord_component_spacing { DISCORD_COMPONENT_SPACING_SMALL = 1, DISCORD_COMPONENT_SPACING_LARGE = 2, __discord_component_spacing_MAX__ };











enum discord_privacy_level { DISCORD_PRIVACY_PUBLIC = 1, DISCORD_PRIVACY_GUILD_ONLY = 2, __discord_privacy_level_MAX__ };





enum discord_sticker_types { DISCORD_STICKER_STANDARD = 1, DISCORD_STICKER_GUILD = 2, __discord_sticker_types_MAX__ };
enum discord_sticker_format_types { DISCORD_STICKER_FORMAT_PNG = 1, DISCORD_STICKER_FORMAT_APNG = 2, DISCORD_STICKER_FORMAT_LOTTIE = 3, __discord_sticker_format_types_MAX__ };










enum discord_membership_state { DISCORD_MEMBERSHIP_INVITED = 1, DISCORD_MEMBERSHIP_ACCEPTED = 2, __discord_membership_state_MAX__ };



enum discord_premium_types { DISCORD_PREMIUM_NONE = 0, DISCORD_PREMIUM_NITRO_CLASSIC = 1, DISCORD_PREMIUM_NITRO = 2, __discord_premium_types_MAX__ };
enum discord_visibility_types { DISCORD_VISIBILITY_NONE = 0, DISCORD_VISIBILITY_EVERYONE = 1, __discord_visibility_types_MAX__ };












enum discord_voice_close_opcodes { DISCORD_VOICE_CLOSE_REASON_UNKNOWN_OPCODE = 4001, DISCORD_VOICE_CLOSE_REASON_DECODE_ERROR = 4002, DISCORD_VOICE_CLOSE_REASON_NOT_AUTHENTICATED = 4003, DISCORD_VOICE_CLOSE_REASON_AUTHENTICATION_FAILED = 4004, DISCORD_VOICE_CLOSE_REASON_ALREADY_AUTHENTICATED = 4005, DISCORD_VOICE_CLOSE_REASON_INVALID_SESSION = 4006, DISCORD_VOICE_CLOSE_REASON_SESSION_TIMED_OUT = 4009, DISCORD_VOICE_CLOSE_REASON_SERVER_NOT_FOUND = 4011, DISCORD_VOICE_CLOSE_REASON_UNKNOWN_PROTOCOL = 4012, DISCORD_VOICE_CLOSE_REASON_DISCONNECTED = 4014, DISCORD_VOICE_CLOSE_REASON_SERVER_CRASH = 4015, DISCORD_VOICE_CLOSE_REASON_UNKNOWN_ENCRYPTION_MODE = 4016, __discord_voice_close_opcodes_MAX__ };
enum discord_voice_opcodes { DISCORD_VOICE_IDENTIFY = 0, DISCORD_VOICE_SELECT_PROTOCOL = 1, DISCORD_VOICE_READY = 2, DISCORD_VOICE_HEARTBEAT = 3, DISCORD_VOICE_SESSION_DESCRIPTION = 4, DISCORD_VOICE_SPEAKING = 5, DISCORD_VOICE_HEARTBEAT_ACK = 6, DISCORD_VOICE_RESUME = 7, DISCORD_VOICE_HELLO = 8, DISCORD_VOICE_RESUMED = 9, DISCORD_VOICE_CLIENT_DISCONNECT = 13, DISCORD_VOICE_CODEC = 14, __discord_voice_opcodes_MAX__ };
enum discord_webhook_types { DISCORD_WEBHOOK_INCOMING = 1, DISCORD_WEBHOOK_CHANNEL_FOLLOWER = 2, DISCORD_WEBHOOK_APPLICATION = 3, __discord_webhook_types_MAX__ };










struct discord_application { _ _ u64snowflake _ id _; _ _ char * name _; _ _ char * icon _; _ _ char * description _; _ struct strings * rpc_origins _; _ _ bool _ bot_public _; _ _ bool _ bot_require_code_grant _; _ _ char * terms_of_service_url _; _ _ char * privacy_policy_url _; _ struct discord_user * owner _; _ _ char * summary _; _ _ char * verify_key _; _ struct discord_team * team _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ primary_sku_id _; _ _ char * slug _; _ _ char * cover_image _; _ _ u64bitmask _ flags _; };
struct discord_install_params { _ struct strings * scopes _; _ _ u64bitmask _ permissions _; };



struct discord_application_command { _ _ u64snowflake _ id _; _ enum discord_application_command_types _ type _; _ _ u64snowflake _ application_id _; _ _ u64snowflake _ guild_id _; _ _ char * name _; _ _ char * description _; _ struct discord_application_command_options * options _; _ _ u64bitmask _ default_member_permissions _; _ _ bool _ dm_permission _; _ _ bool _ default_permission _; _ _ u64snowflake _ version _; };
struct discord_application_commands { _ _ int _ size _; _ struct discord_application_command * array _; _ _ int _ realsize _; };
struct discord_application_command_option { _ enum discord_application_command_option_types _ type _; _ _ char * name _; _ _ char * description _; _ _ bool _ required _; _ struct discord_application_command_option_choices * choices _; _ struct discord_application_command_options * options _; _ struct integers * channel_types _; _ _ char * min_value _; _ _ char * max_value _; _ _ bool _ autocomplete _; };
struct discord_application_command_options { _ _ int _ size _; _ struct discord_application_command_option * array _; _ _ int _ realsize _; };
struct discord_application_command_option_choice { _ _ char * name _; _ _ json_char * value _; };
struct discord_application_command_option_choices { _ _ int _ size _; _ struct discord_application_command_option_choice * array _; _ _ int _ realsize _; };
struct discord_application_command_interaction_data_option { _ _ char * name _; _ enum discord_application_command_option_types _ type _; _ _ json_char * value _; _ struct discord_application_command_interaction_data_options * options _; _ _ bool _ focused _; };
struct discord_application_command_interaction_data_options { _ _ int _ size _; _ struct discord_application_command_interaction_data_option * array _; _ _ int _ realsize _; };
struct discord_guild_application_command_permission { _ _ u64snowflake _ id _; _ _ u64snowflake _ application_id _; _ _ u64snowflake _ guild_id _; _ struct discord_application_command_permissions * permissions _; };
struct discord_guild_application_command_permissions { _ _ int _ size _; _ struct discord_guild_application_command_permission * array _; _ _ int _ realsize _; };
struct discord_application_command_permission { _ _ u64snowflake _ id _; _ enum discord_application_command_permission_types _ type _; _ _ bool _ permission _; };
struct discord_application_command_permissions { _ _ int _ size _; _ struct discord_application_command_permission * array _; _ _ int _ realsize _; };
struct discord_create_global_application_command { _ _ char * name _; _ _ char * description _; _ struct discord_application_command_options * options _; _ _ u64bitmask _ default_member_permissions _; _ _ bool _ dm_permission _; _ _ bool _ default_permission _; _ enum discord_application_command_types _ type _; };
struct discord_edit_global_application_command { _ _ char * name _; _ _ char * description _; _ struct discord_application_command_options * options _; _ _ u64bitmask _ default_member_permissions _; _ _ bool _ dm_permission _; _ _ bool _ default_permission _; };
struct discord_create_guild_application_command { _ _ char * name _; _ _ char * description _; _ struct discord_application_command_options * options _; _ _ u64bitmask _ default_member_permissions _; _ _ bool _ dm_permission _; _ _ bool _ default_permission _; _ enum discord_application_command_types _ type _; };
struct discord_edit_guild_application_command { _ _ char * name _; _ _ char * description _; _ struct discord_application_command_options * options _; _ _ u64bitmask _ default_member_permissions _; _ _ bool _ default_permission _; };
struct discord_bulk_overwrite_guild_application_command { _ _ u64snowflake _ id _; _ _ char * name _; _ struct strings * name_localizations _; _ _ char * description _; _ struct strings * description_localizations _; _ struct discord_application_command_options * options _; _ _ u64bitmask _ default_member_permissions _; _ _ bool _ dm_permission _; _ enum discord_application_command_types _ type _; };
struct discord_bulk_overwrite_guild_application_commands { _ _ int _ size _; _ struct discord_bulk_overwrite_guild_application_command * array _; _ _ int _ realsize _; };

struct discord_audit_log { _ struct discord_audit_log_entries * audit_log_entries _; _ struct discord_guild_scheduled_events * guild_scheduled_events _; _ struct discord_integrations * integrations _; _ struct discord_channels * threads _; _ struct discord_users * users _; _ struct discord_webhooks * webhooks _; };
struct discord_audit_log_entry { _ _ u64snowflake _ target_id _; _ struct discord_audit_log_changes * changes _; _ _ u64snowflake _ user_id _; _ _ u64snowflake _ id _; _ enum discord_audit_log_events _ action_type _; _ struct discord_optional_audit_entry_infos * options _; _ _ char * reason _; };
struct discord_audit_log_entries { _ _ int _ size _; _ struct discord_audit_log_entry * array _; _ _ int _ realsize _; };
struct discord_optional_audit_entry_info { _ _ u64snowflake _ channel_id _; _ _ char * count _; _ _ char * delete_member_days _; _ _ u64snowflake _ id _; _ _ char * members_removed _; _ _ u64snowflake _ message_id _; _ _ char * role_name _; _ _ char * type _; };
struct discord_optional_audit_entry_infos { _ _ int _ size _; _ struct discord_optional_audit_entry_info * array _; _ _ int _ realsize _; };
struct discord_audit_log_change { _ _ json_char * new_value _; _ _ json_char * old_value _; _ _ char * key _; };
struct discord_audit_log_changes { _ _ int _ size _; _ struct discord_audit_log_change * array _; _ _ int _ realsize _; };
struct discord_get_guild_audit_log { _ _ u64snowflake _ user_id _; _ _ int _ action_type _; _ _ u64snowflake _ before _; _ _ int _ limit _; };




struct discord_auto_moderation_trigger_metadata { _ struct strings * keyword_filter _; _ struct integers * presets _; };
struct discord_auto_moderation_action { _ enum discord_auto_moderation_action_types _ type _; _ struct discord_auto_moderation_action_metadata * metadata _; };
struct discord_auto_moderation_actions { _ _ int _ size _; _ struct discord_auto_moderation_action * array _; _ _ int _ realsize _; };
struct discord_auto_moderation_action_metadata { _ _ u64snowflake _ channel_id _; _ _ int _ duration_seconds _; };
struct discord_auto_moderation_rule { _ _ u64snowflake _ id _; _ _ u64snowflake _ guild_id _; _ _ char * name _; _ _ u64snowflake _ creator_id _; _ enum discord_auto_moderation_event_types _ event_type _; _ enum discord_auto_moderation_trigger_types _ trigger_type _; _ struct discord_auto_moderation_actions * actions _; _ struct discord_auto_moderation_trigger_metadata * trigger_metadata _; _ _ bool _ enabled _; _ struct snowflakes * exempt_roles _; _ struct snowflakes * exempt_channels _; };
struct discord_auto_moderation_rules { _ _ int _ size _; _ struct discord_auto_moderation_rule * array _; _ _ int _ realsize _; };
struct discord_create_auto_moderation_rule { _ _ char * reason _; _ _ char * name _; _ enum discord_auto_moderation_event_types _ event_type _; _ enum discord_auto_moderation_trigger_types _ trigger_type _; _ struct discord_auto_moderation_actions * actions _; _ struct discord_auto_moderation_trigger_metadata * trigger_metadata _; _ _ bool _ enabled _; _ struct snowflakes * exempt_roles _; _ struct snowflakes * exempt_channels _; };
struct discord_modify_auto_moderation_rule { _ _ char * reason _; _ _ char * name _; _ enum discord_auto_moderation_event_types _ event_type _; _ struct discord_auto_moderation_trigger_metadata * trigger_metadata _; _ struct discord_auto_moderation_actions * actions _; _ _ bool _ enabled _; _ struct snowflakes * exempt_roles _; _ struct snowflakes * exempt_channels _; };
struct discord_delete_auto_moderation_rule { _ _ char * reason _; };






struct discord_channel { _ _ u64snowflake _ id _; _ enum discord_channel_types _ type _; _ _ u64snowflake _ guild_id _; _ _ int _ position _; _ struct discord_overwrites * permission_overwrites _; _ _ char * name _; _ _ char * topic _; _ _ bool _ nsfw _; _ _ u64snowflake _ last_message_id _; _ _ int _ bitrate _; _ _ int _ user_limit _; _ _ int _ rate_limit_per_user _; _ struct discord_users * recipients _; _ _ char * icon _; _ _ u64snowflake _ owner_id _; _ _ u64snowflake _ application_id _; _ _ bool _ managed _; _ _ u64snowflake _ parent_id _; _ _ u64unix_ms _ last_pin_timestamp _; _ _ char * rtc_region _; _ _ int _ voice_quality_mode _; _ _ int _ message_count _; _ _ int _ member_count _; _ struct discord_thread_metadata * thread_metadata _; _ struct discord_thread_member * member _; _ _ int _ default_auto_archive_duration _; _ _ u64bitmask _ permissions _; _ _ u64bitmask _ flags _; _ _ int _ total_message_sent _; _ struct discord_thread_tags * available_tags _; _ struct snowflakes * applied_tags _; _ struct discord_thread_default_reaction * default_reaction_emoji _; _ _ int _ default_thread_rate_limit_per_user _; _ enum discord_sort_order_types _ default_sort_order _; _ enum discord_forum_layout_types _ default_forum_layout _; };
struct discord_channels { _ _ int _ size _; _ struct discord_channel * array _; _ _ int _ realsize _; };
struct discord_message_activity { _ enum discord_message_activity_types _ type _; _ _ char * party_id _; };
struct discord_message_reference { _ _ u64snowflake _ message_id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ guild_id _; _ _ bool _ fail_if_not_exists _; };
struct discord_message { _ _ u64snowflake _ id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ guild_id _; _ struct discord_user * author _; _ struct discord_guild_member * member _; _ _ char * content _; _ _ u64unix_ms _ timestamp _; _ _ u64unix_ms _ edited_timestamp _; _ _ bool _ tts _; _ _ bool _ mention_everyone _; _ struct discord_users * mentions _; _ struct snowflakes * mention_roles _; _ struct discord_channels * mention_channels _; _ struct discord_attachments * attachments _; _ struct discord_embeds * embeds _; _ struct discord_reactions * reactions _; _ _ json_char * nonce _; _ _ bool _ pinned _; _ _ u64snowflake _ webhook_id _; _ enum discord_message_types _ type _; _ struct discord_message_activity * activity _; _ struct discord_application * application _; _ _ u64snowflake _ application_id _; _ struct discord_message_reference * message_reference _; _ _ u64bitmask _ flags _; _ struct discord_message * referenced_message _; _ struct discord_message_interaction * interaction _; _ struct discord_channel * thread _; _ struct discord_components * components _; _ struct discord_sticker_items * sticker_items _; _ struct discord_stickers * stickers _; _ _ int _ position _; _ struct discord_role_subscription_data * role_subscription_data _; _ struct discord_resolved_data * resolved _; };
struct discord_messages { _ _ int _ size _; _ struct discord_message * array _; _ _ int _ realsize _; };
struct discord_followed_channel { _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ webhook_id _; };
struct discord_reaction_count_details { _ _ int _ burst _; _ _ int _ normal _; };
struct discord_reaction { _ _ int _ count _; _ struct discord_reaction_count_details * count_details _; _ _ bool _ me _; _ _ bool _ me_burst _; _ struct discord_emoji * emoji _; _ _ char * burst_colors _; };
struct discord_reactions { _ _ int _ size _; _ struct discord_reaction * array _; _ _ int _ realsize _; };
struct discord_overwrite { _ _ u64snowflake _ id _; _ _ int _ type _; _ _ u64bitmask _ allow _; _ _ u64bitmask _ deny _; };
struct discord_overwrites { _ _ int _ size _; _ struct discord_overwrite * array _; _ _ int _ realsize _; };
struct discord_thread_metadata { _ _ bool _ archived _; _ _ int _ auto_archive_duration _; _ _ u64unix_ms _ archive_timestamp _; _ _ bool _ locked _; _ _ bool _ invitable _; _ _ u64unix_ms _ create_timestamp _; };
struct discord_thread_member { _ _ u64snowflake _ id _; _ _ u64snowflake _ user_id _; _ _ u64unix_ms _ join_timestamp _; _ _ u64bitmask _ flags _; _ struct discord_guild_member * member _; _ _ u64snowflake _ guild_id _; };
struct discord_thread_members { _ _ int _ size _; _ struct discord_thread_member * array _; _ _ int _ realsize _; };
struct discord_thread_default_reaction { _ _ u64snowflake _ emoji_id _; _ _ char * emoji_name _; };
struct discord_thread_tag { _ _ u64snowflake _ id _; _ _ char * name _; _ _ bool _ moderated _; _ _ u64snowflake _ emoji_id _; _ _ char * emoji_name _; };
struct discord_thread_tags { _ _ int _ size _; _ struct discord_thread_tag * array _; _ _ int _ realsize _; };
struct discord_embed_thumbnail { _ _ char * url _; _ _ char * proxy_url _; _ _ int _ height _; _ _ int _ width _; };
struct discord_embed_video { _ _ char * url _; _ _ char * proxy_url _; _ _ int _ height _; _ _ int _ width _; };
struct discord_embed_image { _ _ char * url _; _ _ char * proxy_url _; _ _ int _ height _; _ _ int _ width _; };
struct discord_embed_provider { _ _ char * name _; _ _ char * url _; };
struct discord_embed_author { _ _ char * name _; _ _ char * url _; _ _ char * icon_url _; _ _ char * proxy_icon_url _; };
struct discord_embed_footer { _ _ char * text _; _ _ char * icon_url _; _ _ char * proxy_icon_url _; };
struct discord_embed_field { _ _ char * name _; _ _ char * value _; _ _ bool _ Inline _; };
struct discord_embed_fields { _ _ int _ size _; _ struct discord_embed_field * array _; _ _ int _ realsize _; };
struct discord_embed { _ _ char * title _; _ _ char * type _; _ _ char * description _; _ _ char * url _; _ _ u64unix_ms _ timestamp _; _ _ int _ color _; _ struct discord_embed_footer * footer _; _ struct discord_embed_image * image _; _ struct discord_embed_thumbnail * thumbnail _; _ struct discord_embed_video * video _; _ struct discord_embed_provider * provider _; _ struct discord_embed_author * author _; _ struct discord_embed_fields * fields _; };
struct discord_embeds { _ _ int _ size _; _ struct discord_embed * array _; _ _ int _ realsize _; };
struct discord_attachment { _ _ char * content _; _ _ u64snowflake _ id _; _ _ char * filename _; _ _ char * description _; _ _ char * content_type _; _ _ size_t _ size _; _ _ char * url _; _ _ char * proxy_url _; _ _ int _ height _; _ _ int _ width _; _ _ bool _ ephemeral _; _ _ int _ duration_secs _; _ _ char * waveform _; _ _ u64bitmask _ flags _; };
struct discord_attachments { _ _ int _ size _; _ struct discord_attachment * array _; _ _ int _ realsize _; };
struct discord_channel_mention { _ _ u64snowflake _ id _; _ _ u64snowflake _ guild_id _; _ enum discord_channel_types _ type _; _ _ char * name _; };
struct discord_allowed_mention { _ struct strings * parse _; _ struct snowflakes * roles _; _ struct snowflakes * users _; _ _ bool _ replied_user _; };
struct discord_role_subscription_data { _ _ u64snowflake _ role_subscription_listing_id _; _ _ char * tier_name _; _ _ int _ total_months_subscribed _; _ _ bool _ is_renewal _; };
struct discord_thread_response_body { _ struct discord_channels * threads _; _ struct discord_thread_members * members _; _ _ bool _ has_more _; };
struct discord_modify_channel { _ _ char * reason _; _ _ char * name _; _ _ char * icon _; _ enum discord_channel_types _ type _; _ _ int _ position _; _ _ char * topic _; _ _ bool _ nsfw _; _ _ int _ rate_limit_per_user _; _ _ int _ user_limit _; _ struct discord_overwrites * permission_overwrites _; _ _ u64snowflake _ parent_id _; _ _ char * rtc_region _; _ _ int _ video_quality_mode _; _ _ int _ default_auto_archive_duration _; _ _ bool _ archived _; _ _ int _ auto_archive_duration _; _ _ bool _ locked _; _ _ bool _ invitable _; };
struct discord_delete_channel { _ _ char * reason _; };
struct discord_get_channel_messages { _ _ u64snowflake _ around _; _ _ u64snowflake _ before _; _ _ u64snowflake _ after _; _ _ int _ limit _; };
struct discord_create_message { _ _ char * content _; _ _ bool _ tts _; _ struct discord_embeds * embeds _; _ struct discord_allowed_mention * allowed_mentions _; _ struct discord_message_reference * message_reference _; _ struct discord_components * components _; _ struct snowflakes * sticker_ids _; _ struct discord_attachments * attachments _; _ _ u64bitmask _ flags _; _ _ bool _ enforce_nonce _; };
struct discord_get_reactions { _ _ u64snowflake _ after _; _ _ int _ limit _; };
struct discord_edit_message { _ _ char * content _; _ struct discord_embeds * embeds _; _ _ u64bitmask _ flags _; _ struct discord_allowed_mention * allowed_mentions _; _ struct discord_components * components _; _ struct discord_attachments * attachments _; };
struct discord_delete_message { _ _ char * reason _; };
struct discord_bulk_delete_messages { _ _ char * reason _; _ struct snowflakes * messages _; };
struct discord_edit_channel_permissions { _ _ char * reason _; _ _ u64bitmask _ allow _; _ _ u64bitmask _ deny _; _ _ int _ type _; };
struct discord_create_channel_invite { _ _ char * reason _; _ _ int _ max_age _; _ _ int _ max_uses _; _ _ bool _ temporary _; _ _ bool _ unique _; _ enum discord_invite_target_types _ target_type _; _ _ u64snowflake _ target_user_id _; _ _ u64snowflake _ target_application_id _; };
struct discord_delete_channel_permission { _ _ char * reason _; };
struct discord_follow_news_channel { _ _ u64snowflake _ webhook_channel_id _; };
struct discord_pin_message { _ _ char * reason _; };
struct discord_unpin_message { _ _ char * reason _; };
struct discord_group_dm_add_recipient { _ _ char * access_token _; _ _ char * nick _; };
struct discord_start_thread_with_message { _ _ char * reason _; _ _ char * name _; _ _ int _ auto_archive_duration _; _ _ int _ rate_limit_per_user _; };
struct discord_start_thread_without_message { _ _ char * reason _; _ _ char * name _; _ _ int _ auto_archive_duration _; _ enum discord_channel_types _ type _; _ _ bool _ invitable _; _ _ int _ rate_limit_per_user _; };
struct discord_list_active_threads { _ struct discord_channels * threads _; _ struct discord_thread_members * members _; _ _ bool _ has_more _; };
struct strings { _ _ int _ size _; _ _ char ** array _; _ _ int _ realsize _; };
struct json_values { _ _ int _ size _; _ _ json_char ** array _; _ _ int _ realsize _; };
struct snowflakes { _ _ int _ size _; _ _ u64snowflake * array _; _ _ int _ realsize _; };
struct bitmasks { _ _ int _ size _; _ _ u64bitmask * array _; _ _ int _ realsize _; };
struct integers { _ _ int _ size _; _ _ int * array _; _ _ int _ realsize _; };
struct discord_emoji { _ _ u64snowflake _ id _; _ _ char * name _; _ struct snowflakes * roles _; _ struct discord_user * user _; _ _ bool _ require_colons _; _ _ bool _ managed _; _ _ bool _ animated _; _ _ bool _ available _; };
struct discord_emojis { _ _ int _ size _; _ struct discord_emoji * array _; _ _ int _ realsize _; };
struct discord_create_guild_emoji { _ _ char * reason _; _ _ char * name _; _ _ char * image _; _ struct snowflakes * roles _; };
struct discord_modify_guild_emoji { _ _ char * reason _; _ _ char * name _; _ _ char * image _; _ struct snowflakes * roles _; };
struct discord_delete_guild_emoji { _ _ char * reason _; };



struct discord_activity { _ _ char * name _; _ enum discord_activity_types _ type _; _ _ char * url _; _ _ u64unix_ms _ created_at _; _ struct discord_activity_timestamps * timestamps _; _ _ u64snowflake _ application_id _; _ _ char * details _; _ _ char * state _; _ struct discord_activity_emoji * emoji _; _ struct discord_activity_party * party _; _ struct discord_activity_assets * assets _; _ struct discord_activity_secrets * secrets _; _ _ bool _ instance _; _ _ u64bitmask _ flags _; _ struct discord_activity_buttons * buttons _; };
struct discord_activities { _ _ int _ size _; _ struct discord_activity * array _; _ _ int _ realsize _; };
struct discord_activity_timestamps { _ _ u64unix_ms _ start _; _ _ u64unix_ms _ end _; };
struct discord_activity_emoji { _ _ char * name _; _ _ u64snowflake _ id _; _ _ bool _ animated _; };
struct discord_activity_party { _ _ char * id _; _ struct integers * size _; };
struct discord_activity_assets { _ _ char * large_image _; _ _ char * large_text _; _ _ char * small_image _; _ _ char * small_text _; };
struct discord_activity_secrets { _ _ char * join _; _ _ char * spectate _; _ _ char * match _; };
struct discord_activity_button { _ _ char * label _; _ _ char * url _; };
struct discord_activity_buttons { _ _ int _ size _; _ struct discord_activity_button * array _; _ _ int _ realsize _; };
struct discord_presence_update { _ struct discord_user * user _; _ _ u64snowflake _ guild_id _; _ _ char * status _; _ struct discord_client_status * client_status _; _ struct discord_activities * activities _; _ _ u64unix_ms _ since _; _ _ bool _ afk _; };
struct discord_client_status { _ _ char * desktop _; _ _ char * mobile _; _ _ char * web _; };
struct discord_presence_updates { _ _ int _ size _; _ struct discord_presence_update * array _; _ _ int _ realsize _; };
struct discord_identify { _ _ char * token _; _ struct discord_identify_connection * properties _; _ _ bool _ compress _; _ _ int _ large_threshold _; _ struct integers * shard _; _ struct discord_presence_update * presence _; _ _ u64bitmask _ intents _; };
struct discord_identify_connection { _ _ char * os _; _ _ char * browser _; _ _ char * device _; };
struct discord_resume { _ _ char * token _; _ _ char * session_id _; _ _ int _ seq _; };
struct discord_request_guild_members { _ _ u64snowflake _ guild_id _; _ _ char * query _; _ _ int _ limit _; _ _ bool _ presences _; _ struct snowflakes * user_ids _; _ _ char * nonce _; };
struct discord_update_voice_state { _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; _ _ bool _ self_mute _; _ _ bool _ self_deaf _; };
struct discord_ready { _ _ int _ v _; _ struct discord_user * user _; _ struct discord_guilds * guilds _; _ _ char * session_id _; _ struct integers * shard _; _ struct discord_application * application _; };
struct discord_auto_moderation_action_execution { _ _ u64snowflake _ guild_id _; _ struct discord_auto_moderation_action * action _; _ enum discord_auto_moderation_trigger_types _ rule_trigger_type _; _ _ u64snowflake _ user_id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ message_id _; _ _ u64snowflake _ alert_system_message_id _; _ _ char * content _; _ _ char * matched_keyword _; _ _ char * matched_content _; };
struct discord_thread_list_sync { _ _ u64snowflake _ guild_id _; _ struct snowflakes * channel_ids _; _ struct discord_channels * threads _; _ struct discord_thread_members * members _; };
struct discord_thread_members_update { _ _ u64snowflake _ id _; _ _ u64snowflake _ guild_id _; _ _ int _ member_count _; _ struct discord_thread_members * added_members _; _ struct snowflakes * removed_member_ids _; };
struct discord_channel_pins_update { _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; _ _ u64unix_ms _ last_pin_timestamp _; };
struct discord_guild_ban_add { _ _ u64snowflake _ guild_id _; _ struct discord_user * user _; };
struct discord_guild_ban_remove { _ _ u64snowflake _ guild_id _; _ struct discord_user * user _; };
struct discord_guild_emojis_update { _ _ u64snowflake _ guild_id _; _ struct discord_emojis * emojis _; };
struct discord_guild_stickers_update { _ _ u64snowflake _ guild_id _; _ struct discord_stickers * stickers _; };
struct discord_guild_integrations_update { _ _ u64snowflake _ guild_id _; };
struct discord_guild_member_remove { _ _ u64snowflake _ guild_id _; _ struct discord_user * user _; };
struct discord_guild_member_update { _ _ u64snowflake _ guild_id _; _ struct snowflakes * roles _; _ struct discord_user * user _; _ _ char * nick _; _ _ char * avatar _; _ _ u64unix_ms _ joined_at _; _ _ u64unix_ms _ premium_since _; _ _ bool _ deaf _; _ _ bool _ mute _; _ _ bool _ pending _; _ _ u64unix_ms _ communication_disabled_until _; };
struct discord_guild_members_chunk { _ _ u64snowflake _ guild_id _; _ struct discord_guild_members * members _; _ _ int _ chunk_index _; _ _ int _ chunk_count _; _ struct snowflakes * not_found _; _ struct discord_presence_updates * presences _; _ _ char * nonce _; };
struct discord_guild_role_create { _ _ u64snowflake _ guild_id _; _ struct discord_role * role _; };
struct discord_guild_role_update { _ _ u64snowflake _ guild_id _; _ struct discord_role * role _; };
struct discord_guild_role_delete { _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ role_id _; };
struct discord_guild_scheduled_event_user_add { _ _ u64snowflake _ guild_scheduled_event_id _; _ _ u64snowflake _ user_id _; _ _ u64snowflake _ guild_id _; };
struct discord_guild_scheduled_event_user_remove { _ _ u64snowflake _ guild_scheduled_event_id _; _ _ u64snowflake _ user_id _; _ _ u64snowflake _ guild_id _; };
struct discord_integration_delete { _ _ u64snowflake _ id _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ application_id _; };
struct discord_invite_create { _ _ u64snowflake _ channel_id _; _ _ char * code _; _ _ u64unix_ms _ created_at _; _ _ u64snowflake _ guild_id _; _ struct discord_user * inviter _; _ _ int _ max_age _; _ _ int _ max_uses _; _ enum discord_invite_target_types _ target_type _; _ struct discord_user * target_user _; _ struct discord_application * target_application _; _ _ bool _ temporary _; _ _ int _ uses _; };
struct discord_invite_delete { _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ guild_id _; _ _ char * code _; };
struct discord_message_delete { _ _ u64snowflake _ id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ guild_id _; };
struct discord_message_delete_bulk { _ struct snowflakes * ids _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ guild_id _; };
struct discord_message_reaction_add { _ _ u64snowflake _ user_id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ message_id _; _ _ u64snowflake _ guild_id _; _ struct discord_guild_member * member _; _ struct discord_emoji * emoji _; };
struct discord_message_reaction_remove { _ _ u64snowflake _ user_id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ message_id _; _ _ u64snowflake _ guild_id _; _ struct discord_emoji * emoji _; };
struct discord_message_reaction_remove_all { _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ message_id _; _ _ u64snowflake _ guild_id _; };
struct discord_message_reaction_remove_emoji { _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ message_id _; _ struct discord_emoji * emoji _; };
struct discord_typing_start { _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ user_id _; _ _ u64unix_ms _ timestamp _; _ struct discord_guild_member * member _; };
struct discord_voice_server_update { _ _ char * token _; _ _ u64snowflake _ guild_id _; _ _ char * endpoint _; };
struct discord_webhooks_update { _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; };
struct discord_session_start_limit { _ _ int _ total _; _ _ int _ remaining _; _ _ int _ reset_after _; _ _ int _ max_concurrency _; };







struct discord_guild { _ _ u64snowflake _ id _; _ _ char * name _; _ _ char * icon _; _ _ char * icon_hash _; _ _ char * splash _; _ _ char * discovery_splash _; _ _ bool _ owner _; _ _ u64snowflake _ owner_id _; _ _ u64bitmask _ permissions _; _ _ u64snowflake _ afk_channel_id _; _ _ int _ afk_timeout _; _ _ bool _ widget_enabled _; _ _ u64snowflake _ widget_channel_id _; _ enum discord_verification_level _ verification_level _; _ enum discord_message_notification_level _ default_message_notifications _; _ enum discord_explicit_content_filter_level _ explicit_content_filter _; _ struct discord_roles * roles _; _ struct discord_emojis * emojis _; _ struct strings * features _; _ enum discord_mfa_level _ mfa_level _; _ _ u64snowflake _ application_id _; _ _ u64snowflake _ system_channel_id _; _ _ u64bitmask _ system_channel_flags _; _ _ u64snowflake _ rules_channel_id _; _ _ u64unix_ms _ joined_at _; _ _ bool _ large _; _ _ bool _ unavailable _; _ _ int _ member_count _; _ struct discord_voice_states * voice_states _; _ struct discord_guild_members * members _; _ struct discord_channels * channels _; _ struct discord_channels * threads _; _ struct discord_presence_updates * presences _; _ _ int _ max_presences _; _ _ int _ max_members _; _ _ char * vanity_url_code _; _ _ char * description _; _ _ char * banner _; _ enum discord_premium_tier _ premium_tier _; _ _ int _ premium_subscription_count _; _ _ char * preferred_locale _; _ _ u64snowflake _ public_updates_channel_id _; _ _ int _ max_video_channel_users _; _ _ int _ approximate_member_count _; _ _ int _ approximate_presence_count _; _ struct discord_welcome_screen * welcome_screen _; _ enum discord_guild_nsfw_level _ nsfw_level _; _ struct discord_stage_instances * stage_instances _; _ struct discord_stickers * stickers _; _ struct discord_guild_scheduled_events * guild_scheduled_events _; _ _ bool _ premium_progress_bar_enabled _; };
struct discord_guilds { _ _ int _ size _; _ struct discord_guild * array _; _ _ int _ realsize _; };
struct discord_guild_preview { _ _ u64snowflake _ id _; _ _ char * name _; _ _ char * icon _; _ _ char * splash _; _ _ char * discovery_splash _; _ struct discord_emojis * emojis _; _ struct strings * features _; _ _ int _ approximate_member_count _; _ _ int _ approximate_presence_count _; _ _ char * description _; _ struct discord_stickers * stickers _; };
struct discord_guild_widget_settings { _ _ char * reason _; _ _ bool _ enabled _; _ _ u64snowflake _ channel_id _; };
struct discord_guild_widget { _ _ u64snowflake _ id _; _ _ char * name _; _ _ char * instant_invite _; _ struct discord_channels * channels _; _ struct discord_users * members _; _ _ int _ presence_count _; };
struct discord_guild_member { _ struct discord_user * user _; _ _ char * nick _; _ _ char * avatar _; _ struct snowflakes * roles _; _ _ u64unix_ms _ joined_at _; _ _ u64unix_ms _ premium_since _; _ _ bool _ deaf _; _ _ bool _ muted _; _ _ bool _ pending _; _ _ u64bitmask _ permissions _; _ _ u64unix_ms _ communication_disabled_until _; _ _ u64snowflake _ guild_id _; };
struct discord_guild_members { _ _ int _ size _; _ struct discord_guild_member * array _; _ _ int _ realsize _; };
struct discord_integration { _ _ u64snowflake _ id _; _ _ char * name _; _ _ char * type _; _ _ bool _ enabled _; _ _ bool _ syncing _; _ _ u64snowflake _ role_id _; _ _ bool _ enable_emoticons _; _ enum discord_integration_expire_behaviors _ expire_behavior _; _ _ int _ expire_grace_period _; _ struct discord_user * user _; _ struct discord_integration_account * account _; _ _ u64unix_ms _ synced_at _; _ _ int _ subscriber_count _; _ _ bool _ revoked _; _ struct discord_integration_application * application _; _ _ u64snowflake _ guild_id _; };
struct discord_integrations { _ _ int _ size _; _ struct discord_integration * array _; _ _ int _ realsize _; };
struct discord_integration_account { _ _ char * id _; _ _ char * name _; };
struct discord_integration_application { _ _ u64snowflake _ id _; _ _ char * name _; _ _ char * icon _; _ _ char * description _; _ _ char * summary _; _ struct discord_user * bot _; };
struct discord_ban { _ _ char * reason _; _ struct discord_user * user _; };
struct discord_bans { _ _ int _ size _; _ struct discord_ban * array _; _ _ int _ realsize _; };
struct discord_welcome_screen { _ _ char * description _; _ struct discord_welcome_screen_channels * welcome_channels _; };
struct discord_welcome_screen_channel { _ _ u64snowflake _ channel_id _; _ _ char * description _; _ _ u64snowflake _ emoji_id _; _ _ char * emoji_name _; };
struct discord_welcome_screen_channels { _ _ int _ size _; _ struct discord_welcome_screen_channel * array _; _ _ int _ realsize _; };
struct discord_prune_count { _ _ int _ pruned _; };
struct discord_create_guild { _ _ char * reason _; _ _ char * name _; _ _ char * region _; _ _ char * icon _; _ enum discord_verification_level _ verification_level _; _ enum discord_message_notification_level _ default_message_notifications _; _ enum discord_explicit_content_filter_level _ explicit_content_filter _; _ struct discord_roles * roles _; _ struct discord_channels * channels _; _ _ u64snowflake _ afk_channel_id _; _ _ int _ afk_timeout _; _ _ u64snowflake _ system_channel_id _; _ _ u64bitmask _ system_channel_flags _; };
struct discord_modify_guild { _ _ char * reason _; _ _ char * name _; _ enum discord_verification_level _ verification_level _; _ enum discord_message_notification_level _ default_message_notifications _; _ enum discord_explicit_content_filter_level _ explicit_content_filter _; _ _ u64snowflake _ afk_channel_id _; _ _ int _ afk_timeout _; _ _ char * icon _; _ _ u64snowflake _ owner_id _; _ _ char * splash _; _ _ char * discovery_splash _; _ _ char * banner _; _ _ u64snowflake _ system_channel_id _; _ _ u64bitmask _ system_channel_flags _; _ _ u64snowflake _ rules_channel_id _; _ _ u64snowflake _ public_updates_channel_id _; _ _ char * preferred_locale _; _ struct strings * features _; _ _ char * description _; _ _ bool _ premium_progress_bar_enabled _; };
struct discord_create_guild_channel { _ _ char * reason _; _ _ char * name _; _ enum discord_channel_types _ type _; _ _ char * topic _; _ _ int _ bitrate _; _ _ int _ user_limit _; _ _ int _ rate_limit_per_user _; _ _ int _ position _; _ struct discord_overwrites * permission_overwrites _; _ _ u64snowflake _ parent_id _; _ _ bool _ nsfw _; };
struct discord_modify_guild_channel_position { _ _ u64snowflake _ id _; _ _ int _ position _; _ _ bool _ lock_category _; _ _ u64snowflake _ parent_id _; };
struct discord_modify_guild_channel_positions { _ _ int _ size _; _ struct discord_modify_guild_channel_position * array _; _ _ int _ realsize _; };
struct discord_list_active_guild_threads { _ struct discord_channels * threads _; _ struct discord_thread_members * members _; };
struct discord_list_guild_members { _ _ int _ limit _; _ _ u64snowflake _ after _; };
struct discord_search_guild_members { _ _ char * query _; _ _ int _ limit _; };
struct discord_add_guild_member { _ _ char * access_token _; _ _ char * nick _; _ struct snowflakes * roles _; _ _ bool _ mute _; _ _ bool _ deaf _; };
struct discord_modify_guild_member { _ _ char * reason _; _ _ char * nick _; _ struct snowflakes * roles _; _ _ bool _ mute _; _ _ bool _ deaf _; _ _ u64snowflake _ channel_id _; _ _ u64unix_ms _ communication_disabled_until _; };
struct discord_modify_current_member { _ _ char * reason _; _ _ char * nick _; };
struct discord_modify_current_user_nick { _ _ char * reason _; _ _ char * nick _; };
struct discord_add_guild_member_role { _ _ char * reason _; };
struct discord_remove_guild_member_role { _ _ char * reason _; };
struct discord_remove_guild_member { _ _ char * reason _; };
struct discord_create_guild_ban { _ _ char * reason _; _ _ int _ delete_message_days _; };
struct discord_remove_guild_ban { _ _ char * reason _; };
struct discord_create_guild_role { _ _ char * reason _; _ _ char * name _; _ _ u64bitmask _ permissions _; _ _ int _ color _; _ _ bool _ hoist _; _ _ char * icon _; _ _ char * unicode_emoji _; _ _ bool _ mentionable _; };
struct discord_modify_guild_role_position { _ _ u64snowflake _ id _; _ _ int _ position _; };
struct discord_modify_guild_role_positions { _ _ int _ size _; _ struct discord_modify_guild_role_position * array _; _ _ int _ realsize _; };
struct discord_modify_guild_role { _ _ char * reason _; _ _ char * name _; _ _ u64bitmask _ permissions _; _ _ int _ color _; _ _ bool _ hoist _; _ _ char * icon _; _ _ char * unicode_emoji _; _ _ bool _ mentionable _; };
struct discord_delete_guild_role { _ _ char * reason _; };
struct discord_get_guild_prune_count { _ _ int _ days _; _ struct snowflakes * include_roles _; };
struct discord_begin_guild_prune { _ _ char * reason _; _ _ int _ days _; _ _ bool _ compute_prune_count _; _ struct snowflakes * include_roles _; };
struct discord_delete_guild_integrations { _ _ char * reason _; _ _ int _ days _; _ struct snowflakes * include_roles _; };
struct discord_get_guild_widget_image { _ _ char * style _; };
struct discord_modify_guild_welcome_screen { _ _ char * reason _; _ _ bool _ enabled _; _ struct discord_welcome_screen_channels * welcome_channels _; _ _ char * description _; };
struct discord_modify_current_user_voice_state { _ _ u64snowflake _ channel_id _; _ _ bool _ suppress _; _ _ u64unix_ms _ request_to_speak_timestamp _; };
struct discord_modify_user_voice_state { _ _ u64snowflake _ channel_id _; _ _ bool _ suppress _; };



struct discord_guild_scheduled_event { _ _ u64snowflake _ id _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ creator_id _; _ _ char * name _; _ _ char * description _; _ _ u64unix_ms _ scheduled_start_time _; _ _ u64unix_ms _ scheduled_end_time _; _ enum discord_guild_scheduled_event_privacy_level _ privacy_level _; _ enum discord_guild_scheduled_event_status _ status _; _ enum discord_guild_scheduled_event_entity_types _ entity_type _; _ _ u64snowflake _ entity_id _; _ struct discord_guild_scheduled_event_entity_metadata * entity_metadata _; _ struct discord_user * creator _; _ _ int _ user_count _; _ _ char * image _; };
struct discord_guild_scheduled_event_entity_metadata { _ _ char * location _; };
struct discord_guild_scheduled_events { _ _ int _ size _; _ struct discord_guild_scheduled_event * array _; _ _ int _ realsize _; };
struct discord_guild_scheduled_event_user { _ _ u64snowflake _ guild_scheduled_event_id _; _ struct discord_user * user _; _ struct discord_guild_member * member _; };
struct discord_guild_scheduled_event_users { _ _ int _ size _; _ struct discord_guild_scheduled_event_user * array _; _ _ int _ realsize _; };
struct discord_list_guild_scheduled_events { _ _ bool _ with_user_count _; };
struct discord_create_guild_scheduled_event { _ _ char * reason _; _ _ u64snowflake _ channel_id _; _ struct discord_guild_scheduled_event_entity_metadata * entity_metadata _; _ _ char * name _; _ enum discord_guild_scheduled_event_privacy_level _ privacy_level _; _ _ u64unix_ms _ scheduled_start_time _; _ _ u64unix_ms _ scheduled_end_time _; _ _ char * description _; _ enum discord_guild_scheduled_event_entity_types _ entity_type _; _ _ char * image _; };
struct discord_get_guild_scheduled_event { _ _ bool _ with_user_count _; };
struct discord_modify_guild_scheduled_event { _ _ char * reason _; _ _ u64snowflake _ channel_id _; _ struct discord_guild_scheduled_event_entity_metadata * entity_metadata _; _ _ char * name _; _ _ u64unix_ms _ scheduled_start_time _; _ _ u64unix_ms _ scheduled_end_time _; _ _ char * description _; _ enum discord_guild_scheduled_event_entity_types _ entity_type _; _ enum discord_guild_scheduled_event_status _ status _; _ _ char * image _; };
struct discord_get_guild_scheduled_event_users { _ _ int _ limit _; _ _ bool _ with_member _; _ _ u64snowflake _ before _; _ _ u64snowflake _ after _; };
struct discord_guild_template { _ _ char * code _; _ _ char * name _; _ _ char * description _; _ _ int _ usage_count _; _ _ u64snowflake _ creator_id _; _ struct discord_user * creator _; _ _ u64unix_ms _ created_at _; _ _ u64unix_ms _ updated_at _; _ _ u64snowflake _ source_guild_id _; _ struct discord_guild * serialized_source_guild _; _ _ bool _ is_dirty _; };
struct discord_guild_templates { _ _ int _ size _; _ struct discord_guild_template * array _; _ _ int _ realsize _; };
struct discord_create_guild_from_guild_template { _ _ char * name _; _ _ char * icon _; };
struct discord_create_guild_template { _ _ char * name _; _ _ char * description _; };
struct discord_modify_guild_template { _ _ char * name _; _ _ char * description _; };


struct discord_interaction { _ _ u64snowflake _ id _; _ _ u64snowflake _ application_id _; _ enum discord_interaction_types _ type _; _ struct discord_interaction_data * data _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; _ struct discord_guild_member * member _; _ struct discord_user * user _; _ _ char * token _; _ _ int _ version _; _ struct discord_message * message _; _ _ char * locale _; _ _ char * guild_locale _; };
struct discord_interaction_data { _ _ u64snowflake _ id _; _ _ char * name _; _ enum discord_application_command_types _ type _; _ struct discord_resolved_data * resolved _; _ struct discord_application_command_interaction_data_options * options _; _ _ char * custom_id _; _ enum discord_component_types _ component_type _; _ struct strings * values _; _ _ u64snowflake _ target_id _; _ struct discord_components * components _; };
struct discord_resolved_data { _ _ json_char * users _; _ _ json_char * members _; _ _ json_char * roles _; _ _ json_char * channels _; _ _ json_char * messages _; _ _ json_char * attachments _; };
struct discord_message_interaction { _ _ u64snowflake _ id _; _ enum discord_interaction_types _ type _; _ _ char * name _; _ struct discord_user * user _; _ struct discord_guild_member * member _; };
struct discord_interaction_response { _ enum discord_interaction_callback_types _ type _; _ struct discord_interaction_callback_data * data _; };
struct discord_interaction_callback_data { _ struct discord_components * components _; _ _ bool _ tts _; _ _ char * content _; _ struct discord_embeds * embeds _; _ _ u64bitmask _ flags _; _ struct discord_attachments * attachments _; _ struct discord_application_command_option_choices * choices _; _ _ char * custom_id _; _ _ char * title _; };
struct discord_edit_original_interaction_response { _ _ u64snowflake _ thread_id _; _ _ char * content _; _ struct discord_embeds * embeds _; _ struct discord_allowed_mention * allowed_mentions _; _ struct discord_components * components _; _ struct discord_attachments * attachments _; };
struct discord_create_followup_message { _ _ bool _ wait _; _ _ u64snowflake _ thread_id _; _ _ char * avatar_url _; _ _ bool _ tts _; _ struct discord_embeds * embeds _; _ struct discord_allowed_mention * allowed_mentions _; _ struct discord_components * components _; _ struct discord_attachments * attachments _; _ _ u64bitmask _ flags _; };
struct discord_edit_followup_message { _ _ u64snowflake _ thread_id _; _ _ char * content _; _ struct discord_embeds * embeds _; _ struct discord_allowed_mention * allowed_mentions _; _ struct discord_components * components _; _ struct discord_attachments * attachments _; };

struct discord_invite { _ _ char * code _; _ struct discord_guild * guild _; _ struct discord_channel * channel _; _ struct discord_user * inviter _; _ enum discord_invite_target_types _ target_type _; _ struct discord_user * target_user _; _ struct discord_application * target_application _; _ _ int _ approximate_presence_count _; _ _ int _ approximate_member_count _; _ _ u64unix_ms _ expires_at _; _ struct discord_invite_stage_instance * stage_instance _; _ struct discord_guild_scheduled_event * guild_scheduled_event _; };
struct discord_invites { _ _ int _ size _; _ struct discord_invite * array _; _ _ int _ realsize _; };
struct discord_invite_metadata { _ _ int _ uses _; _ _ int _ max_uses _; _ _ int _ max_age _; _ _ bool _ temporary _; _ _ u64unix_ms _ created_at _; };
struct discord_invite_stage_instance { _ struct discord_guild_members * members _; _ _ int _ participant_count _; _ _ int _ speaker_count _; _ _ char * topic _; };
struct discord_get_invite { _ _ bool _ with_counts _; _ _ bool _ with_expiration _; _ _ u64snowflake _ guild_scheduled_event_id _; };
struct discord_delete_invite { _ _ char * reason _; };



struct discord_component { _ _ u64snowflake _ id _; _ enum discord_component_types _ type _; _ _ char * custom_id _; _ _ u64snowflake _ sku_id _; _ enum discord_component_styles _ style _; _ _ char * label _; _ struct discord_emoji * emoji _; _ _ char * url _; _ struct discord_select_options * options _; _ _ char * placeholder _; _ _ int _ min_values _; _ _ int _ max_values _; _ struct discord_components * components _; _ _ int _ min_length _; _ _ int _ max_length _; _ _ bool _ required _; _ _ char * value _; };
struct discord_components { _ _ int _ size _; _ struct discord_component * array _; _ _ int _ realsize _; };
struct discord_select_option { _ _ char * label _; _ _ char * value _; _ _ char * description _; _ struct discord_emoji * emoji _; _ _ bool _ Default _; };
struct discord_select_options { _ _ int _ size _; _ struct discord_select_option * array _; _ _ int _ realsize _; };
struct discord_component_media { _ _ char * url _; };
struct discord_component_item { _ struct discord_component_media * media _; _ _ char * description _; _ _ bool _ spoiler _; };
struct discord_component_items { _ _ int _ size _; _ struct discord_component_item * array _; _ _ int _ realsize _; };
struct discord_auth_response { _ struct discord_application * application _; _ struct strings * scopes _; _ _ u64unix_ms _ expires _; _ struct discord_user * user _; };
struct discord_role { _ _ u64snowflake _ id _; _ _ char * name _; _ _ int _ color _; _ _ bool _ hoist _; _ _ char * icon _; _ _ char * unicode_emoji _; _ _ int _ position _; _ _ u64bitmask _ permissions _; _ _ bool _ managed _; _ _ bool _ mentionable _; _ struct discord_role_tag * tags _; };
struct discord_roles { _ _ int _ size _; _ struct discord_role * array _; _ _ int _ realsize _; };
struct discord_role_tag { _ _ u64snowflake _ bot_id _; _ _ u64snowflake _ integration_id _; _ _ bool _ premium_subscribe _; };

struct discord_stage_instance { _ _ u64snowflake _ id _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; _ _ char * topic _; _ enum discord_privacy_level _ privacy_level _; _ _ bool _ discoverable_disabled _; };
struct discord_stage_instances { _ _ int _ size _; _ struct discord_stage_instance * array _; _ _ int _ realsize _; };
struct discord_create_stage_instance { _ _ char * reason _; _ _ u64snowflake _ channel_id _; _ _ char * topic _; _ enum discord_privacy_level _ privacy_level _; };
struct discord_modify_stage_instance { _ _ char * reason _; _ _ char * topic _; _ enum discord_privacy_level _ privacy_level _; };
struct discord_delete_stage_instance { _ _ char * reason _; };


struct discord_sticker { _ _ u64snowflake _ id _; _ _ u64snowflake _ pack_id _; _ _ char * name _; _ _ char * description _; _ _ char * tags _; _ enum discord_sticker_types _ type _; _ enum discord_sticker_format_types _ format_type _; _ _ bool _ available _; _ _ u64snowflake _ guild_id _; _ struct discord_user * user _; _ _ int _ sort_value _; };
struct discord_stickers { _ _ int _ size _; _ struct discord_sticker * array _; _ _ int _ realsize _; };
struct discord_sticker_item { _ _ u64snowflake _ id _; _ _ char * name _; _ enum discord_sticker_format_types _ format_type _; };
struct discord_sticker_items { _ _ int _ size _; _ struct discord_sticker_item * array _; _ _ int _ realsize _; };
struct discord_sticker_pack { _ _ u64snowflake _ id _; _ struct discord_stickers * stickers _; _ _ char * name _; _ _ u64snowflake _ sku_id _; _ _ u64snowflake _ cover_sticker_id _; _ _ char * description _; _ _ u64snowflake _ banner_asset_id _; };
struct discord_sticker_packs { _ _ int _ size _; _ struct discord_sticker_pack * array _; _ _ int _ realsize _; };
struct discord_list_nitro_sticker_packs { _ struct discord_sticker_packs * sticker_packs _; };
struct discord_create_guild_sticker { _ _ char * reason _; _ _ char * name _; _ _ char * description _; _ _ char * tags _; _ struct discord_attachment * file _; };
struct discord_modify_guild_sticker { _ _ char * reason _; _ _ char * name _; _ _ char * description _; _ _ char * tags _; };
struct discord_delete_guild_sticker { _ _ char * reason _; };

struct discord_team { _ _ char * icon _; _ _ u64snowflake _ id _; _ struct discord_team_members * members _; _ _ char * name _; _ _ u64snowflake _ owner_user_id _; };
struct discord_team_member { _ enum discord_membership_state _ membership_state _; _ struct bitmasks * permissions _; _ _ u64snowflake _ team_id _; _ struct discord_user * user _; };
struct discord_team_members { _ _ int _ size _; _ struct discord_team_member * array _; _ _ int _ realsize _; };


struct discord_user { _ _ u64snowflake _ id _; _ _ char * username _; _ _ char * discriminator _; _ _ char * avatar _; _ _ bool _ bot _; _ _ bool _ System _; _ _ bool _ mfa_enabled _; _ _ char * banner _; _ _ int _ accent_color _; _ _ char * locale _; _ _ bool _ verified _; _ _ char * email _; _ _ u64bitmask _ flags _; _ enum discord_premium_types _ premium_type _; _ _ u64bitmask _ public_flags _; };
struct discord_users { _ _ int _ size _; _ struct discord_user * array _; _ _ int _ realsize _; };
struct discord_connection { _ _ u64snowflake _ id _; _ _ char * name _; _ _ char * type _; _ _ bool _ revoked _; _ struct discord_integrations * integrations _; _ _ bool _ verified _; _ _ bool _ friend_sync _; _ _ bool _ show_activity _; _ enum discord_visibility_types _ visibility _; };
struct discord_connections { _ _ int _ size _; _ struct discord_connection * array _; _ _ int _ realsize _; };
struct discord_modify_current_user { _ _ char * username _; _ _ char * avatar _; };
struct discord_get_current_user_guilds { _ _ u64snowflake _ before _; _ _ u64snowflake _ after _; _ _ int _ limit _; };
struct discord_create_dm { _ _ u64snowflake _ recipient_id _; };
struct discord_create_group_dm { _ struct snowflakes * access_tokens _; _ struct strings * nicks _; };
struct discord_voice_state { _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; _ _ u64snowflake _ user_id _; _ struct discord_guild_member * member _; _ _ char * session_id _; _ _ bool _ deaf _; _ _ bool _ mute _; _ _ bool _ self_deaf _; _ _ bool _ self_mute _; _ _ bool _ self_stream _; _ _ bool _ self_video _; _ _ bool _ suppress _; _ _ u64unix_ms _ request_to_speak_timestamp _; };
struct discord_voice_states { _ _ int _ size _; _ struct discord_voice_state * array _; _ _ int _ realsize _; };
struct discord_voice_region { _ _ char * id _; _ _ char * name _; _ _ bool _ optimal _; _ _ bool _ deprecated _; _ _ bool _ custom _; };
struct discord_voice_regions { _ _ int _ size _; _ struct discord_voice_region * array _; _ _ int _ realsize _; };



struct discord_webhook { _ _ u64snowflake _ id _; _ enum discord_webhook_types _ type _; _ _ u64snowflake _ guild_id _; _ _ u64snowflake _ channel_id _; _ struct discord_user * user _; _ _ char * name _; _ _ char * token _; _ _ u64snowflake _ application_id _; _ struct discord_channel * source_channel _; _ _ char * url _; };
struct discord_webhooks { _ _ int _ size _; _ struct discord_webhook * array _; _ _ int _ realsize _; };
struct discord_create_webhook { _ _ char * reason _; _ _ char * name _; _ _ char * avatar _; };
struct discord_modify_webhook { _ _ char * reason _; _ _ char * name _; _ _ char * avatar _; _ _ u64snowflake _ channel_id _; };
struct discord_delete_webhook { _ _ char * reason _; };
struct discord_modify_webhook_with_token { _ _ char * name _; _ _ char * avatar _; };
struct discord_execute_webhook { _ _ bool _ wait _; _ _ u64snowflake _ thread_id _; _ _ char * content _; _ _ char * username _; _ _ char * avatar_url _; _ _ bool _ tts _; _ struct discord_embeds * embeds _; _ struct discord_allowed_mention * allowed_mentions _; _ struct discord_components * components _; _ struct discord_attachments * attachments _; _ _ u64bitmask _ flags _; };
struct discord_get_webhook_message { _ _ u64snowflake _ thread_id _; };
struct discord_edit_webhook_message { _ _ u64snowflake _ thread_id _; _ _ char * content _; _ struct discord_embeds * embeds _; _ struct discord_allowed_mention * allowed_mentions _; _ struct discord_components * components _; _ struct discord_attachments * attachments _; };
struct discord_delete_webhook_message { _ _ u64snowflake _ thread_id _; };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application__id), REFLECTC_NS_UPPER(_LOOKUP__discord_application__name), REFLECTC_NS_UPPER(_LOOKUP__discord_application__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_application__description), REFLECTC_NS_UPPER(_LOOKUP__discord_application__rpc_origins), REFLECTC_NS_UPPER(_LOOKUP__discord_application__bot_public), REFLECTC_NS_UPPER(_LOOKUP__discord_application__bot_require_code_grant), REFLECTC_NS_UPPER(_LOOKUP__discord_application__terms_of_service_url), REFLECTC_NS_UPPER(_LOOKUP__discord_application__privacy_policy_url), REFLECTC_NS_UPPER(_LOOKUP__discord_application__owner), REFLECTC_NS_UPPER(_LOOKUP__discord_application__summary), REFLECTC_NS_UPPER(_LOOKUP__discord_application__verify_key), REFLECTC_NS_UPPER(_LOOKUP__discord_application__team), REFLECTC_NS_UPPER(_LOOKUP__discord_application__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_application__primary_sku_id), REFLECTC_NS_UPPER(_LOOKUP__discord_application__slug), REFLECTC_NS_UPPER(_LOOKUP__discord_application__cover_image), REFLECTC_NS_UPPER(_LOOKUP__discord_application__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_application_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_install_params__scopes), REFLECTC_NS_UPPER(_LOOKUP__discord_install_params__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_install_params_MAX) };



enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__id), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__type), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__name), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__description), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__options), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__default_member_permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__dm_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__default_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command__version), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_commands__size), REFLECTC_NS_UPPER(_LOOKUP__discord_application_commands__array), REFLECTC_NS_UPPER(_LOOKUP__discord_application_commands__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_application_commands_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__type), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__name), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__description), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__required), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__choices), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__options), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__channel_types), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__min_value), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__max_value), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option__autocomplete), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_options__size), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_options__array), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_options__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_options_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_choice__name), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_choice__value), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_choice_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_choices__size), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_choices__array), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_choices__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_option_choices_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_option__name), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_option__type), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_option__value), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_option__options), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_option__focused), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_option_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_options__size), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_options__array), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_options__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_interaction_data_options_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permission__id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permission__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permission__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permission__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permission_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permissions__size), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permissions__array), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permissions__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_application_command_permissions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permission__id), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permission__type), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permission__permission), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permission_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permissions__size), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permissions__array), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permissions__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_application_command_permissions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command__description), REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command__options), REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command__default_member_permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command__dm_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command__default_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command__type), REFLECTC_NS_UPPER(_LOOKUP__discord_create_global_application_command_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_edit_global_application_command__name), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_global_application_command__description), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_global_application_command__options), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_global_application_command__default_member_permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_global_application_command__dm_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_global_application_command__default_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_global_application_command_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command__description), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command__options), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command__default_member_permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command__dm_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command__default_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command__type), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_application_command_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_edit_guild_application_command__name), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_guild_application_command__description), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_guild_application_command__options), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_guild_application_command__default_member_permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_guild_application_command__default_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_guild_application_command_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__id), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__name), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__name_localizations), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__description), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__description_localizations), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__options), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__default_member_permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__dm_permission), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command__type), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_command_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_commands__size), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_commands__array), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_commands__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_overwrite_guild_application_commands_MAX) };

enum { REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log__audit_log_entries), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log__guild_scheduled_events), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log__integrations), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log__threads), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log__users), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log__webhooks), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry__target_id), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry__changes), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry__id), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry__action_type), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry__options), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entry_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entries__size), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entries__array), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entries__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_entries_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__count), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__delete_member_days), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__id), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__members_removed), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__role_name), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info__type), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_info_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_infos__size), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_infos__array), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_infos__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_optional_audit_entry_infos_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_change__new_value), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_change__old_value), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_change__key), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_change_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_changes__size), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_changes__array), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_changes__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_audit_log_changes_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_audit_log__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_audit_log__action_type), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_audit_log__before), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_audit_log__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_audit_log_MAX) };




enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_trigger_metadata__keyword_filter), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_trigger_metadata__presets), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_trigger_metadata_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action__type), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action__metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_actions__size), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_actions__array), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_actions__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_actions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_metadata__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_metadata__duration_seconds), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_metadata_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__name), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__creator_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__event_type), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__trigger_type), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__actions), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__trigger_metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__exempt_roles), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule__exempt_channels), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rule_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rules__size), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rules__array), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rules__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_rules_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__event_type), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__trigger_type), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__actions), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__trigger_metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__exempt_roles), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule__exempt_channels), REFLECTC_NS_UPPER(_LOOKUP__discord_create_auto_moderation_rule_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__event_type), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__trigger_metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__actions), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__exempt_roles), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule__exempt_channels), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_auto_moderation_rule_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_auto_moderation_rule__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_auto_moderation_rule_MAX) };






enum { REFLECTC_NS_UPPER(_LOOKUP__discord_channel__id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__type), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__position), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__permission_overwrites), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__name), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__topic), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__nsfw), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__last_message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__bitrate), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__user_limit), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__rate_limit_per_user), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__recipients), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__owner_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__managed), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__parent_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__last_pin_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__rtc_region), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__voice_quality_mode), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__message_count), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__member_count), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__thread_metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__member), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__default_auto_archive_duration), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__total_message_sent), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__available_tags), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__applied_tags), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__default_reaction_emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__default_thread_rate_limit_per_user), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__default_sort_order), REFLECTC_NS_UPPER(_LOOKUP__discord_channel__default_forum_layout), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_channels__size), REFLECTC_NS_UPPER(_LOOKUP__discord_channels__array), REFLECTC_NS_UPPER(_LOOKUP__discord_channels__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_channels_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_activity__type), REFLECTC_NS_UPPER(_LOOKUP__discord_message_activity__party_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_activity_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_reference__message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reference__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reference__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reference__fail_if_not_exists), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reference_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message__id), REFLECTC_NS_UPPER(_LOOKUP__discord_message__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message__author), REFLECTC_NS_UPPER(_LOOKUP__discord_message__member), REFLECTC_NS_UPPER(_LOOKUP__discord_message__content), REFLECTC_NS_UPPER(_LOOKUP__discord_message__timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_message__edited_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_message__tts), REFLECTC_NS_UPPER(_LOOKUP__discord_message__mention_everyone), REFLECTC_NS_UPPER(_LOOKUP__discord_message__mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_message__mention_roles), REFLECTC_NS_UPPER(_LOOKUP__discord_message__mention_channels), REFLECTC_NS_UPPER(_LOOKUP__discord_message__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_message__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_message__reactions), REFLECTC_NS_UPPER(_LOOKUP__discord_message__nonce), REFLECTC_NS_UPPER(_LOOKUP__discord_message__pinned), REFLECTC_NS_UPPER(_LOOKUP__discord_message__webhook_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message__type), REFLECTC_NS_UPPER(_LOOKUP__discord_message__activity), REFLECTC_NS_UPPER(_LOOKUP__discord_message__application), REFLECTC_NS_UPPER(_LOOKUP__discord_message__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message__message_reference), REFLECTC_NS_UPPER(_LOOKUP__discord_message__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_message__referenced_message), REFLECTC_NS_UPPER(_LOOKUP__discord_message__interaction), REFLECTC_NS_UPPER(_LOOKUP__discord_message__thread), REFLECTC_NS_UPPER(_LOOKUP__discord_message__components), REFLECTC_NS_UPPER(_LOOKUP__discord_message__sticker_items), REFLECTC_NS_UPPER(_LOOKUP__discord_message__stickers), REFLECTC_NS_UPPER(_LOOKUP__discord_message__position), REFLECTC_NS_UPPER(_LOOKUP__discord_message__role_subscription_data), REFLECTC_NS_UPPER(_LOOKUP__discord_message__resolved), REFLECTC_NS_UPPER(_LOOKUP__discord_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_messages__size), REFLECTC_NS_UPPER(_LOOKUP__discord_messages__array), REFLECTC_NS_UPPER(_LOOKUP__discord_messages__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_messages_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_followed_channel__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_followed_channel__webhook_id), REFLECTC_NS_UPPER(_LOOKUP__discord_followed_channel_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_reaction_count_details__burst), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction_count_details__normal), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction_count_details_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_reaction__count), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction__count_details), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction__me), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction__me_burst), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction__emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction__burst_colors), REFLECTC_NS_UPPER(_LOOKUP__discord_reaction_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_reactions__size), REFLECTC_NS_UPPER(_LOOKUP__discord_reactions__array), REFLECTC_NS_UPPER(_LOOKUP__discord_reactions__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_reactions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_overwrite__id), REFLECTC_NS_UPPER(_LOOKUP__discord_overwrite__type), REFLECTC_NS_UPPER(_LOOKUP__discord_overwrite__allow), REFLECTC_NS_UPPER(_LOOKUP__discord_overwrite__deny), REFLECTC_NS_UPPER(_LOOKUP__discord_overwrite_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_overwrites__size), REFLECTC_NS_UPPER(_LOOKUP__discord_overwrites__array), REFLECTC_NS_UPPER(_LOOKUP__discord_overwrites__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_overwrites_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_metadata__archived), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_metadata__auto_archive_duration), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_metadata__archive_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_metadata__locked), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_metadata__invitable), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_metadata__create_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_metadata_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_member__id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_member__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_member__join_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_member__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_member__member), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_member__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_member_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members__size), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members__array), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_default_reaction__emoji_id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_default_reaction__emoji_name), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_default_reaction_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tag__id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tag__name), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tag__moderated), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tag__emoji_id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tag__emoji_name), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tag_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tags__size), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tags__array), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tags__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_tags_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_thumbnail__url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_thumbnail__proxy_url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_thumbnail__height), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_thumbnail__width), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_thumbnail_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_video__url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_video__proxy_url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_video__height), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_video__width), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_video_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_image__url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_image__proxy_url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_image__height), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_image__width), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_image_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_provider__name), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_provider__url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_provider_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_author__name), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_author__url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_author__icon_url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_author__proxy_icon_url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_author_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_footer__text), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_footer__icon_url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_footer__proxy_icon_url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_footer_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_field__name), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_field__value), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_field__Inline), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_field_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed_fields__size), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_fields__array), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_fields__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_fields_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embed__title), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__type), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__description), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__url), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__color), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__footer), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__image), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__thumbnail), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__video), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__provider), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__author), REFLECTC_NS_UPPER(_LOOKUP__discord_embed__fields), REFLECTC_NS_UPPER(_LOOKUP__discord_embed_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_embeds__size), REFLECTC_NS_UPPER(_LOOKUP__discord_embeds__array), REFLECTC_NS_UPPER(_LOOKUP__discord_embeds__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_embeds_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__content), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__id), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__filename), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__description), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__content_type), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__size), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__url), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__proxy_url), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__height), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__width), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__ephemeral), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__duration_secs), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__waveform), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_attachment_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_attachments__size), REFLECTC_NS_UPPER(_LOOKUP__discord_attachments__array), REFLECTC_NS_UPPER(_LOOKUP__discord_attachments__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_attachments_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_channel_mention__id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_mention__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_mention__type), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_mention__name), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_mention_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_allowed_mention__parse), REFLECTC_NS_UPPER(_LOOKUP__discord_allowed_mention__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_allowed_mention__users), REFLECTC_NS_UPPER(_LOOKUP__discord_allowed_mention__replied_user), REFLECTC_NS_UPPER(_LOOKUP__discord_allowed_mention_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_role_subscription_data__role_subscription_listing_id), REFLECTC_NS_UPPER(_LOOKUP__discord_role_subscription_data__tier_name), REFLECTC_NS_UPPER(_LOOKUP__discord_role_subscription_data__total_months_subscribed), REFLECTC_NS_UPPER(_LOOKUP__discord_role_subscription_data__is_renewal), REFLECTC_NS_UPPER(_LOOKUP__discord_role_subscription_data_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_response_body__threads), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_response_body__members), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_response_body__has_more), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_response_body_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__type), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__position), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__topic), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__nsfw), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__rate_limit_per_user), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__user_limit), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__permission_overwrites), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__parent_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__rtc_region), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__video_quality_mode), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__default_auto_archive_duration), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__archived), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__auto_archive_duration), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__locked), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel__invitable), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_channel_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_channel__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_channel_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_channel_messages__around), REFLECTC_NS_UPPER(_LOOKUP__discord_get_channel_messages__before), REFLECTC_NS_UPPER(_LOOKUP__discord_get_channel_messages__after), REFLECTC_NS_UPPER(_LOOKUP__discord_get_channel_messages__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_get_channel_messages_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__content), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__tts), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__allowed_mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__message_reference), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__components), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__sticker_ids), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message__enforce_nonce), REFLECTC_NS_UPPER(_LOOKUP__discord_create_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_reactions__after), REFLECTC_NS_UPPER(_LOOKUP__discord_get_reactions__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_get_reactions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_edit_message__content), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_message__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_message__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_message__allowed_mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_message__components), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_message__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_message__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_delete_messages__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_delete_messages__messages), REFLECTC_NS_UPPER(_LOOKUP__discord_bulk_delete_messages_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_edit_channel_permissions__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_channel_permissions__allow), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_channel_permissions__deny), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_channel_permissions__type), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_channel_permissions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__max_age), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__max_uses), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__temporary), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__unique), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__target_type), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__target_user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite__target_application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_channel_invite_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_channel_permission__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_channel_permission_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_follow_news_channel__webhook_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_follow_news_channel_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_pin_message__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_pin_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_unpin_message__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_unpin_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_group_dm_add_recipient__access_token), REFLECTC_NS_UPPER(_LOOKUP__discord_group_dm_add_recipient__nick), REFLECTC_NS_UPPER(_LOOKUP__discord_group_dm_add_recipient_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_with_message__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_with_message__name), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_with_message__auto_archive_duration), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_with_message__rate_limit_per_user), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_with_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_without_message__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_without_message__name), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_without_message__auto_archive_duration), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_without_message__type), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_without_message__invitable), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_without_message__rate_limit_per_user), REFLECTC_NS_UPPER(_LOOKUP__discord_start_thread_without_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_list_active_threads__threads), REFLECTC_NS_UPPER(_LOOKUP__discord_list_active_threads__members), REFLECTC_NS_UPPER(_LOOKUP__discord_list_active_threads__has_more), REFLECTC_NS_UPPER(_LOOKUP__discord_list_active_threads_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__strings__size), REFLECTC_NS_UPPER(_LOOKUP__strings__array), REFLECTC_NS_UPPER(_LOOKUP__strings__realsize), REFLECTC_NS_UPPER(_LOOKUP__strings_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__json_values__size), REFLECTC_NS_UPPER(_LOOKUP__json_values__array), REFLECTC_NS_UPPER(_LOOKUP__json_values__realsize), REFLECTC_NS_UPPER(_LOOKUP__json_values_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__snowflakes__size), REFLECTC_NS_UPPER(_LOOKUP__snowflakes__array), REFLECTC_NS_UPPER(_LOOKUP__snowflakes__realsize), REFLECTC_NS_UPPER(_LOOKUP__snowflakes_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__bitmasks__size), REFLECTC_NS_UPPER(_LOOKUP__bitmasks__array), REFLECTC_NS_UPPER(_LOOKUP__bitmasks__realsize), REFLECTC_NS_UPPER(_LOOKUP__bitmasks_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__integers__size), REFLECTC_NS_UPPER(_LOOKUP__integers__array), REFLECTC_NS_UPPER(_LOOKUP__integers__realsize), REFLECTC_NS_UPPER(_LOOKUP__integers_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__id), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__name), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__user), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__require_colons), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__managed), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__animated), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji__available), REFLECTC_NS_UPPER(_LOOKUP__discord_emoji_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_emojis__size), REFLECTC_NS_UPPER(_LOOKUP__discord_emojis__array), REFLECTC_NS_UPPER(_LOOKUP__discord_emojis__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_emojis_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_emoji__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_emoji__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_emoji__image), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_emoji__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_emoji_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_emoji__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_emoji__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_emoji__image), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_emoji__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_emoji_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_emoji__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_emoji_MAX) };



enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity__name), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__type), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__url), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__created_at), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__timestamps), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__details), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__state), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__party), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__assets), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__secrets), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__instance), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_activity__buttons), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activities__size), REFLECTC_NS_UPPER(_LOOKUP__discord_activities__array), REFLECTC_NS_UPPER(_LOOKUP__discord_activities__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_activities_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity_timestamps__start), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_timestamps__end), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_timestamps_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity_emoji__name), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_emoji__id), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_emoji__animated), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_emoji_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity_party__id), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_party__size), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_party_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity_assets__large_image), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_assets__large_text), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_assets__small_image), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_assets__small_text), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_assets_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity_secrets__join), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_secrets__spectate), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_secrets__match), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_secrets_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity_button__label), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_button__url), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_button_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_activity_buttons__size), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_buttons__array), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_buttons__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_activity_buttons_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update__user), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update__status), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update__client_status), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update__activities), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update__since), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update__afk), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_client_status__desktop), REFLECTC_NS_UPPER(_LOOKUP__discord_client_status__mobile), REFLECTC_NS_UPPER(_LOOKUP__discord_client_status__web), REFLECTC_NS_UPPER(_LOOKUP__discord_client_status_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_presence_updates__size), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_updates__array), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_updates__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_presence_updates_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_identify__token), REFLECTC_NS_UPPER(_LOOKUP__discord_identify__properties), REFLECTC_NS_UPPER(_LOOKUP__discord_identify__compress), REFLECTC_NS_UPPER(_LOOKUP__discord_identify__large_threshold), REFLECTC_NS_UPPER(_LOOKUP__discord_identify__shard), REFLECTC_NS_UPPER(_LOOKUP__discord_identify__presence), REFLECTC_NS_UPPER(_LOOKUP__discord_identify__intents), REFLECTC_NS_UPPER(_LOOKUP__discord_identify_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_identify_connection__os), REFLECTC_NS_UPPER(_LOOKUP__discord_identify_connection__browser), REFLECTC_NS_UPPER(_LOOKUP__discord_identify_connection__device), REFLECTC_NS_UPPER(_LOOKUP__discord_identify_connection_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_resume__token), REFLECTC_NS_UPPER(_LOOKUP__discord_resume__session_id), REFLECTC_NS_UPPER(_LOOKUP__discord_resume__seq), REFLECTC_NS_UPPER(_LOOKUP__discord_resume_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_request_guild_members__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_request_guild_members__query), REFLECTC_NS_UPPER(_LOOKUP__discord_request_guild_members__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_request_guild_members__presences), REFLECTC_NS_UPPER(_LOOKUP__discord_request_guild_members__user_ids), REFLECTC_NS_UPPER(_LOOKUP__discord_request_guild_members__nonce), REFLECTC_NS_UPPER(_LOOKUP__discord_request_guild_members_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_update_voice_state__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_update_voice_state__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_update_voice_state__self_mute), REFLECTC_NS_UPPER(_LOOKUP__discord_update_voice_state__self_deaf), REFLECTC_NS_UPPER(_LOOKUP__discord_update_voice_state_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_ready__v), REFLECTC_NS_UPPER(_LOOKUP__discord_ready__user), REFLECTC_NS_UPPER(_LOOKUP__discord_ready__guilds), REFLECTC_NS_UPPER(_LOOKUP__discord_ready__session_id), REFLECTC_NS_UPPER(_LOOKUP__discord_ready__shard), REFLECTC_NS_UPPER(_LOOKUP__discord_ready__application), REFLECTC_NS_UPPER(_LOOKUP__discord_ready_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__action), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__rule_trigger_type), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__alert_system_message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__content), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__matched_keyword), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution__matched_content), REFLECTC_NS_UPPER(_LOOKUP__discord_auto_moderation_action_execution_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_list_sync__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_list_sync__channel_ids), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_list_sync__threads), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_list_sync__members), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_list_sync_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members_update__id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members_update__member_count), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members_update__added_members), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members_update__removed_member_ids), REFLECTC_NS_UPPER(_LOOKUP__discord_thread_members_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_channel_pins_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_pins_update__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_pins_update__last_pin_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_channel_pins_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_ban_add__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_ban_add__user), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_ban_add_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_ban_remove__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_ban_remove__user), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_ban_remove_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_emojis_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_emojis_update__emojis), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_emojis_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_stickers_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_stickers_update__stickers), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_stickers_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_integrations_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_integrations_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_remove__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_remove__user), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_remove_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__user), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__nick), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__avatar), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__joined_at), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__premium_since), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__deaf), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__mute), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__pending), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update__communication_disabled_until), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk__members), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk__chunk_index), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk__chunk_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk__not_found), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk__presences), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk__nonce), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_chunk_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_create__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_create__role), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_create_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_update__role), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_delete__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_delete__role_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_role_delete_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_add__guild_scheduled_event_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_add__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_add__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_add_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_remove__guild_scheduled_event_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_remove__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_remove__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_remove_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_integration_delete__id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_delete__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_delete__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_delete_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__code), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__created_at), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__inviter), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__max_age), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__max_uses), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__target_type), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__target_user), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__target_application), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__temporary), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create__uses), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_create_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_invite_delete__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_delete__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_delete__code), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_delete_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete__id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete_bulk__ids), REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete_bulk__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete_bulk__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_delete_bulk_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_add__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_add__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_add__message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_add__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_add__member), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_add__emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_add_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove__message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove__emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_all__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_all__message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_all__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_all_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_emoji__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_emoji__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_emoji__message_id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_emoji__emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_message_reaction_remove_emoji_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_typing_start__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_typing_start__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_typing_start__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_typing_start__timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_typing_start__member), REFLECTC_NS_UPPER(_LOOKUP__discord_typing_start_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_voice_server_update__token), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_server_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_server_update__endpoint), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_server_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_webhooks_update__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_webhooks_update__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_webhooks_update_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_session_start_limit__total), REFLECTC_NS_UPPER(_LOOKUP__discord_session_start_limit__remaining), REFLECTC_NS_UPPER(_LOOKUP__discord_session_start_limit__reset_after), REFLECTC_NS_UPPER(_LOOKUP__discord_session_start_limit__max_concurrency), REFLECTC_NS_UPPER(_LOOKUP__discord_session_start_limit_MAX) };







enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild__id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__name), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__icon_hash), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__splash), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__discovery_splash), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__owner), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__owner_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__afk_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__afk_timeout), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__widget_enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__widget_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__verification_level), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__default_message_notifications), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__explicit_content_filter), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__emojis), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__features), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__mfa_level), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__system_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__system_channel_flags), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__rules_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__joined_at), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__large), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__unavailable), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__member_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__voice_states), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__members), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__channels), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__threads), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__presences), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__max_presences), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__max_members), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__vanity_url_code), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__description), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__banner), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__premium_tier), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__premium_subscription_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__preferred_locale), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__public_updates_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__max_video_channel_users), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__approximate_member_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__approximate_presence_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__welcome_screen), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__nsfw_level), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__stage_instances), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__stickers), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__guild_scheduled_events), REFLECTC_NS_UPPER(_LOOKUP__discord_guild__premium_progress_bar_enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guilds__size), REFLECTC_NS_UPPER(_LOOKUP__discord_guilds__array), REFLECTC_NS_UPPER(_LOOKUP__discord_guilds__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_guilds_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__name), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__splash), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__discovery_splash), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__emojis), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__features), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__approximate_member_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__approximate_presence_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__description), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview__stickers), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_preview_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget_settings__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget_settings__enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget_settings__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget_settings_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget__id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget__name), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget__instant_invite), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget__channels), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget__members), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget__presence_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_widget_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__user), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__nick), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__avatar), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__joined_at), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__premium_since), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__deaf), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__muted), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__pending), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__communication_disabled_until), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_member_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members__size), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members__array), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_members_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_integration__id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__name), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__type), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__syncing), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__role_id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__enable_emoticons), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__expire_behavior), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__expire_grace_period), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__user), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__account), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__synced_at), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__subscriber_count), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__revoked), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__application), REFLECTC_NS_UPPER(_LOOKUP__discord_integration__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_integrations__size), REFLECTC_NS_UPPER(_LOOKUP__discord_integrations__array), REFLECTC_NS_UPPER(_LOOKUP__discord_integrations__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_integrations_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_integration_account__id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_account__name), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_account_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_integration_application__id), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_application__name), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_application__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_application__description), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_application__summary), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_application__bot), REFLECTC_NS_UPPER(_LOOKUP__discord_integration_application_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_ban__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_ban__user), REFLECTC_NS_UPPER(_LOOKUP__discord_ban_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_bans__size), REFLECTC_NS_UPPER(_LOOKUP__discord_bans__array), REFLECTC_NS_UPPER(_LOOKUP__discord_bans__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_bans_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen__description), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen__welcome_channels), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channel__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channel__description), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channel__emoji_id), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channel__emoji_name), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channel_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channels__size), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channels__array), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channels__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_welcome_screen_channels_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_prune_count__pruned), REFLECTC_NS_UPPER(_LOOKUP__discord_prune_count_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__region), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__verification_level), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__default_message_notifications), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__explicit_content_filter), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__channels), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__afk_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__afk_timeout), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__system_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild__system_channel_flags), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__verification_level), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__default_message_notifications), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__explicit_content_filter), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__afk_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__afk_timeout), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__owner_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__splash), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__discovery_splash), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__banner), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__system_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__system_channel_flags), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__rules_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__public_updates_channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__preferred_locale), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__features), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__description), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild__premium_progress_bar_enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__type), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__topic), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__bitrate), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__user_limit), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__rate_limit_per_user), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__position), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__permission_overwrites), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__parent_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel__nsfw), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_channel_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_position__id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_position__position), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_position__lock_category), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_position__parent_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_position_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_positions__size), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_positions__array), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_positions__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_channel_positions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_list_active_guild_threads__threads), REFLECTC_NS_UPPER(_LOOKUP__discord_list_active_guild_threads__members), REFLECTC_NS_UPPER(_LOOKUP__discord_list_active_guild_threads_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_list_guild_members__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_list_guild_members__after), REFLECTC_NS_UPPER(_LOOKUP__discord_list_guild_members_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_search_guild_members__query), REFLECTC_NS_UPPER(_LOOKUP__discord_search_guild_members__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_search_guild_members_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member__access_token), REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member__nick), REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member__mute), REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member__deaf), REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member__nick), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member__mute), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member__deaf), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member__communication_disabled_until), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_member_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_member__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_member__nick), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_member_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_nick__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_nick__nick), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_nick_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member_role__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_add_guild_member_role_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_remove_guild_member_role__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_remove_guild_member_role_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_remove_guild_member__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_remove_guild_member_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_ban__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_ban__delete_message_days), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_ban_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_remove_guild_ban__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_remove_guild_ban_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__color), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__hoist), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__unicode_emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role__mentionable), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_role_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_position__id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_position__position), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_position_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_positions__size), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_positions__array), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_positions__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_positions_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__color), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__hoist), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__unicode_emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role__mentionable), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_role_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_role__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_role_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_prune_count__days), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_prune_count__include_roles), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_prune_count_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_begin_guild_prune__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_begin_guild_prune__days), REFLECTC_NS_UPPER(_LOOKUP__discord_begin_guild_prune__compute_prune_count), REFLECTC_NS_UPPER(_LOOKUP__discord_begin_guild_prune__include_roles), REFLECTC_NS_UPPER(_LOOKUP__discord_begin_guild_prune_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_integrations__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_integrations__days), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_integrations__include_roles), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_integrations_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_widget_image__style), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_widget_image_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_welcome_screen__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_welcome_screen__enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_welcome_screen__welcome_channels), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_welcome_screen__description), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_welcome_screen_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_voice_state__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_voice_state__suppress), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_voice_state__request_to_speak_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_voice_state_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_user_voice_state__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_user_voice_state__suppress), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_user_voice_state_MAX) };



enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__creator_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__name), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__description), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__scheduled_start_time), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__scheduled_end_time), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__privacy_level), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__status), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__entity_type), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__entity_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__entity_metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__creator), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__user_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event__image), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_entity_metadata__location), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_entity_metadata_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_events__size), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_events__array), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_events__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_events_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user__guild_scheduled_event_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user__user), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user__member), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_user_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_users__size), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_users__array), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_users__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_scheduled_event_users_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_list_guild_scheduled_events__with_user_count), REFLECTC_NS_UPPER(_LOOKUP__discord_list_guild_scheduled_events_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__entity_metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__privacy_level), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__scheduled_start_time), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__scheduled_end_time), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__description), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__entity_type), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event__image), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_scheduled_event_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_scheduled_event__with_user_count), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_scheduled_event_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__entity_metadata), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__scheduled_start_time), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__scheduled_end_time), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__description), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__entity_type), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__status), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event__image), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_scheduled_event_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_scheduled_event_users__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_scheduled_event_users__with_member), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_scheduled_event_users__before), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_scheduled_event_users__after), REFLECTC_NS_UPPER(_LOOKUP__discord_get_guild_scheduled_event_users_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__code), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__name), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__description), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__usage_count), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__creator_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__creator), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__created_at), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__updated_at), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__source_guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__serialized_source_guild), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template__is_dirty), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_template_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_guild_templates__size), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_templates__array), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_templates__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_guild_templates_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_from_guild_template__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_from_guild_template__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_from_guild_template_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_template__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_template__description), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_template_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_template__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_template__description), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_template_MAX) };


enum { REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__type), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__data), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__member), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__user), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__token), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__version), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__message), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__locale), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction__guild_locale), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__name), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__type), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__resolved), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__options), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__custom_id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__component_type), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__values), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__target_id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data__components), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_data_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_resolved_data__users), REFLECTC_NS_UPPER(_LOOKUP__discord_resolved_data__members), REFLECTC_NS_UPPER(_LOOKUP__discord_resolved_data__roles), REFLECTC_NS_UPPER(_LOOKUP__discord_resolved_data__channels), REFLECTC_NS_UPPER(_LOOKUP__discord_resolved_data__messages), REFLECTC_NS_UPPER(_LOOKUP__discord_resolved_data__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_resolved_data_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_message_interaction__id), REFLECTC_NS_UPPER(_LOOKUP__discord_message_interaction__type), REFLECTC_NS_UPPER(_LOOKUP__discord_message_interaction__name), REFLECTC_NS_UPPER(_LOOKUP__discord_message_interaction__user), REFLECTC_NS_UPPER(_LOOKUP__discord_message_interaction__member), REFLECTC_NS_UPPER(_LOOKUP__discord_message_interaction_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_response__type), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_response__data), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_response_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__components), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__tts), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__content), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__choices), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__custom_id), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data__title), REFLECTC_NS_UPPER(_LOOKUP__discord_interaction_callback_data_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_edit_original_interaction_response__thread_id), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_original_interaction_response__content), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_original_interaction_response__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_original_interaction_response__allowed_mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_original_interaction_response__components), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_original_interaction_response__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_original_interaction_response_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__wait), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__thread_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__avatar_url), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__tts), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__allowed_mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__components), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_create_followup_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_edit_followup_message__thread_id), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_followup_message__content), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_followup_message__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_followup_message__allowed_mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_followup_message__components), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_followup_message__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_followup_message_MAX) };

enum { REFLECTC_NS_UPPER(_LOOKUP__discord_invite__code), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__guild), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__channel), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__inviter), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__target_type), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__target_user), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__target_application), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__approximate_presence_count), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__approximate_member_count), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__expires_at), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__stage_instance), REFLECTC_NS_UPPER(_LOOKUP__discord_invite__guild_scheduled_event), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_invites__size), REFLECTC_NS_UPPER(_LOOKUP__discord_invites__array), REFLECTC_NS_UPPER(_LOOKUP__discord_invites__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_invites_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_invite_metadata__uses), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_metadata__max_uses), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_metadata__max_age), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_metadata__temporary), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_metadata__created_at), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_metadata_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_invite_stage_instance__members), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_stage_instance__participant_count), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_stage_instance__speaker_count), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_stage_instance__topic), REFLECTC_NS_UPPER(_LOOKUP__discord_invite_stage_instance_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_invite__with_counts), REFLECTC_NS_UPPER(_LOOKUP__discord_get_invite__with_expiration), REFLECTC_NS_UPPER(_LOOKUP__discord_get_invite__guild_scheduled_event_id), REFLECTC_NS_UPPER(_LOOKUP__discord_get_invite_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_invite__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_invite_MAX) };



enum { REFLECTC_NS_UPPER(_LOOKUP__discord_component__id), REFLECTC_NS_UPPER(_LOOKUP__discord_component__type), REFLECTC_NS_UPPER(_LOOKUP__discord_component__custom_id), REFLECTC_NS_UPPER(_LOOKUP__discord_component__sku_id), REFLECTC_NS_UPPER(_LOOKUP__discord_component__style), REFLECTC_NS_UPPER(_LOOKUP__discord_component__label), REFLECTC_NS_UPPER(_LOOKUP__discord_component__emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_component__url), REFLECTC_NS_UPPER(_LOOKUP__discord_component__options), REFLECTC_NS_UPPER(_LOOKUP__discord_component__placeholder), REFLECTC_NS_UPPER(_LOOKUP__discord_component__min_values), REFLECTC_NS_UPPER(_LOOKUP__discord_component__max_values), REFLECTC_NS_UPPER(_LOOKUP__discord_component__components), REFLECTC_NS_UPPER(_LOOKUP__discord_component__min_length), REFLECTC_NS_UPPER(_LOOKUP__discord_component__max_length), REFLECTC_NS_UPPER(_LOOKUP__discord_component__required), REFLECTC_NS_UPPER(_LOOKUP__discord_component__value), REFLECTC_NS_UPPER(_LOOKUP__discord_component_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_components__size), REFLECTC_NS_UPPER(_LOOKUP__discord_components__array), REFLECTC_NS_UPPER(_LOOKUP__discord_components__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_components_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_select_option__label), REFLECTC_NS_UPPER(_LOOKUP__discord_select_option__value), REFLECTC_NS_UPPER(_LOOKUP__discord_select_option__description), REFLECTC_NS_UPPER(_LOOKUP__discord_select_option__emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_select_option__Default), REFLECTC_NS_UPPER(_LOOKUP__discord_select_option_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_select_options__size), REFLECTC_NS_UPPER(_LOOKUP__discord_select_options__array), REFLECTC_NS_UPPER(_LOOKUP__discord_select_options__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_select_options_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_component_media__url), REFLECTC_NS_UPPER(_LOOKUP__discord_component_media_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_component_item__media), REFLECTC_NS_UPPER(_LOOKUP__discord_component_item__description), REFLECTC_NS_UPPER(_LOOKUP__discord_component_item__spoiler), REFLECTC_NS_UPPER(_LOOKUP__discord_component_item_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_component_items__size), REFLECTC_NS_UPPER(_LOOKUP__discord_component_items__array), REFLECTC_NS_UPPER(_LOOKUP__discord_component_items__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_component_items_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_auth_response__application), REFLECTC_NS_UPPER(_LOOKUP__discord_auth_response__scopes), REFLECTC_NS_UPPER(_LOOKUP__discord_auth_response__expires), REFLECTC_NS_UPPER(_LOOKUP__discord_auth_response__user), REFLECTC_NS_UPPER(_LOOKUP__discord_auth_response_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_role__id), REFLECTC_NS_UPPER(_LOOKUP__discord_role__name), REFLECTC_NS_UPPER(_LOOKUP__discord_role__color), REFLECTC_NS_UPPER(_LOOKUP__discord_role__hoist), REFLECTC_NS_UPPER(_LOOKUP__discord_role__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_role__unicode_emoji), REFLECTC_NS_UPPER(_LOOKUP__discord_role__position), REFLECTC_NS_UPPER(_LOOKUP__discord_role__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_role__managed), REFLECTC_NS_UPPER(_LOOKUP__discord_role__mentionable), REFLECTC_NS_UPPER(_LOOKUP__discord_role__tags), REFLECTC_NS_UPPER(_LOOKUP__discord_role_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_roles__size), REFLECTC_NS_UPPER(_LOOKUP__discord_roles__array), REFLECTC_NS_UPPER(_LOOKUP__discord_roles__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_roles_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_role_tag__bot_id), REFLECTC_NS_UPPER(_LOOKUP__discord_role_tag__integration_id), REFLECTC_NS_UPPER(_LOOKUP__discord_role_tag__premium_subscribe), REFLECTC_NS_UPPER(_LOOKUP__discord_role_tag_MAX) };

enum { REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instance__id), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instance__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instance__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instance__topic), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instance__privacy_level), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instance__discoverable_disabled), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instance_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instances__size), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instances__array), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instances__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_stage_instances_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_stage_instance__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_stage_instance__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_stage_instance__topic), REFLECTC_NS_UPPER(_LOOKUP__discord_create_stage_instance__privacy_level), REFLECTC_NS_UPPER(_LOOKUP__discord_create_stage_instance_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_stage_instance__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_stage_instance__topic), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_stage_instance__privacy_level), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_stage_instance_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_stage_instance__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_stage_instance_MAX) };


enum { REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__pack_id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__name), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__description), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__tags), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__type), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__format_type), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__available), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__user), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker__sort_value), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_stickers__size), REFLECTC_NS_UPPER(_LOOKUP__discord_stickers__array), REFLECTC_NS_UPPER(_LOOKUP__discord_stickers__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_stickers_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_item__id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_item__name), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_item__format_type), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_item_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_items__size), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_items__array), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_items__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_items_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack__id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack__stickers), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack__name), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack__sku_id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack__cover_sticker_id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack__description), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack__banner_asset_id), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_pack_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_packs__size), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_packs__array), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_packs__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_sticker_packs_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_list_nitro_sticker_packs__sticker_packs), REFLECTC_NS_UPPER(_LOOKUP__discord_list_nitro_sticker_packs_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_sticker__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_sticker__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_sticker__description), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_sticker__tags), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_sticker__file), REFLECTC_NS_UPPER(_LOOKUP__discord_create_guild_sticker_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_sticker__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_sticker__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_sticker__description), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_sticker__tags), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_guild_sticker_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_sticker__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_guild_sticker_MAX) };

enum { REFLECTC_NS_UPPER(_LOOKUP__discord_team__icon), REFLECTC_NS_UPPER(_LOOKUP__discord_team__id), REFLECTC_NS_UPPER(_LOOKUP__discord_team__members), REFLECTC_NS_UPPER(_LOOKUP__discord_team__name), REFLECTC_NS_UPPER(_LOOKUP__discord_team__owner_user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_team_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_team_member__membership_state), REFLECTC_NS_UPPER(_LOOKUP__discord_team_member__permissions), REFLECTC_NS_UPPER(_LOOKUP__discord_team_member__team_id), REFLECTC_NS_UPPER(_LOOKUP__discord_team_member__user), REFLECTC_NS_UPPER(_LOOKUP__discord_team_member_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_team_members__size), REFLECTC_NS_UPPER(_LOOKUP__discord_team_members__array), REFLECTC_NS_UPPER(_LOOKUP__discord_team_members__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_team_members_MAX) };


enum { REFLECTC_NS_UPPER(_LOOKUP__discord_user__id), REFLECTC_NS_UPPER(_LOOKUP__discord_user__username), REFLECTC_NS_UPPER(_LOOKUP__discord_user__discriminator), REFLECTC_NS_UPPER(_LOOKUP__discord_user__avatar), REFLECTC_NS_UPPER(_LOOKUP__discord_user__bot), REFLECTC_NS_UPPER(_LOOKUP__discord_user__System), REFLECTC_NS_UPPER(_LOOKUP__discord_user__mfa_enabled), REFLECTC_NS_UPPER(_LOOKUP__discord_user__banner), REFLECTC_NS_UPPER(_LOOKUP__discord_user__accent_color), REFLECTC_NS_UPPER(_LOOKUP__discord_user__locale), REFLECTC_NS_UPPER(_LOOKUP__discord_user__verified), REFLECTC_NS_UPPER(_LOOKUP__discord_user__email), REFLECTC_NS_UPPER(_LOOKUP__discord_user__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_user__premium_type), REFLECTC_NS_UPPER(_LOOKUP__discord_user__public_flags), REFLECTC_NS_UPPER(_LOOKUP__discord_user_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_users__size), REFLECTC_NS_UPPER(_LOOKUP__discord_users__array), REFLECTC_NS_UPPER(_LOOKUP__discord_users__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_users_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_connection__id), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__name), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__type), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__revoked), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__integrations), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__verified), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__friend_sync), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__show_activity), REFLECTC_NS_UPPER(_LOOKUP__discord_connection__visibility), REFLECTC_NS_UPPER(_LOOKUP__discord_connection_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_connections__size), REFLECTC_NS_UPPER(_LOOKUP__discord_connections__array), REFLECTC_NS_UPPER(_LOOKUP__discord_connections__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_connections_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user__username), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user__avatar), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_current_user_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_current_user_guilds__before), REFLECTC_NS_UPPER(_LOOKUP__discord_get_current_user_guilds__after), REFLECTC_NS_UPPER(_LOOKUP__discord_get_current_user_guilds__limit), REFLECTC_NS_UPPER(_LOOKUP__discord_get_current_user_guilds_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_dm__recipient_id), REFLECTC_NS_UPPER(_LOOKUP__discord_create_dm_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_group_dm__access_tokens), REFLECTC_NS_UPPER(_LOOKUP__discord_create_group_dm__nicks), REFLECTC_NS_UPPER(_LOOKUP__discord_create_group_dm_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__user_id), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__member), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__session_id), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__deaf), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__mute), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__self_deaf), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__self_mute), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__self_stream), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__self_video), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__suppress), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state__request_to_speak_timestamp), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_state_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_voice_states__size), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_states__array), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_states__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_states_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_voice_region__id), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_region__name), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_region__optimal), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_region__deprecated), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_region__custom), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_region_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_voice_regions__size), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_regions__array), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_regions__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_voice_regions_MAX) };



enum { REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__id), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__type), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__guild_id), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__user), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__name), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__token), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__application_id), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__source_channel), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook__url), REFLECTC_NS_UPPER(_LOOKUP__discord_webhook_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_webhooks__size), REFLECTC_NS_UPPER(_LOOKUP__discord_webhooks__array), REFLECTC_NS_UPPER(_LOOKUP__discord_webhooks__realsize), REFLECTC_NS_UPPER(_LOOKUP__discord_webhooks_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_create_webhook__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_create_webhook__name), REFLECTC_NS_UPPER(_LOOKUP__discord_create_webhook__avatar), REFLECTC_NS_UPPER(_LOOKUP__discord_create_webhook_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook__avatar), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook__channel_id), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_webhook__reason), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_webhook_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook_with_token__name), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook_with_token__avatar), REFLECTC_NS_UPPER(_LOOKUP__discord_modify_webhook_with_token_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__wait), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__thread_id), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__content), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__username), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__avatar_url), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__tts), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__allowed_mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__components), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook__flags), REFLECTC_NS_UPPER(_LOOKUP__discord_execute_webhook_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_get_webhook_message__thread_id), REFLECTC_NS_UPPER(_LOOKUP__discord_get_webhook_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_edit_webhook_message__thread_id), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_webhook_message__content), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_webhook_message__embeds), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_webhook_message__allowed_mentions), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_webhook_message__components), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_webhook_message__attachments), REFLECTC_NS_UPPER(_LOOKUP__discord_edit_webhook_message_MAX) };
enum { REFLECTC_NS_UPPER(_LOOKUP__discord_delete_webhook_message__thread_id), REFLECTC_NS_UPPER(_LOOKUP__discord_delete_webhook_message_MAX) };














































































































#define reflectc_wrap(_symbol)        reflectc_wrap

enum {
    REFLECTC_TYPES(u64unix_ms) = REFLECTC_TYPES(EXTEND),
    REFLECTC_TYPES(u64snowflake),
    REFLECTC_TYPES(u64bitmask),
    REFLECTC_TYPES(json_char),
    REFLECTC_TYPES(size_t)
};



















































































































































































































#undef _

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_application)( struct REFLECTC_PREFIX *registry, struct discord_application *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_install_params)( struct REFLECTC_PREFIX *registry, struct discord_install_params *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_application_command)( struct REFLECTC_PREFIX *registry, struct discord_application_command *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_application_commands)( struct REFLECTC_PREFIX *registry, struct discord_application_commands *self, struct REFLECTC_NS(_wrap) *root);







struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_application_command_permissions)( struct REFLECTC_PREFIX *registry, struct discord_guild_application_command_permissions *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_application_command_permission)( struct REFLECTC_PREFIX *registry, struct discord_application_command_permission *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_application_command_permissions)( struct REFLECTC_PREFIX *registry, struct discord_application_command_permissions *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_global_application_command)( struct REFLECTC_PREFIX *registry, struct discord_create_global_application_command *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_edit_global_application_command)( struct REFLECTC_PREFIX *registry, struct discord_edit_global_application_command *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_application_command)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_application_command *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_edit_guild_application_command)( struct REFLECTC_PREFIX *registry, struct discord_edit_guild_application_command *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_bulk_overwrite_guild_application_command)( struct REFLECTC_PREFIX *registry, struct discord_bulk_overwrite_guild_application_command *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_bulk_overwrite_guild_application_commands)( struct REFLECTC_PREFIX *registry, struct discord_bulk_overwrite_guild_application_commands *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_audit_log)( struct REFLECTC_PREFIX *registry, struct discord_audit_log *self, struct REFLECTC_NS(_wrap) *root);















struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_auto_moderation_rule)( struct REFLECTC_PREFIX *registry, struct discord_auto_moderation_rule *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_auto_moderation_rules)( struct REFLECTC_PREFIX *registry, struct discord_auto_moderation_rules *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_auto_moderation_rule)( struct REFLECTC_PREFIX *registry, struct discord_create_auto_moderation_rule *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_auto_moderation_rule)( struct REFLECTC_PREFIX *registry, struct discord_modify_auto_moderation_rule *self, struct REFLECTC_NS(_wrap) *root);







struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_channel)( struct REFLECTC_PREFIX *registry, struct discord_channel *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_channels)( struct REFLECTC_PREFIX *registry, struct discord_channels *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_message)( struct REFLECTC_PREFIX *registry, struct discord_message *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_messages)( struct REFLECTC_PREFIX *registry, struct discord_messages *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_followed_channel)( struct REFLECTC_PREFIX *registry, struct discord_followed_channel *self, struct REFLECTC_NS(_wrap) *root);






struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_thread_member)( struct REFLECTC_PREFIX *registry, struct discord_thread_member *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_thread_members)( struct REFLECTC_PREFIX *registry, struct discord_thread_members *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_thread_tags)( struct REFLECTC_PREFIX *registry, struct discord_thread_tags *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_thumbnail)( struct REFLECTC_PREFIX *registry, struct discord_embed_thumbnail *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_video)( struct REFLECTC_PREFIX *registry, struct discord_embed_video *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_image)( struct REFLECTC_PREFIX *registry, struct discord_embed_image *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_provider)( struct REFLECTC_PREFIX *registry, struct discord_embed_provider *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_author)( struct REFLECTC_PREFIX *registry, struct discord_embed_author *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_footer)( struct REFLECTC_PREFIX *registry, struct discord_embed_footer *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_field)( struct REFLECTC_PREFIX *registry, struct discord_embed_field *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed_fields)( struct REFLECTC_PREFIX *registry, struct discord_embed_fields *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embed)( struct REFLECTC_PREFIX *registry, struct discord_embed *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_embeds)( struct REFLECTC_PREFIX *registry, struct discord_embeds *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_attachments)( struct REFLECTC_PREFIX *registry, struct discord_attachments *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_thread_response_body)( struct REFLECTC_PREFIX *registry, struct discord_thread_response_body *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_channel)( struct REFLECTC_PREFIX *registry, struct discord_modify_channel *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_message)( struct REFLECTC_PREFIX *registry, struct discord_create_message *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_edit_message)( struct REFLECTC_PREFIX *registry, struct discord_edit_message *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_bulk_delete_messages)( struct REFLECTC_PREFIX *registry, struct discord_bulk_delete_messages *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_edit_channel_permissions)( struct REFLECTC_PREFIX *registry, struct discord_edit_channel_permissions *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_channel_invite)( struct REFLECTC_PREFIX *registry, struct discord_create_channel_invite *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_follow_news_channel)( struct REFLECTC_PREFIX *registry, struct discord_follow_news_channel *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_group_dm_add_recipient)( struct REFLECTC_PREFIX *registry, struct discord_group_dm_add_recipient *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_start_thread_with_message)( struct REFLECTC_PREFIX *registry, struct discord_start_thread_with_message *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_start_thread_without_message)( struct REFLECTC_PREFIX *registry, struct discord_start_thread_without_message *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_list_active_threads)( struct REFLECTC_PREFIX *registry, struct discord_list_active_threads *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_strings)( struct REFLECTC_PREFIX *registry, struct strings *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_json_values)( struct REFLECTC_PREFIX *registry, struct json_values *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_snowflakes)( struct REFLECTC_PREFIX *registry, struct snowflakes *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_bitmasks)( struct REFLECTC_PREFIX *registry, struct bitmasks *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_integers)( struct REFLECTC_PREFIX *registry, struct integers *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_emoji)( struct REFLECTC_PREFIX *registry, struct discord_emoji *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_emojis)( struct REFLECTC_PREFIX *registry, struct discord_emojis *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_emoji)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_emoji *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_emoji)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_emoji *self, struct REFLECTC_NS(_wrap) *root);













struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_presence_update)( struct REFLECTC_PREFIX *registry, struct discord_presence_update *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_identify)( struct REFLECTC_PREFIX *registry, struct discord_identify *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_resume)( struct REFLECTC_PREFIX *registry, struct discord_resume *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_request_guild_members)( struct REFLECTC_PREFIX *registry, struct discord_request_guild_members *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_update_voice_state)( struct REFLECTC_PREFIX *registry, struct discord_update_voice_state *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_ready)( struct REFLECTC_PREFIX *registry, struct discord_ready *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_auto_moderation_action_execution)( struct REFLECTC_PREFIX *registry, struct discord_auto_moderation_action_execution *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_thread_list_sync)( struct REFLECTC_PREFIX *registry, struct discord_thread_list_sync *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_thread_members_update)( struct REFLECTC_PREFIX *registry, struct discord_thread_members_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_channel_pins_update)( struct REFLECTC_PREFIX *registry, struct discord_channel_pins_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_ban_add)( struct REFLECTC_PREFIX *registry, struct discord_guild_ban_add *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_ban_remove)( struct REFLECTC_PREFIX *registry, struct discord_guild_ban_remove *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_emojis_update)( struct REFLECTC_PREFIX *registry, struct discord_guild_emojis_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_stickers_update)( struct REFLECTC_PREFIX *registry, struct discord_guild_stickers_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_integrations_update)( struct REFLECTC_PREFIX *registry, struct discord_guild_integrations_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_member_remove)( struct REFLECTC_PREFIX *registry, struct discord_guild_member_remove *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_member_update)( struct REFLECTC_PREFIX *registry, struct discord_guild_member_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_members_chunk)( struct REFLECTC_PREFIX *registry, struct discord_guild_members_chunk *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_role_create)( struct REFLECTC_PREFIX *registry, struct discord_guild_role_create *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_role_update)( struct REFLECTC_PREFIX *registry, struct discord_guild_role_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_role_delete)( struct REFLECTC_PREFIX *registry, struct discord_guild_role_delete *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_scheduled_event_user_add)( struct REFLECTC_PREFIX *registry, struct discord_guild_scheduled_event_user_add *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_scheduled_event_user_remove)( struct REFLECTC_PREFIX *registry, struct discord_guild_scheduled_event_user_remove *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_integration_delete)( struct REFLECTC_PREFIX *registry, struct discord_integration_delete *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_invite_create)( struct REFLECTC_PREFIX *registry, struct discord_invite_create *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_invite_delete)( struct REFLECTC_PREFIX *registry, struct discord_invite_delete *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_message_delete)( struct REFLECTC_PREFIX *registry, struct discord_message_delete *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_message_delete_bulk)( struct REFLECTC_PREFIX *registry, struct discord_message_delete_bulk *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_message_reaction_add)( struct REFLECTC_PREFIX *registry, struct discord_message_reaction_add *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_message_reaction_remove)( struct REFLECTC_PREFIX *registry, struct discord_message_reaction_remove *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_message_reaction_remove_all)( struct REFLECTC_PREFIX *registry, struct discord_message_reaction_remove_all *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_message_reaction_remove_emoji)( struct REFLECTC_PREFIX *registry, struct discord_message_reaction_remove_emoji *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_typing_start)( struct REFLECTC_PREFIX *registry, struct discord_typing_start *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_voice_server_update)( struct REFLECTC_PREFIX *registry, struct discord_voice_server_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_webhooks_update)( struct REFLECTC_PREFIX *registry, struct discord_webhooks_update *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_session_start_limit)( struct REFLECTC_PREFIX *registry, struct discord_session_start_limit *self, struct REFLECTC_NS(_wrap) *root);







struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild)( struct REFLECTC_PREFIX *registry, struct discord_guild *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guilds)( struct REFLECTC_PREFIX *registry, struct discord_guilds *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_preview)( struct REFLECTC_PREFIX *registry, struct discord_guild_preview *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_widget_settings)( struct REFLECTC_PREFIX *registry, struct discord_guild_widget_settings *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_widget)( struct REFLECTC_PREFIX *registry, struct discord_guild_widget *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_member)( struct REFLECTC_PREFIX *registry, struct discord_guild_member *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_members)( struct REFLECTC_PREFIX *registry, struct discord_guild_members *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_integration)( struct REFLECTC_PREFIX *registry, struct discord_integration *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_integrations)( struct REFLECTC_PREFIX *registry, struct discord_integrations *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_ban)( struct REFLECTC_PREFIX *registry, struct discord_ban *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_bans)( struct REFLECTC_PREFIX *registry, struct discord_bans *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_welcome_screen)( struct REFLECTC_PREFIX *registry, struct discord_welcome_screen *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_prune_count)( struct REFLECTC_PREFIX *registry, struct discord_prune_count *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild)( struct REFLECTC_PREFIX *registry, struct discord_create_guild *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_channel)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_channel *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_channel_positions)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_channel_positions *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_list_active_guild_threads)( struct REFLECTC_PREFIX *registry, struct discord_list_active_guild_threads *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_add_guild_member)( struct REFLECTC_PREFIX *registry, struct discord_add_guild_member *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_member)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_member *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_current_member)( struct REFLECTC_PREFIX *registry, struct discord_modify_current_member *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_current_user_nick)( struct REFLECTC_PREFIX *registry, struct discord_modify_current_user_nick *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_ban)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_ban *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_role)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_role *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_role_positions)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_role_positions *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_role)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_role *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_begin_guild_prune)( struct REFLECTC_PREFIX *registry, struct discord_begin_guild_prune *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_welcome_screen)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_welcome_screen *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_current_user_voice_state)( struct REFLECTC_PREFIX *registry, struct discord_modify_current_user_voice_state *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_user_voice_state)( struct REFLECTC_PREFIX *registry, struct discord_modify_user_voice_state *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_scheduled_event)( struct REFLECTC_PREFIX *registry, struct discord_guild_scheduled_event *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_scheduled_events)( struct REFLECTC_PREFIX *registry, struct discord_guild_scheduled_events *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_scheduled_event_users)( struct REFLECTC_PREFIX *registry, struct discord_guild_scheduled_event_users *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_scheduled_event)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_scheduled_event *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_scheduled_event)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_scheduled_event *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_template)( struct REFLECTC_PREFIX *registry, struct discord_guild_template *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_guild_templates)( struct REFLECTC_PREFIX *registry, struct discord_guild_templates *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_from_guild_template)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_from_guild_template *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_guild_template)( struct REFLECTC_PREFIX *registry, struct discord_create_guild_template *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_template)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_template *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_interaction)( struct REFLECTC_PREFIX *registry, struct discord_interaction *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_interaction_response)( struct REFLECTC_PREFIX *registry, struct discord_interaction_response *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_edit_original_interaction_response)( struct REFLECTC_PREFIX *registry, struct discord_edit_original_interaction_response *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_followup_message)( struct REFLECTC_PREFIX *registry, struct discord_create_followup_message *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_edit_followup_message)( struct REFLECTC_PREFIX *registry, struct discord_edit_followup_message *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_invite)( struct REFLECTC_PREFIX *registry, struct discord_invite *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_invites)( struct REFLECTC_PREFIX *registry, struct discord_invites *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_get_invite)( struct REFLECTC_PREFIX *registry, struct discord_get_invite *self, struct REFLECTC_NS(_wrap) *root);




struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_component)( struct REFLECTC_PREFIX *registry, struct discord_component *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_components)( struct REFLECTC_PREFIX *registry, struct discord_components *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_select_options)( struct REFLECTC_PREFIX *registry, struct discord_select_options *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_component_items)( struct REFLECTC_PREFIX *registry, struct discord_component_items *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_auth_response)( struct REFLECTC_PREFIX *registry, struct discord_auth_response *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_role)( struct REFLECTC_PREFIX *registry, struct discord_role *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_roles)( struct REFLECTC_PREFIX *registry, struct discord_roles *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_stage_instance)( struct REFLECTC_PREFIX *registry, struct discord_stage_instance *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_stage_instance)( struct REFLECTC_PREFIX *registry, struct discord_create_stage_instance *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_stage_instance)( struct REFLECTC_PREFIX *registry, struct discord_modify_stage_instance *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_sticker)( struct REFLECTC_PREFIX *registry, struct discord_sticker *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_stickers)( struct REFLECTC_PREFIX *registry, struct discord_stickers *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_sticker_packs)( struct REFLECTC_PREFIX *registry, struct discord_sticker_packs *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_list_nitro_sticker_packs)( struct REFLECTC_PREFIX *registry, struct discord_list_nitro_sticker_packs *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_guild_sticker)( struct REFLECTC_PREFIX *registry, struct discord_modify_guild_sticker *self, struct REFLECTC_NS(_wrap) *root);


struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_team)( struct REFLECTC_PREFIX *registry, struct discord_team *self, struct REFLECTC_NS(_wrap) *root);




struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_user)( struct REFLECTC_PREFIX *registry, struct discord_user *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_users)( struct REFLECTC_PREFIX *registry, struct discord_users *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_connections)( struct REFLECTC_PREFIX *registry, struct discord_connections *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_current_user)( struct REFLECTC_PREFIX *registry, struct discord_modify_current_user *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_dm)( struct REFLECTC_PREFIX *registry, struct discord_create_dm *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_group_dm)( struct REFLECTC_PREFIX *registry, struct discord_create_group_dm *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_voice_state)( struct REFLECTC_PREFIX *registry, struct discord_voice_state *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_voice_states)( struct REFLECTC_PREFIX *registry, struct discord_voice_states *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_voice_regions)( struct REFLECTC_PREFIX *registry, struct discord_voice_regions *self, struct REFLECTC_NS(_wrap) *root);



struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_webhook)( struct REFLECTC_PREFIX *registry, struct discord_webhook *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_webhooks)( struct REFLECTC_PREFIX *registry, struct discord_webhooks *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_create_webhook)( struct REFLECTC_PREFIX *registry, struct discord_create_webhook *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_webhook)( struct REFLECTC_PREFIX *registry, struct discord_modify_webhook *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_modify_webhook_with_token)( struct REFLECTC_PREFIX *registry, struct discord_modify_webhook_with_token *self, struct REFLECTC_NS(_wrap) *root);
struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_execute_webhook)( struct REFLECTC_PREFIX *registry, struct discord_execute_webhook *self, struct REFLECTC_NS(_wrap) *root);

struct REFLECTC_NS(_wrap) *REFLECTC_NS(_from_discord_edit_webhook_message)( struct REFLECTC_PREFIX *registry, struct discord_edit_webhook_message *self, struct REFLECTC_NS(_wrap) *root);


#endif /* REFLECT_C_GENERATED_H */
