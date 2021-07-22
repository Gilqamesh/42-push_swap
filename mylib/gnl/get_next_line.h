/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:03:30 by edavid            #+#    #+#             */
/*   Updated: 2021/06/25 20:29:39 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		contains_newline(char *str, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin_v3(char **s1, char **s2);
char	*ft_strdup_v2(const char *s, int n);

#endif
