/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_err.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:27:07 by capapes           #+#    #+#             */
/*   Updated: 2024/07/30 16:39:42 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ERR_H
# define MS_ERR_H

// Text color definitions
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"  // Reset to default color

int	ms_err_print(char *str, int err);

#endif