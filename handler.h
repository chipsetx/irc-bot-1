#ifndef _HANDLER_H__
#define _HANDLER_H__

#include "config.h"
#include "socket.h"
#include "command.h"
#include "bot.h"

typedef struct message message;
typedef struct handler {
  char *name;
  void (*handler)(Config *c, message *msg);
} handler;

void handler_hello(Config *c, message *msg);

#endif
