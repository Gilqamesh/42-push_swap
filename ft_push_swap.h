/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:41:50 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 15:06:55 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

#include "mylib/libft/libft.h"
#include "mylib/printf/ft_printf.h"
typedef struct	s_stack
{
	int	*array;
	int	counter;
}	t_stack;
void	parse_input(int argc, char **argv);
void	ft_error(void);

#endif
