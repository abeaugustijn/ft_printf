/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:49:17 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/06 15:54:27 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <formats.h>
#include <stdarg.h>

int		output(t_format_info *info, va_list *args)
{
	if (info->type == STRING)
		return (f_string(info, args));
	else if (info->type == CHAR)
		return (f_char(info, args));
	else if (info->type == INT)
		return (f_int(info, args));
	else if (info->type == PERCENTAGE)
		return (f_percentage(info));
	else if (info->type == HEX_UP)
		return (f_hex(info, TRUE, args));
	else if (info->type == HEX_LOW)
		return (f_hex(info, FALSE, args));
	else if (info->type == POINTER)
		return (f_pointer(info, args));
	else if (info->type == UNSIGNED)
		return (f_unsigned(info, args));
	return (0);
}
