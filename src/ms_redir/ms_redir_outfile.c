/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_outfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:07:58 by capapes           #+#    #+#             */
/*   Updated: 2024/07/25 00:11:17 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ms_redir.h"
#include <errno.h>

static int	get_open_args(t_output *output)
{
	if (output->type == FILEOUT)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	if (output->type == FILEAPPEND)
		return (O_WRONLY | O_CREAT | O_APPEND);
}

/*
 * @brief Redirects the output to a file or a pipe
 * 
 * @param output The output structure
 * @return int 1 if an error occured, 0 otherwise
 */

int	ms_redir_outfile(t_output *output)
{
	int	open_args;

	if (output->type == FILEOUT || output->type == FILEAPPEND)
	{
		open_args = get_open_args(output);
		output->fd[FD_WRITE] = open(output->file, open_args, RW_R_R);
		if (output->fd[FD_WRITE] == -1)
			return (
				printf("minishell: %s: %s\n", output->file,
					strerror(errno)), errno);
		return (0);
	}
	else if (output->type == PIPEOUT)
		pipe(output->fd);
	return (0);
}
