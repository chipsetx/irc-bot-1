#include "socket.h"

static int sent = 0;

void connect_server(Config *config)
{
  SOCKET sock;

  printf("connecting ...\n");
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("error creating socket : %s\n", strerror(errno));
    exit(1);
  }

  struct hostent *hostinfo = NULL;
  SOCKADDR_IN sin = { 0 };

  hostinfo = gethostbyname(config->server);
  if (hostinfo == NULL)
    {
      fprintf (stderr, "Unknown host %s.\n", config->server);
      exit(1);
    }

  sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr; 
  sin.sin_port = htons(config->port);
  sin.sin_family = AF_INET;

  if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == -1)
    {
      fprintf (stderr, "connect error:  %s.\n", strerror(errno));
      exit(1);
    }

  config->socket = sock;
}

int write_server(Config *config, char *str)
{
  int n;

  log_msg(config, str, 1);
  n = write(config->socket, str, strlen(str));
  
  return n;
}


int log_msg(Config *config, char *str, int side) {
  int n;


  if (!sent) {
    if (side == 1) {
      write(config->log, ">> ", 3);
    } else {
      write(config->log, "<< ", 3);
    }
    sent = 1;
  }
  n = write(config->log, str, strlen(str));

  
  if (str[0] == '\n') {
    sent = 0;
  }
  return n;
}
