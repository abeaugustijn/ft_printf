/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sz_int.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 09:33:03 by aaugusti      #+#   #+#                  */
/*   Updated: 2019/12/13 19:22:54 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <stdarg.h>
#include <sizes.h>

/*
**	Size conversion for integer formats.
*/

long long int	sz_int(t_format_info *info, va_list *args)
{
	if (info->has_size)
	{
		if (info->size == HH)
			return ((signed char)va_arg(*args, int));
		if (info->size == H)
			return ((short int)va_arg(*args, int));
		if (info->size == L)
			return ((long int)va_arg(*args, long int));
		if (info->size == LL)
			return ((long long int)va_arg(*args, long long int));
	}
	return ((int)va_arg(*args, int));
}
