/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:31:56 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/16 11:26:53 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <stdarg.h>

void	f_char(t_format_info *info, va_list *args)
{
	char			c;
	unsigned int	i;

	c = (char)va_arg(*args, int);
	if (info->left_align)
		ft_putchar_fd(c, FD);
	if (info->has_width)
	{
		i = 0;
		while (i < info->width - 1)
		{
			ft_putchar_fd(info->zero_pad ? '0' : ' ', 1);
			i++;
		}
	}
	if (!info->left_align)
		ft_putchar_fd(c, FD);
}
