/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:05:13 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 18:19:50 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	stack_sa(t_push_swap *mystruct)
{
	int	tmp;

	if (mystruct->a.n < 2)
		return ;
	tmp = mystruct->a.arr[mystruct->a.n - 1];
	mystruct->a.arr[mystruct->a.n - 1] = mystruct->a.arr[mystruct->a.n - 2];
	mystruct->a.arr[mystruct->a.n - 2] = tmp;
}

void	stack_sb(t_push_swap *mystruct)
{
	int	tmp;

	if (mystruct->b.n < 2)
		return ;
	tmp = mystruct->b.arr[mystruct->b.n - 1];
	mystruct->b.arr[mystruct->b.n - 1] = mystruct->b.arr[mystruct->b.n - 2];
	mystruct->b.arr[mystruct->b.n - 2] = tmp;
}

void	stack_ss(t_push_swap *mystruct)
{
	stack_sa(mystruct);
	stack_sb(mystruct);
}

void	stack_pa(t_push_swap *mystruct)
{
	if (!mystruct->b.n)
		return ;
	mystruct->a.arr[mystruct->a.n++] = mystruct->b.arr[--mystruct->b.n];
}

void	stack_pb(t_push_swap *mystruct)
{
	if (!mystruct->a.n)
		return ;
	mystruct->b.arr[mystruct->b.n++] = mystruct->a.arr[--mystruct->a.n];
}
