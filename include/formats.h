/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formats.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:33 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:22:33 by aaugusti      ########   odam.nl         */
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
