#ifndef _HANDLER_H__
#define _HANDLER_H__

#include "config.h"
#include "socket.h"
#include "command.h"

typedef struct handler {
  char *name;
  void (*handler)(Config *c, char *channel, char *str);
} handler;

void handler_hello(Config *c, char *channel, char *str);

#endif
