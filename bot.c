#include "bot.h"


void start_bot(Config *c)
{
  connect_server(c);
  join_server(c);
  loop(c);
  clean(c);
}

void clean(Config *c) {
  free(c->host);
  free(c->name);
  free(c->server);
  free(c->channel);

  close(c->log);
  close(c->socket);
  free(c);
}

void join_server(Config *c)
{   
  command_pass(c);
  command_nick(c, NULL);
  command_user(c);
}

void loop(Config *c)
{
  char *buffer;
  char *line;
  fd_set rdfs;
  char *save;
  int n;
  int i;

  while(1)
    {
      FD_ZERO(&rdfs);
      buffer = malloc(BUFF_SIZE +1);
  

      FD_SET(c->socket, &rdfs);

      if(select(c->socket + 1, &rdfs, NULL, NULL, NULL) == -1)
	{
	  fprintf(stderr, "error select : %s\n", strerror(errno));
	  break;
	}
      
      if(FD_ISSET(c->socket, &rdfs))
	{
	  for (n = 0; (n = read(c->socket, buffer, BUFF_SIZE)) <  BUFF_SIZE;i++) {
	    if(n == 0)
	      {
		printf("Server disconnected !\n");
		break;
	      }

	    while ((line = strtok_r(buffer, "\n", &save)) != NULL) {

	      log_msg(c, line, 0);
	      log_msg(c, "\n", 0);
	      printf("%s\n", line);
	      parse_buffer(c, line);
	      free(buffer);
	      buffer = NULL;
	    }
	    buffer = malloc(BUFF_SIZE +1);
	    memset(buffer, 0, BUFF_SIZE);
	  }
	}
    }
}

void parse_buffer(Config *c, char *buffer)
{
  char *token;
  char *save;
  int i;
  
  command commands[] = {
    {"PING", &command_ping},
    {"PRIVMSG", &on_privmsg},
    {0, 0}
  };
  
  token = strtok_r(buffer, " ", &save);
  if (token == NULL) {
    return;
  }
  if (token[0] == ':') {
    token = strtok_r(NULL, " ", &save);
  }
  
  for (i = 0; commands[i].name != 0; i++) {
    if (strcmp(token, commands[i].name) == 0) {
      commands[i].command(c, strtok_r(NULL, "", &save));      
    } 
  }
}

void on_privmsg(Config *c, char *buffer) {
  char *token;
  char *ptr;
  char *channel;
  int i;
  
  handler handlers[] = {
    {"hello", &handler_hello},
    {0, 0}
  };
  channel = strtok_r(buffer, " ", &ptr);
  if (channel == NULL) {
    return;
  }
  if (strcmp(channel, c->channel) != 0 && strcmp(channel, c->name) != 0) {
    return;
  }
  token = strtok_r(NULL, "", &ptr);
  if (token == NULL) {
    return;
  }
  
  token++;
  if (token[0] == '!') {
    token++;
    for (i = 0; handlers[i].name != 0; i++) {
      if (strncmp(token, handlers[i].name, strlen(handlers[i].name)) == 0) {
	handlers[i].handler(c, channel, strtok_r(NULL, "", &ptr));      
      } 
    }
    
  }
  
}
