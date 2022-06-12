#ifndef IIADB_COMMANDS_H
#define IIADB_COMMAND_H

/* ping command */
void cmd_ping(struct discord* client, const struct discord_message* msg);

/* about command */
void cmd_about(struct discord* client, const struct discord_message* msg);

/* list commands command */
void cmd_list_commands(struct discord* client, const struct discord_message* msg);

/* help command */
void cmd_help(struct discord* client, const struct discord_message* msg);

#endif
