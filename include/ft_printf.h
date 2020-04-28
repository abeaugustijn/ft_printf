/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:02:10 by abe        #+#   #+#                     */
/*   Updated: 2020/04/28 13:45:50 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "t_format_info.h"

# define FD 1

int				ft_printf(const char *format, ...);
int				handle_format(char **tgt, char **format, va_list *args, int n);
int				output(t_format_info *info, va_list *args, int n);

#endif
