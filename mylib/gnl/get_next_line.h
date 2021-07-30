/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:03:30 by edavid            #+#    #+#             */
/*   Updated: 2021/07/30 16:32:48 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "../libft/libft.h"

int		get_next_line(int fd, char **line);
int		contains_newline(char *str, size_t n);
// Allocates a new string that is the result of joining together 's1' and 's2'
// Also frees s1 and s2 as a side effect
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strdup_v2(const char *s, int n);

#endif
