/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:13 by capapes           #+#    #+#             */
/*   Updated: 2024/07/25 16:56:26 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "ms_redir.h"

int	file_create(t_input *input)
{
	input->fd[FD_READ] = open(input->file, O_RDONLY);
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

int	here_doc_create(t_input *input)
{
	int	err;

	file_create(input);
	file_unlink(input);
	return (0);
}
