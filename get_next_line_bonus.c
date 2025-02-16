/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:05:22 by apchelni          #+#    #+#             */
/*   Updated: 2024/12/10 15:45:49 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fd_buf	fd_arr[MAX_FD];
	t_line			line;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line.str = NULL;
	line.str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line.str)
		return (NULL);
	line.str_len = 0;
	line.size = BUFFER_SIZE;
	while (1)
	{
		status = read_line(&fd_arr[fd], fd, &line);
		if (status <= 0)
			return (free(line.str), NULL);
		else if (status == 1)
			break ;
	}
	line.str[line.str_len] = '\0';
	return (line.str);
}
/* 
#include <stdio.h>

int	main(void)
{
	int		fd[3];
	char	*line;
	int		active = 3;
	int		i;

	fd[0] = open("test.txt", O_RDONLY);
	fd[1] = open("tes2.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	while (active > 0)
	{
		i = -1;
		while (++i < 3)
		{
			line = get_next_line(fd[i]);
			if (line != NULL)
			{
				printf ("%s", line);
				free(line);
			}
			else
			{
				if (fd[i] != -1)
					close(fd[i]);
				fd[i] = -1;
				active--;
			}
		}
	}
} */