/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testers_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:31:51 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 18:34:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_stacks_helper(t_node_binary *a_cur, t_node_binary *b_cur,
int a_counter, int b_counter)
{
	while (a_counter >= 0 && a_counter > b_counter)
	{
		ft_printf("%d\n", *(int *)(a_cur->content));
		a_cur = a_cur->next;
		a_counter--;
	}
	while (b_counter >= 0 && b_counter > a_counter)
	{
		ft_printf(" \t\t%d\n", *(int *)(b_cur->content));
		b_cur = b_cur->next;
		b_counter--;
	}
	while (a_counter >= 0)
	{
		ft_printf("%d\t\t%d\n", *(int *)(a_cur->content),
			*(int *)(b_cur->content));
		a_cur = a_cur->next;
		b_cur = b_cur->next;
		a_counter--;
		b_counter--;
	}
}
