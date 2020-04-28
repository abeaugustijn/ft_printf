/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formats.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:58:28 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 12:13:34 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H
# include <t_format_info.h>
# include <stdarg.h>

int		f_string(t_format_info *info, va_list *args, int n);
int		f_char(t_format_info *info, va_list *args, int n);
int		f_int(t_format_info *info, va_list *args, int n);
int		f_unsigned(t_format_info *info, va_list *args, int n);
int		f_hex(t_format_info *info, va_list *args, int n);
int		f_pointer(t_format_info *info, va_list *args, int n);
int		f_percentage(t_format_info *info, va_list *args, int n);
int		f_n(t_format_info *info, va_list *args, int n);

#endif
