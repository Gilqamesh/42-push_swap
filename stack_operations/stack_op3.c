/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:27:29 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 18:31:08 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	stack_rra(t_push_swap *mystruct)
{
	int	tmp;
	int	i;

	if (!mystruct->a.n)
		return ;
	tmp = mystruct->a.arr[0];
	i = -1;
	while (++i < mystruct->a.n - 1)
		mystruct->a.arr[i] = mystruct->a.arr[i + 1];
	mystruct->a.arr[i] = tmp;
}

void	stack_rrb(t_push_swap *mystruct)
{
	int	tmp;
	int	i;

	if (!mystruct->b.n)
		return ;
	tmp = mystruct->b.arr[0];
	i = -1;
	while (++i < mystruct->b.n - 1)
		mystruct->b.arr[i] = mystruct->b.arr[i + 1];
	mystruct->b.arr[i] = tmp;
}

void	stack_rrr(t_push_swap *mystruct)
{
	stack_rra(mystruct);
	stack_rrb(mystruct);
}
