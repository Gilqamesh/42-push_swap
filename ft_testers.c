/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:44:59 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 19:07:16 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_push_swap.h"

void	print_stacks(t_push_swap *mystruct)
{
	int	a_index;
	int	b_index;

	a_index = mystruct->a.n - 1;
	b_index = mystruct->b.n - 1;
	ft_printf("------------------------------------------------------------\n");
	while (a_index >= 0 && a_index > b_index)
		ft_printf("%d\n", mystruct->a.arr[a_index--]);
	while (b_index >= 0 && b_index > a_index)
		ft_printf(" \t\t%d\n", mystruct->b.arr[b_index--]);
	while (a_index >= 0)
		ft_printf("%d\t\t%d\n", mystruct->a.arr[a_index--],
			mystruct->b.arr[b_index--]);
	ft_printf("_\t\t_\n");
	ft_printf("a\t\tb\n");
	ft_printf("------------------------------------------------------------\n");
}

static void	check_key_pressed(t_push_swap *mystruct, char input)
{
	if (input == 'q')
		stack_sa(mystruct);
	else if (input == 'w')
		stack_sb(mystruct);
	else if (input == 'e')
		stack_ss(mystruct);
	else if (input == 'a')
		stack_pa(mystruct);
	else if (input == 's')
		stack_pb(mystruct);
	else if (input == 'z')
		stack_ra(mystruct);
	else if (input == 'x')
		stack_rb(mystruct);
	else if (input == 'c')
		stack_rr(mystruct);
	else if (input == 'r')
		stack_rra(mystruct);
	else if (input == 't')
		stack_rrb(mystruct);
	else if (input == 'y')
		stack_rrr(mystruct);
}

void	game_loop(t_push_swap *mystruct)
{
	char	input;

	print_stacks(mystruct);
	input = 1;
	while (input)
	{
		ft_putstr_fd("q - swap a, w - swap b, e - swap both\n", 0);
		ft_putstr_fd("a - push a, s - push b\n", 0);
		ft_putstr_fd("z - rotate a, x - rotate b, c - rotate both\n", 0);
		ft_putstr_fd("r - rev rot a, t - rev rot b, y - rev rot both\n", 0);
		ft_putstr_fd("Enter operation: ", 0);
		read(1, &input, 1);
		read(1, 0, 1);
		check_key_pressed(mystruct, input);
		print_stacks(mystruct);
	}
}
