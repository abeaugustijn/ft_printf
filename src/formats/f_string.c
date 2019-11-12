/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:45 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/12 16:38:46 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <libft.h>

void	f_string(t_format_info *info, va_list *args)
{
	char	*str;
	int		str_len;
	int		i;

	str = (char *)va_arg(*args, char *);
	str_len = (int)ft_strlen(str);
	if (info->left_align)
		ft_putstr_fd(str, FD);
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
		ft_putstr_fd(str, FD);
}
