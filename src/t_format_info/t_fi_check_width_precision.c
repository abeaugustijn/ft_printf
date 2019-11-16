/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_check_width_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:50:18 by abe               #+#    #+#             */
/*   Updated: 2019/11/12 19:54:10 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>

void			t_fi_check_width_precision(t_format_info *info, va_list *args)
{
	if (info->expect_width_arg)
		info->width = (int)va_arg(*args, int);
	if (info->expect_precision_arg)
		info->precision = (int)va_arg(*args, int);
}
