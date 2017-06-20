#include "command.h"

void command_nick(Config *c, char *nick){

  write_server(c, "NICK ");
  if (nick == NULL) {
  write_server(c, c->name);
  } else {
    write_server(c, nick);
  }
  write_server(c, "\n");
  
}

void command_ping(Config *c, char *pong) {
  write_server(c, "PONG ");
  write_server(c, pong);
  write_server(c, "\n");
  command_join(c);
}

void command_user(Config *c) {
  write_server(c, "USER ");
  write_server(c, c->name);
  write_server(c, " ");
  write_server(c, c->host);
  write_server(c, " ");
  write_server(c, c->host);
  write_server(c, " :");
  write_server(c, c->name);
  write_server(c, "\n");
}

void command_pass(Config *c) {
  if (c->password == NULL) {
    return;
  }
  write_server(c, "PASS ");
  write_server(c, c->password);
  write_server(c, "\n");
}


void command_join(Config *c) {

  write_server(c, "JOIN ");
  write_server(c, c->channel);
  write_server(c, "\n");
}

void command_msg(Config *c, char *channel, char *str) {
  write_server(c, "PRIVMSG ");
  write_server(c, channel);
  write_server(c, " ");
  write_server(c, str);
  write_server(c, "\n");
}
