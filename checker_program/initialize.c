/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:52:40 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 19:32:14 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	destroy_operations(t_push_swap *mystruct, char ***operations,
int index)
{
	while (index--)
		free((*operations)[index]);
	free(*operations);
	ft_error(mystruct);
}

static int	valid_function_name(char *str)
{
	int			i;
	static char	*operation_names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr", (char *)0};

	if (!str)
		return (0);
	i = -1;
	while (operation_names[++i])
		if (!ft_strncmp(str, operation_names[i], 3))
			return (1);
	return (0);
}

void	execute_operations(t_push_swap *mystruct, char **operations,
int number_of_ops)
{
	static	void	(*functions[])(t_push_swap *) = {stack_sa, stack_sb,
		stack_ss, stack_pa, stack_pb, stack_ra, stack_rb, stack_rr, stack_rra,
		stack_rrb, stack_rrr};
	static char		*operation_names[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr", (char *)0};
	char			*str;
	int				str_index;
	int				i;

	i = -1;
	while (++i < number_of_ops)
	{
		str_index = -1;
		while (ft_strncmp(operations[i], operation_names[++str_index], 3))
			;
		(*functions[str_index])(mystruct);
	}
}

void	read_operations(t_push_swap *mystruct)
{
	char		**operations;
	int			op_index;
	int			read_bytes;

	op_index = 0;
	operations = (char **)0;
	while (1)
	{
		operations = ft_realloc(operations, ++op_index * sizeof(*operations));
		read_bytes = get_next_line(0, operations + op_index - 1);
		if (read_bytes < 0)
			destroy_operations(mystruct, &operations, op_index - 1);
		if (!read_bytes)
			break ;
	}
	while (read_bytes < op_index - 1)
		if (!valid_function_name(operations[read_bytes++]))
			destroy_operations(mystruct, &operations, op_index);
	execute_operations(mystruct, operations, op_index - 1);
}
