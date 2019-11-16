/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:49:17 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/16 15:44:47 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>

void	output(t_format_info *info, va_list *args)
{
	if (info->type == STRING)
		f_string(info, args);
	else if (info->type == CHAR)
		f_char(info, args);
	else if (info->type == INT)
		f_int(info, args);
	else if (info->type == PERCENTAGE)
		f_percentage();
}
