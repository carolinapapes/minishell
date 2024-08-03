/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:56:40 by capapes           #+#    #+#             */
/*   Updated: 2024/07/30 18:54:24 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ms_redir.h"
#include "ms_err.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

void	test_print_action(char *action, char *color)
{
	fprintf(stderr, "%s%s%s\n", color, action, RESET);
}

void	test_change_permissions(char *file, int permissions)
{
	if (chmod(file, permissions) == -1)
		ms_err_print("chmod", errno);
}

void	test_create_file(t_output output, char *content)
{
	output.fd[FD_WRITE] = open(output.file, O_WRONLY | O_CREAT | O_TRUNC, RW_R_R);
	if (content)
		write(output.fd[FD_WRITE], content, strlen(content));
	close(output.fd[FD_WRITE]);
}

int	test_is_dir(char *file)
{
	struct stat	sb;

	return (stat(file, &sb) == 0 && S_ISDIR(sb.st_mode));
}

void	test_remove_file(char *file)
{
	if (access(file, F_OK) != -1)
	{
		if (test_is_dir(file))
			rmdir(file);
		else
			unlink(file);
	}
}

int	test_write_file(t_output *output, char *content)
{
	if (write(output->fd[FD_WRITE], content, strlen(content)) == -1)
	{
		ms_err_print("test_write_file", errno);
		return (1);
	}
	return (0);
}
