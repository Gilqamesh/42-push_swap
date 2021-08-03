NAME = push_swap
BONUSNAME = checker
BONUSOBJ = checker_program/ft_checker.o checker_program/initialize.o
CC = gcc
OBJ = ft_initialize.o ft_error.o ft_testers.o \
stack_operations/stack_op1.o stack_operations/stack_op2.o \
stack_operations/stack_op3.o utils/ft_entropy.o algorithms/LIS/LIS_sort.o \
ft_get_routes.o stack_operations/stack_op1_helper.o ft_testers_helper.o \
utils/ft_utils.o algorithms/LIS/LIS_utils.o algorithms/LIS/LIS_sort.o
CFLAGS = 
LIBNAME = libpush_swap.a
LIBPATH = ./$(LIBNAME)

$(NAME): $(OBJ) ft_driver.o
	make library
	$(CC) $(CFLAGS) -o $(NAME) $(LIBPATH)
	make clean
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBNAME):
	cd mylib && $(MAKE) all
	cp ./mylib/libmylib.a .
	cd mylib && $(MAKE) fclean
	ar -x libmylib.a
	ar -rs $(LIBNAME) *.o
	ar -rs $(LIBNAME) ./stack_operations/*.o
	rm -f ./stack_operations/*.o
	ar -rs $(LIBNAME) ./algorithms/LIS/*.o
	rm -f ./algorithms/LIS/*.o
	ar -rs $(LIBNAME) ./utils/*.o
	cd utils && rm -f *.o
	rm -f *.o libmylib.a

.PHONY: clean fclean re all bonus library tester
clean:
	rm -f *.o __.SYMDEF __.SYMDEF\ SORTED
	cd mylib && $(MAKE) fclean
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
bonus: fclean $(OBJ) $(BONUSOBJ)
	cp checker_program/*.o .
	make library
	$(CC) $(CFLAGS) -o $(BONUSNAME) $(LIBNAME)
	make clean
library: $(LIBNAME)
tester: fclean $(OBJ) $(BONUSOBJ)
	make library
	$(CC) $(CFLAGS) -c tester.c
	$(CC) $(CFLAGS) -o tester $(LIBNAME) tester.o
	make clean