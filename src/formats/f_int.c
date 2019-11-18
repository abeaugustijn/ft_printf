/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:02:44 by abe               #+#    #+#             */
/*   Updated: 2019/11/18 20:07:50 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <t_format_info.h>

void			f_int_putnbr(t_format_info *info, t_bool is_neg,
		long long int to_put)
{
	unsigned int	og_intlen;
	unsigned int	i;

	og_intlen = ft_ull_len(to_put);
	if (info->has_space)
		ft_putchar_fd(' ', FD);
	if (info->force_sign && to_put > 0)
		ft_putchar_fd('+', FD);
	if (info->has_precision && info->precision > og_intlen)
	{
		i = 0;
		while (i < og_intlen - info->precision)
		{
			ft_putchar_fd('0', FD);
			i++;
		}
	}
}

unsigned int	f_int_get_intlen(t_format_info *info, int to_put)
{
	unsigned int	res;

	res = ft_intlen(to_put);
	if (info->has_precision && info->precision > res)
		res = info->precision;
	if (to_put > 0 && (info->has_sign || info->has_space))
		res++;
	return (res);
}

unsigned int	f_int_print_padding(t_format_info* info, unsigned int int_len)
{
	unsigned int i;

	i = 0;
	if (info->has_width && !info->zero_pad)
		while (i < info->width - int_len)
		{
			ft_putchar_fd(' ', FD);
			i++;
		}
	return (i);
}

int				f_int(t_format_info *info, va_list *args)
{
	long long int	to_put;
	unsigned int	int_len;
	int				res;
	t_bool			is_neg;

	res = 0;
	to_put = (int)va_arg(*args, int);
	t_fi_handle_sign(info, to_put);
	t_fi_handle_plus_space(info);
	is_neg = to_put < 0;
	to_put = is_neg ? to_put * -1 : to_put;
	if (info->left_align)
		ft_putnbr_fd(to_put, is_neg, FD);
	int_len = f_int_get_intlen(info, to_put);
	f_int_print_padding(info, int_len);
	if (!info->left_align)
		ft_putnbr_fd(to_put, is_neg, FD);
	return (res);
}
