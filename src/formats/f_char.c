/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:31:56 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/18 14:16:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <stdarg.h>
#include <utils.h>

int		f_char(t_format_info *info, va_list *args)
{
	char			c;
	unsigned int	i;
	int				res;

	res = 0;
	c = (char)va_arg(*args, int);
	if (info->left_align)
		ft_putchar_fd_count(c, FD, &res);
	if (info->has_width)
	{
		i = 0;
		while (i < info->width - 1)
		{
			ft_putchar_fd_count(info->zero_pad ? '0' : ' ', 1, &res);
			i++;
		}
	}
	if (!info->left_align)
		ft_putchar_fd_count(c, FD, &res);
	return (res);
}
