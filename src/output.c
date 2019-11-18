/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:49:17 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/18 14:24:00 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>

int		output(t_format_info *info, va_list *args)
{
	if (info->type == STRING)
		return (f_string(info, args));
	else if (info->type == CHAR)
		return (f_char(info, args));
	else if (info->type == INT)
		return (f_int(info, args));
	else if (info->type == PERCENTAGE)
		return (f_percentage());
	return (0);
}
