NAME = push_swap
CC = gcc
OBJ = ft_driver.o ft_initialize.o ft_error.o
CFLAGS = 
LIBNAME = libpush_swap.a
LIBPATH = /Users/edavid/Desktop/Repo/MyProjects/push_swap/$(LIBNAME)

$(NAME): $(OBJ)
	cd mylib && $(MAKE) all
	cp ./mylib/libmylib.a .
	cd mylib && $(MAKE) fclean
	ar -x libmylib.a
	ar -rs $(LIBNAME) *.o
	rm -f *.o libmylib.a
	$(CC) $(CFLAGS) -o $(NAME) $(LIBPATH)
	rm -f libmylib.a $(LIBNAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all bonus
clean:
	rm -f *.o $(NAME)
	cd mylib && $(MAKE) fclean
fclean:
	make clean
	rm -f $(LIBNAME)
re:
	make clean
	make all
all: $(NAME)
	make bonus
bonus: