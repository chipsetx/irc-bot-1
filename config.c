#include "config.h"

Config *parse_config(char *path) {
  FILE *fp;
  Config *c;
  errno = 0;

  if ((fp = fopen(path, "r")) == NULL) {
    fprintf(stderr,"erreur lors de l'ouverture du fichier %s : %s\n", path, strerror(errno));
    c = use_default_config();
  } else {
    c = parse_file(fp);
    fclose(fp);
  }
  
  if ((c->log = open(DEFAULT_LOG_FILE, O_CREAT|O_TRUNC|O_WRONLY)) == -1) {
    printf("%d\n", c->log);
    fprintf(stderr,"erreur lors de l'ouverture du fichier %s : %s\n", path, strerror(errno));
    c->log = 1;
  }
  
  return c;
  
}

Config *parse_file(FILE *fp) {
  char *str;
  char *token;
  Config *c;
  ssize_t read;
  
  c = malloc(sizeof(Config));
  while ((read = readline(&str, fp)) != -1){
    token = strtok(str, "=");
    if (strcmp("host", token) == 0) {
      token =  strtok(NULL, "=");
      c->host = malloc(strlen(token) +1);
      strcpy(c->host, token);
    }
    else if (strcmp("name", token) ==0) {
      token =  strtok(NULL, "=");
      c->name = malloc(strlen(token) +1);
      strcpy(c->name, token);
    }
    else if (strcmp("server", token) ==0) {
      token =  strtok(NULL, "=");
      c->server = malloc(strlen(token) +1);
      strcpy(c->server, token);
    }
    else if (strcmp("channel", token) ==0) {
      token =  strtok(NULL, "=");
      c->channel = malloc(strlen(token) +1);
      strcpy(c->channel, token);
    }
    else if (strcmp("port", token) ==0) {
      token =  strtok(NULL, "=");
      c->port = atoi(token);
    }
  }
  
  return c;
}

Config *use_default_config() {
  printf("using default configuration ...\n");
  Config *c = malloc(sizeof(Config));

  c->name = DEFAULT_NAME;
  c->host = DEFAULT_HOST;
  c->server = DEFAULT_SERVER;
  c->port = DEFAULT_PORT;
  c->channel = DEFAULT_CHANNEL;
  
  return c;
}

ssize_t readline(char **lineptr, FILE *stream)
{
  size_t len = 0;  // Size of the buffer, ignored.

  ssize_t chars = getline(lineptr, &len, stream);


  if((*lineptr)[chars -1] == '\n') {
    (*lineptr)[chars -1] = '\0';
    --chars;
  }

  return chars;
}
