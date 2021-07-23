/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:31:09 by edavid            #+#    #+#             */
/*   Updated: 2021/07/23 16:34:47 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	mystruct;

	if (argc < 2)
		return (0);
	initialize_struct(&mystruct, argc);
	parse_input(&mystruct, argc, argv);
	read_operations(&mystruct);
	print_stacks(&mystruct);
	if (is_solution(&mystruct))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
