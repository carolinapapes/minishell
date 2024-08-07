/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:05:30 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 19:34:56 by capapes          ###   ########.fr       */
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

typedef enum e_io
{
	OUT = 1,
	IN = 1 << 2,
	IO_FILE = 1 << 3,
	PIPE = 1 << 4,
	STD = 1 << 5,
	HERE = 1 << 6,
	APPEND = 1 << 7,
	FILEIN = IN | IO_FILE,
	HEREIN = IN | HERE,
	PIPEIN = IN | PIPE,
	STDIN = IN | STD,
	PIPEOUT = OUT | PIPE,
	STDOUT = OUT | STD,
	FILEOUT = OUT | IO_FILE,
	FILEAPPEND = APPEND | FILEOUT,
}	t_io_types;

typedef struct s_io
{
	char			*file;
	int				fd[2];
	t_io_types		type;
}	t_io;

int	ms_fd_close(int *fd);

int	io_file(t_io *io);

#endif

