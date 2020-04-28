/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_char.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:31:56 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:49:48 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <t_format_info.h>
#include <stdarg.h>
#include <utils.h>

/*
**	The format function for a single character. Has to take width into account.
*/

int		f_char(t_format_info *info, va_list *args, int n)
{
	char			c;
	unsigned int	i;
	int				res;

	(void)n;
	res = 0;
	c = (char)va_arg(*args, int);
	if (info->left_align)
		ft_putchar_fd_count(info->tgt, c, &res);
	if (info->has_width)
	{
		i = 0;
		while (i < info->width - 1)
		{
			ft_putchar_fd_count(info->tgt, info->zero_pad ? '0' : ' ', &res);
			i++;
		}
	}
	if (!info->left_align)
		ft_putchar_fd_count(info->tgt, c, &res);
	return (res);
}
