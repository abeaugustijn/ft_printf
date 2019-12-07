/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_check_width_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:50:18 by abe               #+#    #+#             */
/*   Updated: 2019/12/07 14:00:46 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>

/*
**	Get the next argument if there is a '*' flag for with or precision set.
**	The value gets stored in the info object.
*/

void			t_fi_check_width_precision(t_format_info *info, va_list *args)
{
	int	tmp_width;

	if (info->expect_width_arg)
	{
		tmp_width = (int)va_arg(*args, int);
		if (tmp_width < 0)
		{
			info->width = tmp_width * -1;
			info->left_align = TRUE;
		}
		else
			info->width = tmp_width;
	}
	if (info->expect_precision_arg)
		info->precision = (int)va_arg(*args, int);
}
