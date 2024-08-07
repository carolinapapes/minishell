/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_redir.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:53:01 by capapes           #+#    #+#             */
/*   Updated: 2024/08/07 19:30:13 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MS_REDIR_H
# define TEST_MS_REDIR_H

# include "ms_redir.h"

void	full_test_outfile(void);
void	test_print_action(char *action, char *color);
void	test_change_permissions(char *file, int permissions);
void	test_create_file(t_io output, char *content);
int		test_is_dir(char *file);
void	test_remove_file(char *file);
int		test_write_file(t_io *output, char *content);

#endif