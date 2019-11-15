/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:45 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/15 15:43:35 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <libft.h>

void	f_string_putstr(t_format_info *info, char *str)
{
	if (info->has_precision)
		ft_putstr_n_fd(str, (size_t)info->precision, FD);
	else
		ft_putstr_fd(str, FD);
}

void	f_string(t_format_info *info, va_list *args)
{
	char	*str;
	int		str_len;
	int		i;

	str = (char *)va_arg(*args, char *);
	str_len = (int)ft_strlen(str);
	if (info->left_align)
		f_string_putstr(info, str);
	if (info->has_width)
	{
		i = 0;
		while (i < info->width - str_len)
		{
			ft_putchar_fd(info->zero_pad ? '0' : ' ', 1);
			i++;
		}
	}
	if (!info->left_align)
		f_string_putstr(info, str);
}
