#ifndef _BOT_H__
#define _BOT_H__

#include <unistd.h>

#include "config.h"
#include "socket.h"
#include "command.h"
#include "handler.h"

#define BUFF_SIZE 1024

typedef struct command {
  char *name;
  void (* command)(Config*, char*);
} command;

void start_bot(Config *c);
void parse_buffer(Config *c, char *buffer);
void join_server(Config *c);
void loop(Config *c);
void clean(Config *c);
void on_privmsg(Config *c, char *buffer);
#endif
