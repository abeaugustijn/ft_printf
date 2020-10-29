/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:35 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:22:35 by aaugusti      ########   odam.nl         */
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
