#ifndef _COMMAND_H__
#define _COMMAND_H__

#include <unistd.h>

#include "config.h"
#include "socket.h"
#include "bot.h"

typedef struct message message;

void command_nick(Config *c, char *nick);
void command_ping(Config *c, message *msg);
void command_user(Config *c);
void command_pass(Config *c);
void command_join(Config *c);
void command_msg(Config *c, message *msg);
#endif
