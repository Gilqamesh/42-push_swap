/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_driver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:59:27 by edavid            #+#    #+#             */
/*   Updated: 2021/08/07 00:00:45 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pb
// pb
// ra
// pb
// ra
// pb
// ra
// rrb
// ra
// ra
// ra

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	mystruct;
	char		*sequence;
	char		**sequence_arr;
	int			i;

	initialize_struct(&mystruct, argc);
	if (argc < 2)
		ft_error(&mystruct);
	parse_input(&mystruct, argc, argv);
	// PRINT_HERE();
	// sequence = LIS_sort2(&mystruct);
	sequence = LIS_sort(&mystruct);
	sequence_arr = ft_split(sequence, ' ');
	crunch_sequence(sequence_arr);
	i = -1;
	// while (sequence_arr[++i])
	// 	ft_printf("%s\n", sequence_arr[i]);
	ft_printf("Sequence: %s\n", sequence);
	ft_printf("Number of arguments: %d\n", mystruct.a.n);
	ft_printf("Number of operations: %d\n", ft_n_of_words_by_delim(sequence, ' '));
	// game_loop(&mystruct);
	free(sequence);
	// i = -1;
	// while (sequence_arr[++i])
	// 	free(sequence_arr[i]);
	// free(sequence_arr);
	// system("leaks push_swap");
	return (0);
}
