# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edavid <edavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 10:05:25 by edavid            #+#    #+#              #
#    Updated: 2021/07/31 11:50:32 by edavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
sources = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isdigit.c ft_isalpha.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
bonus_sources = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
extended_sources = ft_realloc.c ft_nodbinadd_back.c ft_nodbinadd_front.c \
ft_nodbinclear.c ft_nodbindelone.c ft_nodbiniter.c ft_nodbinlast.c \
ft_nodbinmap.c ft_nodbinnew.c ft_nodbinsize.c ft_nodbindel.c ft_nodbinprint_int.c \
ft_lstsortedinsert_int.c ft_lstdel.c ft_lstprint_int.c ft_merge_sort_int.c \
ft_abs_int.c ft_merge_sort_str.c ft_strcmp.c ft_intdup.c

NAME = libft.a

$(NAME) : *.c
	$(CC) $(FLAGS) -c $(sources)
	ar rc $@ *.o
	make clean
.PHONY: clean bonus all fclean re
clean :
	rm -f *.o __.SYMDEF __.SYMDEF\ SORTED
bonus :
	$(CC) $(FLAGS) -c $(bonus_sources) $(extended_sources)
	ar rc $(NAME) *.o
	make clean
all :
	make $(NAME)
	make bonus
	make clean
fclean :
	make clean
	rm -f $(NAME)
re :
	make fclean
	make all
