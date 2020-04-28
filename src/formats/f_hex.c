/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_hex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 11:46:14 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:13:08 by aaugusti      ########   odam.nl         */
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
**	- first check negative; the first char in the case of a negative int is
**		always a minus
*/

static void			f_hex_print(t_format_info *info, unsigned long long to_put,
		unsigned int print_len, int *res)
{
	int				n_zero;

	if (info->has_precision && !info->precision && !to_put &&
			info->type != POINTER)
		return ;
	if (info->hex_identifier)
		ft_putstr_fd_count(info->type == HEX_UP ? "0X" : "0x", FD, res);
	n_zero = print_len - ft_hexlen(to_put) - ((info->hex_identifier &&
		(to_put || info->type == POINTER)) ? 2 : 0);
	while (n_zero > 0)
	{
		ft_putchar_fd_count('0', FD, res);
		n_zero--;
	}
	if (!(info->has_precision && !info->precision && !to_put &&
			info->type == POINTER))
		ft_puthex_fd_count(to_put, FD, info->type == HEX_UP, res);
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

static unsigned int	f_hex_get_print_len(t_format_info *info,
		unsigned long long to_put)
{
	size_t			og_hexlen;
	unsigned int	res;

	og_hexlen = ft_hexlen(to_put);
	res = og_hexlen;
	if (info->has_precision && !info->precision && !to_put)
		res = 0;
	if (info->has_precision && ((size_t)info->precision > og_hexlen))
		res = info->precision;
	if (info->hex_identifier)
		res += 2;
	if (info->has_precision && info->has_width)
		return (res);
	if (info->zero_pad && info->has_width)
		res = info->width > og_hexlen ? info->width : og_hexlen;
	return (res);
}

/*
**	The format function for formats of the type unsigned integer printed as hex.
**	Also implements support for pointers.
*/

int					f_hex(t_format_info *info, va_list *args, int n)
{
	unsigned long long	to_put;
	int					res;
	unsigned int		print_len;
	unsigned int		i;

	(void)n;
	res = 0;
	to_put = sz_hex(info, args);
	if (!to_put && info->type != POINTER)
		info->hex_identifier = false;
	print_len = f_hex_get_print_len(info, to_put);
	if (info->left_align)
		f_hex_print(info, to_put, print_len, &res);
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
		f_hex_print(info, to_put, print_len, &res);
	return (res);
}
