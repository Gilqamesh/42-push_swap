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
MYLIB = ./mylib/libmylib.a

$(NAME): $(OBJ) ft_driver.o $(LIBNAME)
	ar -d $(LIBNAME) ft_checker.o tester.o
	ar -rs $(LIBNAME) ft_driver.o
	$(CC) $(CFLAGS) -o $(NAME) $(LIBPATH)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBNAME):
	$(MAKE) --directory=mylib
	cp $(MYLIB) .
	ar -x libmylib.a
	ar -rs $(LIBNAME) *.o
	ar -rs $(LIBNAME) ./stack_operations/*.o
	ar -rs $(LIBNAME) ./algorithms/LIS/*.o
	ar -rs $(LIBNAME) ./utils/*.o
	rm -f libmylib.a
$(MYLIB):
	$(MAKE) --directory=mylib
.PHONY: clean fclean re all bonus library tester
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
bonus: $(OBJ) $(BONUSOBJ)
	make library
	ar -d $(LIBNAME) tester.o driver.o
	ar -rs $(LIBNAME) checker_program/*.o
	$(CC) $(CFLAGS) -o $(BONUSNAME) $(LIBNAME)
library: $(LIBNAME)
tester: $(OBJ) tester.o
	rm -rf $(LIBNAME)
	make library
	ar -d $(LIBNAME) ft_driver.o ft_checker.o tester.o
	$(CC) $(CFLAGS) -o tester $(LIBNAME) tester.o