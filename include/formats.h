/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:58:28 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/09 12:14:45 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H
# include <t_format_info.h>
# include <stdarg.h>

int		f_string(t_format_info *info, va_list *args);
int		f_char(t_format_info *info, va_list *args);
int		f_int(t_format_info *info, va_list *args);
int		f_unsigned(t_format_info *info, va_list *args);
int		f_hex(t_format_info *info, va_list *args);
int		f_pointer(t_format_info *info, va_list *args);
int		f_percentage(t_format_info *info);
int		f_n(va_list *args, int n);

#endif
