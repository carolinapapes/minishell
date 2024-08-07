/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:39:35 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 19:43:27 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_switch.h"
#include "ms_redir.h"

int ms_switch_func(int option, const t_case_handler_func handlersSet[], void *param)
{
	int i;

	i = 0;
	while (handlersSet[i].type != -1)
	{
		if (handlersSet[i].type == option)
			return handlersSet[i].fn(param);
		i++;
	}
	return 0;
}

int ms_switch_func_io(int option, const t_case_handler_func handlersSet[], t_io *param)
{
	return (ms_switch_func(option, handlersSet, (void *)param));
}

int ms_find(int option, const t_case_handler_int handlersSet[])
{
	int i;

	i = 0;
	while(handlersSet[i].key != -1)
	{
		if (handlersSet[i].key == option)
			return handlersSet[i].value;
		i++;
	}
	return (0);
}