/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:02:44 by abe               #+#    #+#             */
/*   Updated: 2019/11/16 22:18:59 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <t_format_info.h>

void			f_int_putnbr(t_format_info *info, va_list *args)
{
	
}

unsigned int	f_int_get_intlen(t_format_info *info, int to_put)
{
	unsigned int og_intlen;

	og_intlen = ft_intlen(to_put);
	if (to_put > 0 && info->force_sign)
		og_intlen++;

	return (og_intlen);
}

unsigned int	f_int_print_padding(t_format_info* info, unsigned int int_len)
{
	unsigned int i;

	i = 0;
	if (info->has_width)
	{
		while (i < info->width - int_len)
		{
			ft_putchar_fd(info->has_space ? ' ' : '0', FD);
			i++;
		}
	}
	return (i);
}

void			f_int(t_format_info *info, va_list *args)
{
	int				to_put;
	unsigned int	int_len;

	to_put = (int)va_arg(*args, int);
	t_fi_handle_sign(info, to_put);
	t_fi_handle_plus_space(info);
	to_put = to_put < 0 ? to_put * -1 : to_put;
	if (info->left_align)
		ft_putnbr_fd(to_put, FD);
	int_len = f_int_get_intlen(info, to_put);
	f_int_print_padding(info, int_len);
	if (!info->left_align)
		ft_putnbr_fd(to_put, FD);
}
