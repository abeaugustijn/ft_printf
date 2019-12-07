/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:02:44 by abe               #+#    #+#             */
/*   Updated: 2019/12/07 11:00:18 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <t_format_info.h>
#include <libft.h>
#include <utils.h>
#include <sizes.h>

/*
**	Print the integer. This is only the non-whitespace part of the int.
**	- first check negative; the first char in the case of a negative int is
**		always a minus
*/

void			f_int_print(t_format_info *info, long long to_put,
		unsigned int print_len, int *res)
{
	unsigned int	is_neg;
	int				n_zero;
	int				i;
	unsigned int	use_width;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	use_width = info->has_width && info->width > info->precision;
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
	if(!(info->has_precision && !info->precision))
		ft_putnbr_ll_fd_count(to_put, FD, res);
}

/*
**	Get the amount of non-whitespace bytes that will be printed.
**	- in the case that width is set and there is a zero flag return the largest
**		of og_intlen and width.
**	- if precision is set and precision is larger than og_intlen return pre-
**		cision.
**		* also, if to_put is negative add a byte for the minus
**	- precision overwrites width
*/

unsigned int	f_int_get_print_len(t_format_info *info, long long to_put)
{
	size_t			og_intlen;
	unsigned int	is_neg;
	unsigned int	res;

	is_neg = to_put < 0;
	if (is_neg)
		to_put *= -1;
	og_intlen = ft_intlen(to_put);
	res = og_intlen;
	if (info->has_precision && info->precision > og_intlen)
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

int				f_int(t_format_info *info, va_list *args)
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
