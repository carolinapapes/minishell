/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:35:50 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 19:28:28 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# ifndef MS_REDIR_H
#  include "ms_redir.h"
# endif

typedef enum e_cmd
{
	BUILTIN,
	EXTERNAL
}	t_cmd_types;

typedef enum e_builtin
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_builtin_types;


typedef struct s_cmd
{
	t_io		input_;
	t_io		output;
	char		*cmd;
	char		*path;
	char		**args;
	int		exit_status;
}	t_cmd;

#endif