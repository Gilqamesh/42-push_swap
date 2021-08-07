/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:55:15 by edavid            #+#    #+#             */
/*   Updated: 2021/08/07 20:41:56 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*tmp;	
	t_list	**tail;
	char	*s1 = "hello";
	char	*s2 = "hello2";
	char	*s3 = "hello3";

	lst = NULL;
	tail = &lst;
	ft_lstadd_back(&lst, ft_lstnew(s1));
	ft_lstadd_back(&lst, ft_lstnew(s2));
	ft_lstadd_back(&lst, ft_lstnew(s3));
	
	return (0);
}
