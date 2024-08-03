/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_outfile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:27:12 by capapes           #+#    #+#             */
/*   Updated: 2024/07/30 18:40:22 by capapes          ###   ########.fr       */
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
#include "test_ms_redir.h"

void	test_case_no_file(t_output *output)
{
	test_print_action("\nTest no file", BLUE);
	ms_redir_outfile(output);
	test_write_file(output, "new text\n");
	ms_fd_close(&output->fd[FD_WRITE]);
}

void	test_case_existing_file(t_output *output)
{
	test_print_action("\nTest existing file", BLUE);
	test_create_file(*output, "base text\n");
	ms_redir_outfile(output);
	test_write_file(output, "new text\n");
	ms_fd_close(&output->fd[FD_WRITE]);
}

void	test_case_existing_file_no_permissions(t_output *output)
{
	test_print_action("\nTest existing file no permissions", BLUE);
	test_create_file(*output, "base text\n");
	test_change_permissions(output->file, 0);
	ms_redir_outfile(output);
	ms_fd_close(&output->fd[FD_WRITE]);
}

void	test_case_directory(t_output *output)
{
	test_print_action("\nTest case directory", BLUE);
	if (mkdir(output->file, RWX_RWX_RWX) == -1)
		ms_err_print("mkdir", errno);
	ms_redir_outfile(output);
	ms_fd_close(&output->fd[FD_WRITE]);
}

void	remove_fileout()
{
	test_remove_file("fileout_test_1");
	test_remove_file("fileout_test_2");
	test_remove_file("fileout_test_3");
	test_remove_file("fileout_test_4");
}

void	fileappend_remove()
{
	test_remove_file("fileappend_test_1");
	test_remove_file("fileappend_test_2");
	test_remove_file("fileappend_test_3");
	test_remove_file("fileappend_test_4");
}

void	test_type_fileout()
{
	t_output	output;

	printf("\n\nTYPE FILEOUT\n");
	remove_fileout();
	output.type = FILEOUT;
	output.file = "fileout_test_1";
	test_case_no_file(&output);
	output.file = "fileout_test_2";
	test_case_existing_file(&output);
	output.file = "fileout_test_3";
	test_case_existing_file_no_permissions(&output);
	output.file = "fileout_test_4";
	test_case_directory(&output);
}

void	test_type_fileappend()
{
	t_output	output;

	printf("\n\nTYPE FILEAPPEND\n");
	fileappend_remove();
	output.type = FILEAPPEND;
	output.file = "fileappend_test_1";
	test_case_no_file(&output);
	output.file = "fileappend_test_2";
	test_case_existing_file(&output);
	output.file = "fileappend_test_3";
	test_case_existing_file_no_permissions(&output);
	output.file = "fileappend_test_4";
	test_case_directory(&output);
}

void	full_test_outfile(void)
{
	test_type_fileout();
	test_type_fileappend();
}
