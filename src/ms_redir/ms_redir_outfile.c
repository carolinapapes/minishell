/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_outfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:07:58 by capapes           #+#    #+#             */
/*   Updated: 2024/07/31 16:17:03 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ms_redir.h"
#include "ms_err.h"
#include <errno.h>
#include <unistd.h>

static int	get_open_args(t_output *output)
{
	if (output->type == FILEOUT)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	if (output->type == FILEAPPEND)
		return (O_WRONLY | O_CREAT | O_APPEND);
	return (0);
}

static int	outfile(t_output *output)
{
	int	open_args;

	open_args = get_open_args(output);
	output->fd[FD_WRITE] = open(output->file, open_args, RW_R_R);
	if (output->fd[FD_WRITE] == -1)
		return (ms_err_print(output->file, errno));
	return (0);
}

static int	pipeout(t_output *output)
{
	if (pipe(output->fd) == -1)
		return (ms_err_print("pipe", errno));
	return (0);
}

static int	set_stdout(t_output *output)
{
	output->fd[FD_WRITE] = STDOUT_FILENO;
	return (0);
}

/*
 * @brief Redirects the output to a file, a pipe or stdout
 * 
 * @param output The output structure
 * @return int 1 if an error occured, 0 otherwise
 */

int	ms_redir_outfile(t_output *output)
{
	if (output->type == FILEOUT || output->type == FILEAPPEND)
		return (outfile(output));
	if (output->type == PIPEOUT)
		return (pipeout(output));
	if (output->type == STDOUT)
		return (set_stdout(output));
	return (0);
}