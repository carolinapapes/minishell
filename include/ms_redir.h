/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:05:30 by capapes           #+#    #+#             */
/*   Updated: 2024/08/03 15:50:02 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_REDIR_H
# define MS_REDIR_H

# define RW_R_R 		0644
# define RW_0_0			0600
# define RWX_RWX_RWX 	0777
# define RWX_RWX_R		0755

# define FD_WRITE 		1
# define FD_READ  		0

# define FILENAME ".minishell_heredoc_tmp"

typedef enum e_input
{
	FILEIN,
	HEREIN,
	PIPEIN,
	STDIN
}	t_input_types;

typedef enum e_output
{
	FILEOUT,
	FILEAPPEND,
	PIPEOUT,
	STDOUT
}	t_output_types;

typedef struct s_input
{
	char			*file;
	int				fd[2];
	t_input_types	type;
}	t_input;

typedef struct s_output
{
	int				fd[2];
	char			*file;
	t_output_types	type;
}	t_output;

int	ms_fd_close(int *fd);
int	ms_redir_outfile(t_output *output);

#endif

