/*      This file is part of iiadb.

    iiadb is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    iiadb is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with iiadb. If not, see
   <https://www.gnu.org/licenses/>.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "discord.h"
#include "commands.h"

void on_ready(struct discord* client)
{
    const struct discord_user* bot = discord_get_self(client);

    log_info("bot: Logged in as %s!", bot->username);
}

int main(void)
{
    struct discord* client = discord_config_init("config.json");

    discord_set_on_ready(client, &on_ready);
    discord_set_on_command(client, "ping", &cmd_ping);
    discord_set_on_command(client, "about", &cmd_about);
    discord_set_on_command(client, "list commands", &cmd_list_commands);
    discord_set_on_command(client, "list cmds", &cmd_list_commands);
    discord_set_on_command(client, "help", &cmd_help);

    discord_run(client);

    discord_cleanup(client);

    return 0;
}
