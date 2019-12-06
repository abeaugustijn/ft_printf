/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sz_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 09:33:03 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/06 10:31:20 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>

long long int	sz_int(t_format_info *info, va_list *args)
{
	if (!info->has_size)
		return ((int)va_arg(*args, int));
	if (info->size == HH)
		return ((signed char)va_arg(*args, signed char));
	if (info->size == H)
		return ((short int)va_arg(*args, short int));
	if (info->size == LL)
		return ((long int)va_arg(*args, long int));
	if (info->size == L)
		return ((long long int)va_arg(*args, long long int));
	return ((int)va_arg(*args, int));
}
