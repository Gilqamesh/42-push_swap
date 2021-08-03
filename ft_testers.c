/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:44:59 by edavid            #+#    #+#             */
/*   Updated: 2021/08/03 16:27:15 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_push_swap.h"

void	print_stacks(t_push_swap *mystruct)
{
	int				a_counter;
	int				b_counter;
	t_node_binary	*a_cur;
	t_node_binary	*b_cur;

	a_counter = mystruct->a.n - 1;
	b_counter = mystruct->b.n - 1;
	a_cur = mystruct->a.head;
	b_cur = mystruct->b.head;
	ft_printf("------------------------------------------------------------\n");
	print_stacks_helper(a_cur, b_cur, a_counter, b_counter);
	ft_printf("_\t\t_\n");
	ft_printf("a\t\tb\n");
	ft_printf("entropies\n");
	ft_printf("%d\t\t%d\n", calc_entropy(&mystruct->a),
		calc_entropy(&mystruct->b));
	ft_printf("sorted\n");
	ft_printf("%d\t\t%d\n", is_stack_sorted(&mystruct->a, 0),
		is_stack_sorted(&mystruct->b, 0));
	ft_printf("n of elements\n");
	ft_printf("%d\t\t%d\n", mystruct->a.n, mystruct->b.n);
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
		ft_putstr_fd("q - sa, w - sb, e - ss\n", 0);
		ft_putstr_fd("a - pa, s - pb\n", 0);
		ft_putstr_fd("z - ra, x - rb, c - rr\n", 0);
		ft_putstr_fd("r - rra, t - rrb, y - rrr\n", 0);
		ft_putstr_fd("Enter operation: ", 0);
		read(1, &input, 1);
		read(1, 0, 1);
		check_key_pressed(mystruct, input);
		print_stacks(mystruct);
	}
}

int	is_solution(t_push_swap *mystruct)
{
	int				entr_a;
	int				entr_b;
	int				i;
	t_node_binary	*cur;

	update_entropies(mystruct, &entr_a, &entr_b);
	if (entr_a || entr_b || mystruct->b.n)
		return (0);
	cur = mystruct->a.head;
	i = -1;
	while (++i < mystruct->a.n - 1)
	{
		if (*(int *)(cur->content) > *(int *)(cur->next->content))
			return (0);
		cur = cur->next;
	}
	return (1);
}
