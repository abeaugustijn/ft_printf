/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_pointer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:44:48 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:13:28 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>

/*
**	This is just a wrapper around f_hex, which sets some additional flags to
**	format the pointer correctly.
*/

int		f_pointer(t_format_info *info, va_list *args, int n)
{
	(void)n;
	info->hex_identifier = true;
	info->has_size = true;
	info->size = LL;
	return (f_hex(info, args, n));
}
