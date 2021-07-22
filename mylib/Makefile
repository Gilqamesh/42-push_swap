NAME = libmylib.a

$(NAME):
	cd libft && $(MAKE) all
	cp libft/libft.a .
	cd libft && $(MAKE) fclean
	ar -x libft.a
	cd printf && $(MAKE) all
	cp printf/libftprintf.a .
	cd printf && $(MAKE) fclean
	ar -x libftprintf.a
	cd gnl && $(MAKE) all
	cp gnl/libgnl.a .
	cd gnl && $(MAKE) fclean
	ar -x libgnl.a
	rm -rf *.a
	ar -rs $(NAME) *.o
	rm -rf *.o

.PHONY: all fclean
all:
	make $(NAME)
fclean:
	rm -rf *.o $(NAME)