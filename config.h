#ifndef _CONFIG_H__
#define _CONFIG_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DEFAULT_CONFIG "config.cfg"
#define DEFAULT_NAME "taitaibot"
#define DEFAULT_HOST "taitaihost"
#define DEFAULT_SERVER "irc.quakenet.org"
#define DEFAULT_PORT 6667
#define DEFAULT_LOG_FILE "bot.log"
#define DEFAULT_CHANNEL "#test"

typedef struct Config {
  
  char *name;
  char *host;
  char *server;
  char *password;
  char *channel;
  int port;
  int socket;
  int log;
  
} Config;

Config *parse_config(char *path);
Config *parse_file(FILE *fp);
Config *use_default_config();
ssize_t readline(char **lineptr, FILE *stream);
#endif
