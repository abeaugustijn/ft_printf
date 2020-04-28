/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sz_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 11:54:12 by aaugusti      #+#   #+#                  */
/*   Updated: 2019/12/13 19:22:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <stdarg.h>
#include <sizes.h>

/*
**	Size conversion for hexadecimal formats.
*/

long long int	sz_hex(t_format_info *info, va_list *args)
{
	if (info->has_size)
	{
		if (info->size == HH)
			return ((unsigned char)va_arg(*args, int));
		if (info->size == H)
			return ((unsigned short int)va_arg(*args, int));
		if (info->size == L)
			return ((unsigned long int)va_arg(*args, unsigned long int));
		if (info->size == LL)
			return ((unsigned long long int)va_arg(*args,
						unsigned long long int));
	}
	return ((unsigned int)va_arg(*args, unsigned int));
}
