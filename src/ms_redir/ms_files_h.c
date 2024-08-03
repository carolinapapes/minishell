/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_files_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:03:55 by capapes           #+#    #+#             */
/*   Updated: 2024/08/03 16:50:47 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ms_redir.h"
#include "ms_err.h"
#include <unistd.h>
#include <fcntl.h>

int	file_create(t_input *input)
{
	input->fd[FD_READ] = open(input->file, O_RDWR | O_CREAT | O_TRUNC, RW_R_R);
	if (input->fd[FD_READ] == -1)
		return (ms_err_print("here doc", errno));
	return (0);
}

int	file_unlink(t_input *input)
{
	if (unlink(input->file) == -1)
	{
		ms_fd_close(&input->fd[FD_READ]);
		return (ms_err_print("unlink", errno));
	}
	return (0);
}
