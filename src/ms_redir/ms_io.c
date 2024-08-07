/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:07:58 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 19:48:04 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_err.h"
#include "ms_redir.h"
#include "ms_switch.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>


static int default_handler(t_io *output)
{
	output->fd[FD_WRITE] = STDOUT_FILENO;
	return (0);
}


static const t_case_handler_func ioHandlers[] = {
        { IO_FILE, io_file },
        { PIPEOUT, pipeout},
        { STD, default_handler},
        { -1, default_handler }
};



/*
 * @brief Redirects the input / output to a file, a pipe or stdout
 * 
 * @param output The output structure
 * @return int 1 if an error occured, 0 otherwise
 */

int	ms_redir_io(t_io *output)
{
	return (ms_switch(output->type, ioHandlers, output));
}





