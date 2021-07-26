/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entropy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:01:02 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 17:12:02 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	calc_entropy(t_stack *stack)
{
	int				entropy;
	int				i;
	t_node_binary	*cur;

	cur = stack->head;
	entropy = 0;
	i = -1;
	while (++i < stack->n - 1)
	{
		if (*(int *)(cur->content) > *(int *)(cur->next->content))
			entropy++;
		cur = cur->next;
	}
	if (stack->n > 2 && *(int *)(stack->head->content)
		> *(int *)(stack->head->prev->content))
		entropy++;
	return (entropy);
}
