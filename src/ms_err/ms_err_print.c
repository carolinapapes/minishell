/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_err_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:24:48 by capapes           #+#    #+#             */
/*   Updated: 2024/07/30 16:07:08 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ms_err_print(char *str, int err)
{
	printf("minishell: %s: %s\n", str, strerror(err));
	return (err);
}
