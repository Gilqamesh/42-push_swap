/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by edavid            #+#    #+#             */
/*   Updated: 2021/07/28 10:22:54 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "ft_push_swap.h"

static int	contains_non_numeric(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (1);
	return (0);
}

static void	test_is_str_valid_int(t_push_swap *mystruct, char *str)
{
	int	res;

	if (*str == '+')
		str++;
	if (*str == '-')
	{
		if (!*str || contains_non_numeric(str + 1))
			ft_error(mystruct);
	}
	else if (!*str || contains_non_numeric(str))
		ft_error(mystruct);
	res = ft_atoi(str);
	if (res == INT_MIN && ft_strncmp(str, "-2147483648", 11))
		ft_error(mystruct);
	if (res == INT_MAX && ft_strncmp(str, "2147483647", 10))
		ft_error(mystruct);
}

void	initialize_struct(t_push_swap *mystruct, int argc)
{
	ft_bzero(mystruct, sizeof(*mystruct));
	mystruct->a.n = argc - 1;
	mystruct->b.n = 0;
}

static void	test_for_duplicates(t_push_swap *mystruct, t_list **lst)
{
	t_list	*head;

	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head->next)
	{
		if (*(int *)(head->content) == *(int *)(head->next->content))
		{
			ft_lstclear(lst, ft_lstdel);
			ft_error(mystruct);
		}
		head = head->next;
	}
}

void	parse_input(t_push_swap *mystruct, int argc, char **argv)
{
	int				i;
	int				*nptr;
	t_list			*sorted;
	t_node_binary	*new;

	i = 1;
	sorted = (t_list *)0;
	while (i < argc)
	{
		test_is_str_valid_int(mystruct, argv[i]);
		nptr = malloc(sizeof(*nptr));
		if (!nptr)
			ft_error(mystruct);
		*nptr = ft_atoi(argv[i]);
		ft_lstsortedinsert_int(&sorted, ft_lstnew(nptr));
		new = ft_nodbinnew(nptr);
		if (!new)
			ft_error(mystruct);
		ft_nodbinadd_back(&mystruct->a.head, new);
		if (++i == argc)
		{
			new->next = mystruct->a.head;
			mystruct->a.head->prev = new;
		}
	}
	test_for_duplicates(mystruct, &sorted);
	mystruct->sorted = sorted;
}
