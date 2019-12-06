/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:44:48 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/06 14:59:59 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <libft.h>

int		f_pointer(t_format_info *info, va_list *args)
{
	info->hex_identifier = TRUE;
	info->has_size = TRUE;
	info->size = LL;
	return (f_hex(info, FALSE, args));
}
