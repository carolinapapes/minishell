/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_infile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:12:17 by capapes           #+#    #+#             */
/*   Updated: 2024/07/25 14:14:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ms_redir.h"
#include <errno.h>

static int	filein(t_input *input)
{
	input->fd[0] = open(input->file, O_RDONLY);
	if (input->fd[0] == -1)
		return (errno);
	return (0);
}

static int	pipein(int *fd)
{
	if (pipe(fd) == -1)
		return (errno);
	return (0);
}

static int	herein(t_input *input)
{
	input->fd[0] = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, RW_R_R);
	if (input->fd[0] == -1)
		return (printf("minishell: %s: %s\n", ".tmp", strerror(errno)));
	return (0);
}

/*
 * @brief Redirects the input to a file or a pipe
 * 
 * @param input The input structure
 * @return int 1 if an error occured, 0 otherwise
 */

void	ms_redir_infile(t_input *input)
{
	if (input->type == FILEIN)
		return (filein(input));
	if (input->type == PIPEIN)
		return (pipein(input->fd));
	if (input->type == HEREIN)
		return (herein(input));
}
