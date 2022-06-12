/*      This file is part of iiadb.

    iiadb is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    iiadb is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with iiadb. If not, see
   <https://www.gnu.org/licenses/>.  */

#include <stdio.h>
#include "discord.h"

void cmd_ping(struct discord* client, const struct discord_message* msg)
{
    ORCAcode code;
    const char* fmt = "Listen, @%s. I don't like pings at all!";
    size_t len = snprintf(NULL, 0, fmt, msg->author->username);
    char reply[len + 1];
    snprintf(reply, sizeof reply, fmt, msg->author->username);

    struct discord_create_message_params params = {.content = reply};

    code = discord_create_message(client, msg->channel_id, &params, NULL);
    if(code != ORCA_OK)
        log_info("bot: iiadb: discord_create_message did not return ORCA_OK in cmd_ping.");
}

void cmd_about(struct discord* client, const struct discord_message* msg)
{
    ORCAcode code;
    struct discord_embed eb = {.title = "About me",
                               .type = "rich",
                               .description =
                                   "IIADB - IIADB is a discord bot. I Work 24/7/365 to serve my creators.\n"
                                   "Written in the C Programming Language with help of orca libraries.\n"
                                   "Creation date: 12/06/2022\n"
                                   "\nVisit my author's profile: https://github.com/icebarf\n",
                               .url = "https://github.com/icebarf/iiadb",
                               .color = 3066993};

    struct discord_create_message_params params = {.embed = &eb};

    code = discord_create_message(client, msg->channel_id, &params, NULL);
    if(code != ORCA_OK)
        log_info("bot: iiadb: discord_create_message did not return ORCA_OK in cmd_about.");
}

void cmd_list_commands(struct discord* client, const struct discord_message* msg)
{
    ORCAcode code;
    struct discord_embed eb = {.title = "Commands List",
                               .type = "rich",
                               .description =
                                   "`.iping` - check for a response from the bot\n"
                                   "`.iabout` - information about the bot\n"
                                   "`.ilist cmds | .ilist commands`\n"
                                   "-  list of commands available in the bot\n",
                               .color = 3066993};

    struct discord_create_message_params params = {.embed = &eb};

    code = discord_create_message(client, msg->channel_id, &params, NULL);
    if(code != ORCA_OK)
        log_info("bot: iiadb: discord_create_message did not return ORCA_OK in cmd_list_commands.");
}

void cmd_help(struct discord* client, const struct discord_message* msg)
{
    ORCAcode code;
    struct discord_embed eb = {.title = "Help Menu",
                               .type = "rich",
                               .description =
                                   "**View the list of commands available**\n"
                                   "`.ilist cmds`\n"
                                   "\nMoar help soon",
                               .color = 3066993};

    struct discord_create_message_params params = {.embed = &eb};

    code = discord_create_message(client, msg->channel_id, &params, NULL);
    if(code != ORCA_OK)
        log_info("bot: iiadb: discord_create_message did not return ORCA_OK in cmd_help.");
}

