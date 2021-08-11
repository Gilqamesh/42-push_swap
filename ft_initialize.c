/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 21:04:22 by edavid           ###   ########.fr       */
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

static void	test_for_duplicates(t_push_swap *mystruct)
{
	t_list	*head;
	t_list	**lst;

	lst = &mystruct->sorted;
	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head->next)
	{
		if (*(int *)(head->content) == *(int *)(head->next->content))
			ft_error(mystruct);
		head = head->next;
	}
}

static void	handle_argument(t_push_swap *mystruct, char **argv, t_3_int *ijk,
t_list **sorted)
{
	int				*nptr;
	char			**str_arr;
	t_node_binary	*new;

	str_arr = ft_split(argv[ijk->a], ' ');
	while (str_arr[++ijk->b])
	{
		test_is_str_valid_int(mystruct, str_arr[ijk->b]);
		nptr = malloc(sizeof(*nptr));
		if (!nptr)
			ft_error(mystruct);
		*nptr = ft_atoi(str_arr[ijk->b]);
		ft_lstsortedinsert_int(sorted, ft_lstnew(nptr));
		new = ft_nodbinnew(ft_intdup(*nptr));
		if (!new)
			ft_error(mystruct);
		ft_nodbinadd_back(&mystruct->a.head, new);
		mystruct->a.n++;
	}
	ft_destroy_str_arr(&str_arr);
	if (ijk->a == ijk->c - 1)
	{
		new->next = mystruct->a.head;
		mystruct->a.head->prev = new;
	}
}

void	parse_input(t_push_swap *mystruct, int argc, char **argv)
{
	t_3_int			ijk;
	t_list			*sorted;

	sorted = (t_list *)0;
	ijk.a = 0;
	ijk.c = argc;
	while (++ijk.a < argc)
	{
		ijk.b = -1;
		handle_argument(mystruct, argv, &ijk, &sorted);
	}
	mystruct->sorted = sorted;
	test_for_duplicates(mystruct);
}
