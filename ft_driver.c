/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_driver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:59:27 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 11:30:13 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	mystruct;

	initialize_struct(&mystruct, argc);
	if (argc < 2)
		ft_error(&mystruct);
	parse_input(&mystruct, argc, argv);
	// order_stack_algo(&mystruct);
	game_loop(&mystruct);
	return (0);
}
