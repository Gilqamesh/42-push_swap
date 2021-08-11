/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:59:04 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 22:24:30 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

static char	*get_ops_for_three_helper(t_push_swap *mystruct, t_3_int ijk)
{
	if (ijk.a > ijk.b && ijk.c > ijk.b && ijk.a > ijk.c)
	{
		stack_ra(mystruct);
		return (ft_strdup(" ra"));
	}
	else if (ijk.b > ijk.a && ijk.b > ijk.c && ijk.c > ijk.a)
	{
		stack_sa(mystruct);
		stack_ra(mystruct);
		return (ft_strdup(" sa ra"));
	}
	else if (ijk.b > ijk.a && ijk.b > ijk.c && ijk.a > ijk.c)
	{
		stack_rra(mystruct);
		return (ft_strdup(" rra"));
	}
	return (ft_strdup(""));
}

char	*get_ops_for_three(t_push_swap *mystruct)
{
	t_3_int	ijk;

	ijk.a = *(int *)mystruct->a.head->content;
	ijk.b = *(int *)mystruct->a.head->next->content;
	ijk.c = *(int *)mystruct->a.head->prev->content;
	if (ijk.a > ijk.b && ijk.c > ijk.b && ijk.c > ijk.a)
	{
		stack_sa(mystruct);
		return (ft_strdup(" sa"));
	}
	else if (ijk.a > ijk.b && ijk.b > ijk.c && ijk.a > ijk.c)
	{
		stack_sa(mystruct);
		stack_rra(mystruct);
		return (ft_strdup(" sa rra"));
	}
	return (get_ops_for_three_helper(mystruct, ijk));
}

char	*three_sort(t_push_swap *mystruct)
{
	t_node_binary	*result_lst;
	char			*result_str;

	if (mystruct->a.n == 3)
		return (get_ops_for_three(mystruct));
	result_lst = NULL;
	while (mystruct->a.n > 3)
	{
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pb")));
		stack_pb(mystruct);
	}
	ft_nodbinadd_front(&result_lst, ft_nodbinnew(get_ops_for_three(mystruct)));
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}
