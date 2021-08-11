/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:07:08 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 23:11:56 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helper4.h"

void	init_vars(t_stack *stack, t_node_binary **result_lst, int *i,
t_node_binary **cur)
{
	t_node_binary	*min;

	min = get_min_from_stack(stack);
	*cur = stack->head;
	*i = -1;
	while (++(*i) < stack->n)
	{
		if (*cur == min)
			break ;
		*cur = (*cur)->next;
	}
	*result_lst = NULL;
}

void	get_rotations(t_stack *stack, t_node_binary **result_lst, int i,
char stack_name)
{
	if (i > stack->n / 2)
	{
		i = stack->n - i;
		if (stack_name == 'a')
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" rra")));
		else
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" rrb")));
	}
	else
	{
		if (stack_name == 'a')
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" ra")));
		else
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" rb")));
	}
}

int	get_input_limit_on_LIS(int n_of_inputs)
{
	if (n_of_inputs > 200)
		return (200);
	return (n_of_inputs);
}
