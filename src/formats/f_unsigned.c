/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:22:10 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/06 15:52:34 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>
#include <sizes.h>
#include <libft.h>
#include <utils.h>

void			f_unsigned_print(t_format_info *info, unsigned long long to_put,
		unsigned int print_len, int *res)
{
	int				n_zero;
	int				i;
	unsigned int	use_width;

	use_width = info->has_width && (info->width > info->precision);
	if (info->has_precision && !info->precision)
		return ;
	if (info->force_sign)
		ft_putchar_fd_count('+', FD, res);
	else if (info->has_space)
		ft_putchar_fd_count(' ', FD, res);
	n_zero = print_len - (info->force_sign || info->has_space)
		- ft_unsignedlen(to_put);
	if (n_zero > 0)
	{
		i = 0;
		while (i < n_zero)
		{
			ft_putchar_fd_count('0', FD, res);
			i++;
		}
	}
	ft_putunsigned_fd(to_put, FD);
}

unsigned int	f_unsigned_get_print_len(t_format_info *info,
		unsigned long long to_put)
{
	size_t			og_len;
	unsigned int	res;

	og_len = ft_unsignedlen(to_put);
	res = og_len;
	if (info->has_precision && !info->precision)
		return (0);
	if (info->has_precision && (info->precision > og_len))
		res = info->precision;
	if (info->force_sign || info->has_space)
		res++;
	if (info->has_precision && info->has_width)
		return (res);
	if (info->zero_pad && info->has_width)
		res = info->width > og_len ? info->width : og_len;
	return (res);
}

int		f_unsigned(t_format_info *info, va_list *args)
{
	unsigned long long	to_put;
	int					res;
	unsigned int		print_len;
	unsigned int		i;

	res = 0;
	to_put = sz_hex(info, args);
	print_len = f_unsigned_get_print_len(info, to_put);
	if (info->left_align)
		f_unsigned_print(info, to_put, print_len, &res);
	if (info->width > print_len)
	{
		i = 0;
		while (i < info->width - print_len)
		{
			ft_putchar_fd(' ', FD);
			i++;
		}
		res += i;
	}
	if (!info->left_align)
		f_unsigned_print(info, to_put, print_len, &res);
	return (res);
}
