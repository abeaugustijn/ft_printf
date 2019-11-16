/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:02:44 by abe               #+#    #+#             */
/*   Updated: 2019/11/16 11:27:19 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <t_format_info.h>

void	f_int(t_format_info *info, va_list *args)
{
	int				to_put;
	unsigned int	i;
	int				int_len;

	to_put = (int)va_arg(*args, int);
	if (info->left_align)
		ft_putnbr_fd(to_put, FD);
	int_len = (int)ft_intlen(to_put);
	if (info->has_width)
	{
		i = 0;
		while (i < info->width - int_len)
		{
			ft_putchar_fd(info->zero_pad ? '0' : ' ', FD);
			i++;
		}
	}
	if (!info->left_align)
		ft_putnbr_fd(to_put, FD);
}
