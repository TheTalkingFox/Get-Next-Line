/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:05:22 by apchelni          #+#    #+#             */
/*   Updated: 2024/12/10 15:46:01 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct fd_buf
{
	char	buf[BUFFER_SIZE + 1];
}			t_fd_buf;

typedef struct line_stat
{
	char	*str;
	int		size;
	int		str_len;
}			t_line;

char		*get_next_line(int fd);
int			read_line(t_fd_buf *fd_buf, int fd, t_line *line);
int			increase_size(t_line *line);
int			copy_from_buffer(t_fd_buf *fd_buf, t_line *line);

#endif