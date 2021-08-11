NAME = push_swap
BONUSNAME = checker
BONUSOBJ = checker_program/ft_checker.o checker_program/initialize.o
CC = gcc
SRC = ft_initialize.c ft_error.c ft_testers.c \
stack_operations/stack_op1.c stack_operations/stack_op2.c \
stack_operations/stack_op3.c utils/ft_entropy.c algorithms/LIS/LIS_sort.c \
ft_get_routes.c stack_operations/stack_op1_helper.c ft_testers_helper.c \
utils/ft_utils.c algorithms/LIS/LIS_utils.c algorithms/LIS/LIS_sort.c \
helper1.c helper2.c algorithms/LIS/utils_helper1.c algorithms/LIS/utils_helper2.c \
algorithms/LIS/utils_helper3.c algorithms/LIS/utils_helper4.c \
algorithms/three_sort/three_sort.c

CFLAGS = -g
LIBNAME = libpush_swap.a
LIBPATH = ./$(LIBNAME)
MYLIB = ./mylib/libmylib.a

$(NAME): $(SRC:.c=.o) ft_driver.o $(LIBNAME)
	make library
	-ar -d $(LIBNAME) ft_checker.o
	ar -rs $(LIBNAME) ft_driver.o
	$(CC) $(CFLAGS) -o $(NAME) $(LIBPATH)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar -rs $(LIBNAME) $@
$(LIBNAME): $(MYLIB)
$(MYLIB):
	$(MAKE) --directory=mylib
.PHONY: clean fclean re all bonus library fcleanall
clean:
	rm -f *.o __.SYMDEF __.SYMDEF\ SORTED
	cd stack_operations && rm -f *.o
	cd utils && rm -f *.o
	cd checker_program && rm -f *.o
	cd algorithms/LIS && rm -f *.o
fclean:
	make clean
	rm -f $(LIBNAME)
re:
	make fclean
	make all
all: $(NAME)
bonus: $(SRC:.c=.o) $(BONUSOBJ)
	make library
	-ar -d $(LIBNAME) driver.o
	ar -rs $(LIBNAME) $(BONUSOBJ)
	$(CC) $(CFLAGS) -o $(BONUSNAME) $(LIBNAME)
library:
	make $(LIBNAME)
	cp $(MYLIB) .
	ar -x libmylib.a
	rm -rf libmylib.a
	ar -rs $(LIBNAME) *.o
	ar -rs $(LIBNAME) ./stack_operations/*.o
	ar -rs $(LIBNAME) ./algorithms/LIS/*.o
	ar -rs $(LIBNAME) ./algorithms/three_sort/*.o
	ar -rs $(LIBNAME) ./utils/*.o
fcleanall: fclean
	$(MAKE) fcleanall --directory=mylib