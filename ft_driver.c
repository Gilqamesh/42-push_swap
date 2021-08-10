/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_driver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:59:27 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 20:12:51 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	print_operations(char *ops)
{
	while (*ops)
	{
		while (*ops == ' ')
			ops++;
		while (*ops && *ops != ' ')
		{
			ft_printf("%c", *ops);
			ops++;
		}
		while (*ops && *ops == ' ')
			ops++;
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	mystruct;
	char		*sequence;

	ft_bzero(&mystruct, sizeof(mystruct));
	if (argc < 2)
		ft_error(&mystruct);
	parse_input(&mystruct, argc, argv);
	sequence = LIS_sort(&mystruct);
	print_operations(sequence);
	free(sequence);
	return (0);
}
