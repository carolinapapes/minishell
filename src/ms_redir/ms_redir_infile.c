/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_infile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:12:17 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 19:48:13 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ms_redir.h"
#include <errno.h>
#include <unistd.h>

// static int	filein(t_io *input)
// {
// 	input->fd[FD_READ] = open(input->file, O_RDONLY);
// 	if (input->fd[FD_READ] == -1)
// 		return (ms_err_print(input->file, errno));
// 	return (0);
// }



static int	herein(t_io *input)
{
	input->fd[FD_READ] = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, RW_R_R);
	if (input->fd[FD_READ] == -1)
		return (ms_err_print("here doc", errno));
	return (0);
}

int	set_stdin(t_io *input)
{
	input->fd[FD_READ] = STDIN_FILENO;
	return (0);
}

/*
 * @brief Redirects the input to a file or a pipe
 * 
 * @param input The input structure
 * @return int 1 if an error occured, 0 otherwise
 */

void	ms_redir_infile(t_io *input)
{
	if (input->type == FILEIN)
		return (filein(input));
	if (input->type == PIPEIN)
		return (pipein(input));
	if (input->type == HEREIN)
		return (herein(input));
	if (input->type == STDIN)
		set_stdin(input);
}
