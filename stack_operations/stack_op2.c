/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:20:23 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 18:29:54 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	stack_ra(t_push_swap *mystruct)
{
	int	tmp;
	int	i;

	if (!mystruct->a.n)
		return ;
	tmp = mystruct->a.arr[mystruct->a.n - 1];
	i = mystruct->a.n;
	while (--i > 0)
		mystruct->a.arr[i] = mystruct->a.arr[i - 1];
	mystruct->a.arr[i] = tmp;
}

void	stack_rb(t_push_swap *mystruct)
{
	int	tmp;
	int	i;

	if (!mystruct->b.n)
		return ;
	tmp = mystruct->b.arr[mystruct->b.n - 1];
	i = mystruct->b.n;
	while (--i > 0)
		mystruct->b.arr[i] = mystruct->b.arr[i - 1];
	mystruct->b.arr[i] = tmp;
}

void	stack_rr(t_push_swap *mystruct)
{
	stack_ra(mystruct);
	stack_rb(mystruct);
}
