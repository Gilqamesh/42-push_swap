BUFFER = BUFFER_SIZE=42
CC = gcc
OBJ = get_next_line.o get_next_line_utils.o
CFLAGS = -Wall -Wextra -Werror
NAME = libgnl.a


$(NAME): $(OBJ)
	ar -rs $(NAME) $^
	rm -rf __.SYMDEF __.SYMDEF\ SORTED

get_next_line.o : get_next_line.c get_next_line.h
	$(CC) $(CFLAGS) -c -D $(BUFFER) get_next_line.c
get_next_line_utils.o : get_next_line_utils.c get_next_line.h
	$(CC) $(CFLAGS) -c get_next_line_utils.c

.PHONY: all fclean fcleanall
all:
	make $(NAME)
fclean:
	rm -rf *.o $(NAME) __.SYMDEF __.SYMDEF\ SORTED
fcleanall: fclean