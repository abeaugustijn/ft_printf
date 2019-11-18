/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:58:28 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/18 14:10:42 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H
# include <ft_printf.h>

int		f_string(t_format_info *info, va_list *args);
int		f_char(t_format_info *info, va_list *args);
int		f_int(t_format_info *info, va_list *args);
int		f_percentage();

#endif
