/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:10:42 by edavid            #+#    #+#             */
/*   Updated: 2021/07/01 13:57:26 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>

static int	reset_ret(char **line, int ret, char **buf_p)
{
	if (!ret && line)
	{
		*line = malloc(1);
		**line = '\0';
	}
	if (buf_p)
	{
		free(*buf_p);
		*buf_p = (char *)0;
	}
	return (ret);
}

static int	get_next_line2(char **buf, int buf_len,
char **line, int fd)
{
	char	*tmp_str;
	int		tmp_index;

	tmp_str = ft_strdup_v2(buf[fd], buf_len);
	free(buf[fd]);
	buf_len += BUFFER_SIZE;
	buf[fd] = malloc(buf_len + 1);
	tmp_index = read(fd, buf[fd], BUFFER_SIZE);
	if (tmp_index <= 0)
	{
		if (tmp_index == 0)
			*line = tmp_str;
		else
			free(tmp_str);
		return (reset_ret((char **)0, tmp_index, &buf[fd]));
	}
	buf[fd][tmp_index] = '\0';
	buf[fd] = ft_strjoin_v3(&tmp_str, &buf[fd]);
	return (get_next_line(fd, line));
}

int	get_next_line(int fd, char **line)
{
	int				tmp_index;
	int				buf_len;
	static char		*buffers[OPEN_MAX] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!buffers[fd])
	{
		buffers[fd] = malloc(BUFFER_SIZE + 1);
		if (!buffers[fd])
			return (-1);
		buf_len = BUFFER_SIZE;
		tmp_index = read(fd, buffers[fd], BUFFER_SIZE);
		if (tmp_index <= 0)
			return (reset_ret(line, tmp_index, &buffers[fd]));
		buffers[fd][tmp_index] = '\0';
		return (get_next_line(fd, line));
	}
	buf_len = ft_strlen(buffers[fd]);
	tmp_index = contains_newline(buffers[fd], buf_len);
	if (tmp_index == buf_len)
		return (get_next_line2(buffers, buf_len, line, fd));
	*line = ft_strdup_v2(buffers[fd], tmp_index);
	ft_memmove(buffers[fd], buffers[fd] + tmp_index + 1, buf_len - tmp_index);
	return (1);
}
