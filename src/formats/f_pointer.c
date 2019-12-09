/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:44:48 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/09 12:19:00 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>

/*
**	This is just a wrapper around f_hex, which sets some additional flags to
**	format the pointer correctly.
*/

int		f_pointer(t_format_info *info, va_list *args)
{
	info->hex_identifier = TRUE;
	info->has_size = TRUE;
	info->size = LL;
	return (f_hex(info, args));
}
