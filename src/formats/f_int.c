/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:02:44 by abe               #+#    #+#             */
/*   Updated: 2019/12/10 07:43:11 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <stdarg.h>
#include <t_format_info.h>
#include <libft.h>
#include <utils.h>
#include <sizes.h>

/*
**	Print the integer. This is only the non-whitespace part of the int.
*/

static void			f_int_print(t_format_info *info, long long to_put,
		unsigned int print_len, int *res)
{
	unsigned int	is_neg;
	int				n_zero;
	int				i;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	if (is_neg || info->force_sign)
		ft_putchar_fd_count(is_neg ? '-' : '+', FD, res);
	else if (info->has_space)
		ft_putchar_fd_count(' ', FD, res);
	n_zero = print_len - ((is_neg || info->force_sign || info->has_space)
		? 1 : 0) - ft_intlen(to_put);
	if (n_zero > 0)
	{
		i = 0;
		while (i < n_zero)
		{
			ft_putchar_fd_count('0', FD, res);
			i++;
		}
	}
	if (!(info->has_precision && !info->precision))
		ft_putnbr_ll_fd_count(to_put, FD, res);
}

/*
**	Get the amount of non-whitespace bytes that will be printed.
*/
			
static unsigned int	f_int_get_print_len(t_format_info *info, long long to_put)
{
	size_t			og_intlen;
	unsigned int	is_neg;
	unsigned int	res;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	og_intlen = ft_intlen(to_put);
	res = og_intlen;
	if (info->has_precision && (size_t) info->precision > og_intlen)
		res = info->precision;
	if (info->has_precision && !info->precision && !to_put)
		res = 0;
	if (is_neg || info->force_sign || info->has_space)
		res++;
	if (info->has_precision && info->has_width)
		return (res);
	if (info->zero_pad && info->has_width)
		res = info->width > og_intlen ? info->width : og_intlen;
	return (res);
}

/*
**	The format function for formats of the type integer.
*/

int					f_int(t_format_info *info, va_list *args)
{
	long long int	to_put;
	int				res;
	unsigned int	print_len;
	unsigned int	i;

	res = 0;
	to_put = sz_int(info, args);
	print_len = f_int_get_print_len(info, to_put);
	if (info->left_align)
		f_int_print(info, to_put, print_len, &res);
	if (info->width > print_len)
	{
		i = 0;
		while (i < info->width - print_len)
		{
			ft_putchar_fd_count(' ', FD, &res);
			i++;
		}
	}
	if (!info->left_align)
		f_int_print(info, to_put, print_len, &res);
	return (res);
}
