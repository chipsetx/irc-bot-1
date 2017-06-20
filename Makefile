SRC = main.c config.c bot.c socket.c command.c handler.c

OBJ = $(SRC:.c=.o)

EXE = ircbot

CFLAGS = -W -Wall

all: $(OBJ)
	gcc $(OBJ) -o $(EXE)

debug:
	gcc $(SRC) -g -o $(EXE)
clean :
	rm -f $(EXE)
	rm -f $(OBJ)
	rm -f *~
re : clean all

