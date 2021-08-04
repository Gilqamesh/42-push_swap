NAME = libmylib.a
LIBFT = libft/libft.a
LIBPRINTF = printf/libftprintf.a
LIBGNL = gnl/libgnl.a

$(NAME): $(LIBFT) $(LIBPRINTF) $(LIBGNL)
	cp $(LIBFT) .
	ar -x libft.a
	cp $(LIBPRINTF) .
	ar -x libftprintf.a
	cp $(LIBGNL) .
	ar -x libgnl.a
	rm -rf *.a
	ar -rs $(NAME) *.o
	rm -rf *.o
$(LIBFT):
	$(MAKE) --directory=libft
$(LIBPRINTF):
	$(MAKE) --directory=printf
$(LIBGNL):
	$(MAKE) --directory=gnl
.PHONY: all fclean
all: $(NAME)
clean:
	rm -rf *.o __.SYMDEF __.SYMDEF\ SORTED
fclean:
	make clean
	rm -rf $(NAME)