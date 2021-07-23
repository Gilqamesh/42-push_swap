NAME = push_swap
CC = gcc
OBJ = ft_driver.o ft_initialize.o ft_error.o ft_testers.o \
stack_operations/stack_op1.o stack_operations/stack_op2.o \
stack_operations/stack_op3.o utils/ft_entropy.o ft_order_algo.o
CFLAGS = 
LIBNAME = libpush_swap.a
LIBPATH = /Users/edavid/Desktop/Repo/MyProjects/push_swap/$(LIBNAME)

$(NAME): $(OBJ)
	cd mylib && $(MAKE) all
	cp ./mylib/libmylib.a .
	cd mylib && $(MAKE) fclean
	ar -x libmylib.a
	ar -rs $(LIBNAME) *.o
	ar -rs $(LIBNAME) ./stack_operations/*.o
	cd stack_operations && rm -f *.o
	ar -rs $(LIBNAME) ./utils/*.o
	cd utils && rm -f *.o
	rm -f *.o libmylib.a
	$(CC) $(CFLAGS) -o $(NAME) $(LIBPATH)
	rm -f libmylib.a $(LIBNAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all bonus
clean:
	rm -f *.o $(NAME)
	cd mylib && $(MAKE) fclean
	cd stack_operations && rm -f *.o
fclean:
	make clean
	rm -f $(LIBNAME)
re:
	make clean
	make all
all: $(NAME)
	make bonus
bonus: