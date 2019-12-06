/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:11:57 by aaugusti          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/12/06 14:20:17 by aaugusti         ###   ########.fr       */
=======
/*   Updated: 2019/11/26 14:14:08 by aaugusti         ###   ########.fr       */
>>>>>>> 85f13aa506e5b57ea4b7c97a71de09c4522d6026
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <t_format_info.h>
#include <libft.h>
#include <utils.h>
#include <stdlib.h>

/*
**	Print the integer. This is only the non-whitespace part of the int.
**	- first check negative; the first char in the case of a negative int is
**		always a minus
*/

void			f_hex_print(t_format_info *info, unsigned int to_put,
		t_bool cap, unsigned int print_len, int *res)
{
	unsigned int	is_neg;
	int				n_zero;
	int				i;
	unsigned int	use_width;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	use_width = info->has_width && (info->width > info->precision);
	if (info->has_precision && !info->precision)
		return ;
	if (is_neg || info->force_sign)
		ft_putchar_fd_count(is_neg ? '-' : '+', FD, res);
	else if (info->has_space)
		ft_putchar_fd_count(' ', FD, res);
<<<<<<< HEAD
	if (info->hex_identifier && to_put != 0)
		ft_putstr_fd(cap ? "0X" : "0x", FD);
	n_zero = print_len - (is_neg || info->force_sign || info->has_space)
		- ft_hexlen(to_put) - ((info->hex_identifier && to_put) ? 2 : 0);
	if (n_zero > 0)
=======
	n_zero = print_len - ((is_neg || info->force_sign || info->has_space)
			? 1 : 0) - ft_hexlen(to_put) - ((info->hex_identifier && to_put > 0) ? 2 : 0);
	if (info->hex_identifier && to_put != 0)
		ft_putstr_fd(cap ? "0X" : "0x", FD);
	if (n_zero > 0 && (info->has_precision && info->precision > 0))
>>>>>>> 85f13aa506e5b57ea4b7c97a71de09c4522d6026
	{
		i = 0;
		while (i < n_zero)
		{
			ft_putchar_fd_count('0', FD, res);
			i++;
		}
	}
	ft_puthex_fd(to_put, FD, cap);
}

/*
**	Get the amount of non-whitespace bytes that will be printed.
**	- in the case that width is set and there is a zero flag return the largest
**		of og_hexlen and width.
**	- if precision is set and precision is larger than og_hexlen return pre-
**		cision.
**		* also, if to_put is negative add a byte for the minus
**	- precision overwrites width
*/

unsigned int	f_hex_get_print_len(t_format_info *info, unsigned int to_put)
{
	size_t			og_hexlen;
	unsigned int	is_neg;
	unsigned int	res;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	og_hexlen = ft_hexlen(to_put);
	res = og_hexlen;
<<<<<<< HEAD
	if (info->has_precision && !info->precision)
		return (0);
	if (info->has_precision && (info->precision > og_hexlen))
		res = info->precision;
	if (info->hex_identifier && to_put)
=======
	if (info->has_precision && info->precision > og_hexlen)
		res = res > info->precision ? res : info->precision;
	if (info->hex_identifier && to_put != 0)
>>>>>>> 85f13aa506e5b57ea4b7c97a71de09c4522d6026
		res += 2;
	if (is_neg || info->force_sign || info->has_space)
		res++;
	if (info->has_precision && info->has_width)
		return (res);
	if (info->zero_pad && info->has_width)
		res = info->width > og_hexlen ? info->width : og_hexlen;
	return (res);
}

/*
**	The format function for formats of the type unsigned integer printed as hex.
*/

int				f_hex(t_format_info *info, t_bool cap, va_list *args)
{
	unsigned int	to_put;
	int				res;
	unsigned int	print_len;
	unsigned int	i;

	res = 0;
	to_put = (unsigned int)va_arg(*args, unsigned int);
	print_len = f_hex_get_print_len(info, to_put);
	if (info->left_align)
		f_hex_print(info, to_put, cap, print_len, &res);
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
		f_hex_print(info, to_put, cap, print_len, &res);
	return (res);
}

