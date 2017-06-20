#include "main.h"

int main(int ac, char **av) {

  Config *c;
  
  if (ac > 1 ) {
    c = parse_config(av[1]);
  } else {
    c = parse_config(DEFAULT_CONFIG);
  }
  printf("\n\n---- Configuration ----\n");
  printf("Name: %s\nHost: %s\nServer: %s\nPort:%d\n", c->name, c->host, c->server, c->port);
  printf("-----------------------\n\n");

  start_bot(c);
  return 0;
}

