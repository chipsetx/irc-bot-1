#ifndef _SOCKET_H__
#define _SOCKET_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include "config.h"

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

void connect_server(Config *config);
int write_server(Config *config, char *str);
int log_msg(Config *config, char *str, int side);

#endif
