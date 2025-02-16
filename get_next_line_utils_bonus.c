/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:05:22 by apchelni          #+#    #+#             */
/*   Updated: 2024/12/10 15:46:24 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	increase_size(t_line *line)
{
	char	*new_str;
	int		j;

	(line->size) += BUFFER_SIZE;
	new_str = NULL;
	new_str = malloc((line->size + 1) * sizeof(char));
	if (!new_str)
		return (-1);
	j = -1;
	while (++j < line->str_len)
		new_str[j] = (line->str)[j];
	free(line->str);
	line->str = new_str;
	return (1);
}

int	copy_from_buffer(t_fd_buf *fd_buf, t_line *line)
{
	int	i;

	i = 0;
	while (fd_buf->buf[i] != '\0')
	{
		if (line->str_len >= line->size)
			if (!increase_size(line))
				return (-1);
		(line->str)[(line->str_len)++] = fd_buf->buf[i++];
		if (fd_buf->buf[i - 1] == '\n')
			break ;
	}
	return (i);
}

void	update_buffer(t_fd_buf *fd_buf, int start)
{
	int	j;

	j = 0;
	while (fd_buf->buf[start] != '\0')
		fd_buf->buf[j++] = fd_buf->buf[start++];
	fd_buf->buf[j] = '\0';
}

int	read_line(t_fd_buf *fd_buf, int fd, t_line *line)
{
	int	bytes_read;
	int	copied_len;

	if (fd_buf->buf[0] == '\0')
	{
		bytes_read = read(fd, fd_buf->buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
		{
			if (line->str_len == 0)
				return (0);
			return (1);
		}
		fd_buf->buf[bytes_read] = '\0';
	}
	copied_len = copy_from_buffer(fd_buf, line);
	if (copied_len < 0)
		return (-1);
	update_buffer(fd_buf, copied_len);
	if (line->str_len > 0 && (line->str)[line->str_len - 1] == '\n')
		return (1);
	return (2);
}
