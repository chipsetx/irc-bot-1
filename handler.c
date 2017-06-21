#include "handler.h"

void handler_hello(Config *c, message *msg)
{
  char *str  = ":hello world";
  msg->msg = str;
  command_msg(c, msg);
}
