#include "handler.h"

void handler_hello(Config *c, char *channel, char *str)
{
  (void) str;
  command_msg(c, channel, ":hello world");
}
