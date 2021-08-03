/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_driver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:59:27 by edavid            #+#    #+#             */
/*   Updated: 2021/08/03 18:30:06 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	sequence = LIS_sort(&mystruct);
	sequence_arr = ft_split(sequence, ' ');
	i = -1;
	while (sequence_arr[++i])
		ft_printf("%s\n", sequence_arr[i]);
	// ft_printf("Sequence: %s\n", sequence);
	// ft_printf("Number of operations: %d\n", ft_n_of_words_by_delim(sequence, ' '));
	// game_loop(&mystruct);
	return (0);
}
// 1 3 2 -5 6 4 0 -23
// ra pb ra pb pb ra pb pb rb pa pa rb rb pb rb rb rb pb pa ra ra ra pa ra ra pa ra pa ra pa rra