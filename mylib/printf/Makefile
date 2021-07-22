# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edavid <edavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 20:47:25 by edavid            #+#    #+#              #
#    Updated: 2021/07/22 15:01:38 by edavid           ###   ########.fr        #
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
	cd ../libft && $(MAKE) fclean
	mv libft.a $(NAME)
	ar -rs $(NAME) $^
	make clean
ft_printf.o : ft_printf.c $(libftHeader) ft_printf.h ft_conversions.h
	$(CC) $(CFLAGS) -c ft_printf.c
ft_conversions.o : ft_conversions.c $(libftHeader) ft_conversions.h
	$(CC) $(CFLAGS) -c ft_conversions.c
ft_conversions2.o : ft_conversions2.c $(libftHeader) ft_conversions.h
	$(CC) $(CFLAGS) -c ft_conversions2.c
ft_conversions_utils.o : ft_conversions_utils.c $(libftHeader) ft_conversions.h
	$(CC) $(CFLAGS) -c ft_conversions_utils.c
ft_conversions_utils2.o : ft_conversions_utils2.c $(libftHeader) ft_conversions.h
	$(CC) $(CFLAGS) -c ft_conversions_utils2.c
ft_printf_utils.o : ft_printf_utils.c $(libftHeader) ft_printf.h ft_conversions.h
	$(CC) $(CFLAGS) -c ft_printf_utils.c
ft_set_flags.o : ft_set_flags.c $(libftHeader) ft_printf.h
	$(CC) $(CFLAGS) -c ft_set_flags.c
ft_print_conversion_hexa.o : ft_print_conversion_hexa.c $(libftHeader) ft_conversions.h
	$(CC) $(CFLAGS) -c ft_print_conversion_hexa.c
ft_print_conversion_hexa_utilities.o : ft_print_conversion_hexa_utilities.c $(libftHeader) ft_conversions.h
	$(CC) $(CFLAGS) -c ft_print_conversion_hexa_utilities.c
ft_print_conversion_s.o : ft_print_conversion_s.c $(libftHeader) ft_conversions.h ft_print_conversion_s_utilities.h
	$(CC) $(CFLAGS) -c ft_print_conversion_s.c
ft_print_conversion_s_utilities.o : ft_print_conversion_s_utilities.c $(libftHeader) ft_print_conversion_s_utilities.h
	$(CC) $(CFLAGS) -c ft_print_conversion_s_utilities.c
ft_print_conversion_p.o : ft_print_conversion_p.c $(libftHeader) ft_conversions.h
	$(CC) $(CFLAGS) -c ft_print_conversion_p.c
ft_print_conversion_int.o : ft_print_conversion_int.c $(libftHeader) ft_conversions.h ft_print_conversion_int_utils.h
	$(CC) $(CFLAGS) -c ft_print_conversion_int.c
ft_print_conversion_int_utils.o : ft_print_conversion_int_utils.c $(libftHeader) ft_print_conversion_int_utils.h
	$(CC) $(CFLAGS) -c ft_print_conversion_int_utils.c
ft_print_conversion_uint.o : ft_print_conversion_uint.c $(libftHeader) ft_conversions.h ft_print_conversion_uint_utils.h
	$(CC) $(CFLAGS) -c ft_print_conversion_uint.c
ft_print_conversion_uint_utils.o : ft_print_conversion_uint_utils.c $(libftHeader) ft_print_conversion_uint_utils.h
	$(CC) $(CFLAGS) -c ft_print_conversion_uint_utils.c
driver.o : driver.c ft_printf.h
	$(CC) $(CFLAGS) -c driver.c
.PHONY: all clean fclean re bonus test
all : $(NAME)
clean :
	rm -f *.o libft/*.o
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
# need driver.c test file for this
