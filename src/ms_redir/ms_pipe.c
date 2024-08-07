/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:47:47 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 20:30:26 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_redir.h"
#include "ms_switch.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int open_pipe(t_io *io)
{
    if (pipe(io->fd) == -1)
        return (ms_err_print("pipe", errno));
    return (0);
}

static int pipe_close_one(t_io *io, int side)
{
    if (close(io->fd[side]) == -1)
        return (ms_err_print("close", errno));
}

static int pipe_stdup(t_io *io, int side)
{
    stdup(io->fd[side], side);
}

static int pipe_fn(t_io *io, int action)
{
    int side;

    side = ms_find(io->type, fd_type);
    if (action)
    {
        pipe_close_one(io, side);
        pipe_stdup(io, !side);
    }
    else
        pipe_close_one(io, !side);
    return (0);
}