/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_fd_h.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:55:18 by capapes           #+#    #+#             */
/*   Updated: 2024/07/25 16:40:38 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>

/*
 * @brief Closes a file descriptor and assings -1 to it. 
 * If the file descriptor is already -1, it does nothing.
 * 
 * @param fd The file descriptor 
 * @return int errno if an error occured, 0 otherwise
 */

int	ms_fd_close(int *fd)
{
	if (*fd == -1)
		return (0);
	if (close(*fd) == -1)
		return (errno);
	*fd = -1;
	return (0);
}

int	ms_fd_close_all(int *fd)
{
	int	err;

	err = 0;
	if (fd[0] != -1)
		err = ms_fd_close(&fd[0]);
	if (fd[1] != -1)
		err = ms_fd_close(&fd[1]);
	return (err);
}
