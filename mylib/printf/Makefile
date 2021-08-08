# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edavid <edavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 20:47:25 by edavid            #+#    #+#              #
#    Updated: 2021/08/08 13:38:12 by edavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
libftHeader = ../libft/libft.h
sources = ft_printf.c ft_conversions.c ft_conversions2.c \
ft_conversions_utils.c ft_conversions_utils2.c ft_printf_utils.c \
ft_set_flags.c ft_print_conversion_hexa.c ft_print_conversion_hexa_utilities.c \
ft_print_conversion_s_utilities.c ft_print_conversion_s.c ft_print_conversion_p.c \
ft_print_conversion_int.c ft_print_conversion_int_utils.c ft_print_conversion_uint.c \
ft_print_conversion_uint_utils.c

$(NAME) : $(sources:.c=.o)
	cd ../libft && $(MAKE) all
	cp $(libftHeader:.h=.a) .
	mv libft.a $(NAME)
	ar -rs $(NAME) $^
%.o: %.c
	$(CC) $(CFLAGS) -c $^
.PHONY: all clean fclean re bonus test fcleanall
all : $(NAME)
clean :
	rm -f *.o libft/*.o __.SYMDEF __.SYMDEF\ SORTED
fclean : clean
	rm -f $(NAME)
	cd ../libft && rm -f libft.a
re :
	make clean
	make all
bonus : all
test : $(sources:.c=.o) driver.o
	cd ../libft && $(MAKE) all
	cp $(libftHeader:.h=.a) .
	mv libft.a $(NAME)
	ar -rs $(NAME) $(sources:.c=.o) driver.o
	$(CC) -o test.out $^ -Llibft -lft
fcleanall: fclean