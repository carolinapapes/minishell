/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:13 by capapes           #+#    #+#             */
/*   Updated: 2024/07/31 16:04:31 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "ms_redir.h"
#include "ms_err.h"
#include <unistd.h>

int	here_doc_create(t_input *input)
{
	int	err;

	file_create(input);
	file_unlink(input);
	return (0);
}

int	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		i;
	int		read_qty;

	i = 0;
	buf = malloc(1000);
	while (1)
	{
		read_qty = read(fd, buf + i, 1);
		if (read_qty == -1)
			break ;
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			*line = buf;
			return (1);
		}
		i++;
	}
	buf[i] = '\0';
	*line = buf;
	return (0);
}

int	here_doc_get_data(t_input *input)
{
	char	*line;
	int		err;

	err = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strcmp(line, input->file) == 0)
			break ;
		ft_putendl_fd(line, input->fd[FD_READ]);
		free(line);
	}
	free(line);
	return (err);
}

