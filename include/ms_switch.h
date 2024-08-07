/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_switch.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:40:15 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 19:36:26 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SWITCH_H
# define MS_SWITCH_H

# include "ms_redir.h"

typedef struct s_case_handler_func
{
	int type;
	int (*fn)(void *);
} t_case_handler_func;

typedef struct s_case_handler_int
{
    int key;
    int value;
} t_case_handler_int;

int ms_switch_func(int option, const t_case_handler_func handlersSet[], t_io *param);
int ms_switch_int(int option, const t_case_handler_int	handlersSet[]);

# endif