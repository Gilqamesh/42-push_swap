/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:20:23 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 16:30:48 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	stack_ra(t_push_swap *mystruct)
{
	mystruct->a.head = mystruct->a.head->prev;
}

void	stack_rb(t_push_swap *mystruct)
{
	mystruct->b.head = mystruct->b.head->prev;
}

void	stack_rr(t_push_swap *mystruct)
{
	stack_ra(mystruct);
	stack_rb(mystruct);
}
