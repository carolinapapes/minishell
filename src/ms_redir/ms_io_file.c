/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_io_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:32:03 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 20:23:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_err.h"
#include "ms_redir.h"
#include "ms_switch.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

static const t_case_handler_int open_args[] = {
	{FILEIN, O_RDONLY},
	{FILEOUT, O_WRONLY | O_CREAT | O_TRUNC},
	{FILEAPPEND, O_WRONLY | O_CREAT | O_APPEND},
	{-1, 0},
};

static const t_case_handler_int fd_type[] = {
	{IN, FD_READ},
	{OUT, FD_WRITE},
	{-1, -1},
};

static int io_open(t_io *io, int fd_type, int flags)
{
	io->fd[fd_type] = open(io->file, flags, RW_R_R);
	if (io->fd[fd_type] == -1)
		return(ms_err_print(io->file, errno));
	return (0);
}

int	io_file(t_io *io)
{
	int	fd_type;
	int flags;

	fd_type = ms_find(io->type, fd_type);
	flags = ms_find(io->type, open_args);
	return(io_open(io, fd_type, flags));
}