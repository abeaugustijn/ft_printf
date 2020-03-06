/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:22:10 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/06 17:37:45 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>
#include <sizes.h>
#include <libft.h>
#include <utils.h>

/*
**	Print the unsigned int. This is only the non-whitespace part.
*/

static void			f_unsigned_print(t_format_info *info,
		unsigned long long to_put, unsigned int print_len, int *res)
{
	int				n_zero;

	n_zero = print_len - ft_unsignedlen(to_put);
	while (n_zero > 0)
	{
		ft_putchar_fd_count('0', FD, res);
		n_zero--;
	}
	if (!(info->has_precision && !info->precision && !to_put))
		ft_putunsigned_fd_count(to_put, FD, res);
}

/*
**	Get the amount of non-whitespace bytes that will be printed.
*/

static unsigned int	f_unsigned_get_print_len(t_format_info *info,
				unsigned long long to_put)
{
	size_t			og_len;
	unsigned int	res;

	og_len = ft_unsignedlen(to_put);
	res = og_len;
	if (info->has_precision && !info->precision && !to_put)
		return (0);
	if (info->has_precision && ((size_t)info->precision > og_len))
		res = info->precision;
	if (info->has_precision && info->has_width)
		return (res);
	if (info->zero_pad && info->has_width)
		res = info->width > og_len ? info->width : og_len;
	return (res);
}

/*
**	The format function for formats of the type unsigned integer.
*/

int					f_unsigned(t_format_info *info, va_list *args)
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
			ft_putchar_fd_count(' ', FD, &res);
			i++;
		}
	}
	if (!info->left_align)
		f_unsigned_print(info, to_put, print_len, &res);
	return (res);
}
