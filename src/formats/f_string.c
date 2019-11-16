/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:45 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/16 21:07:52 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <libft.h>

void			f_string_putstr(t_format_info *info, char *str)
{
	if (info->has_precision)
		ft_putstr_n_fd(str, (size_t)info->precision, FD);
	else
		ft_putstr_fd(str, FD);
}

int				f_string_handle_null(t_format_info *info, char **str,
		unsigned int *str_len)
{
	if (*str != NULL)
		return (0);
	if (info->has_precision && info->precision < 6)
		*str = "";
	else
	{
		*str = "(null)";
		*str_len = 6;
	}
	return (1);
}

unsigned int	f_string_print_padding(t_format_info *info, unsigned int str_len)
{
	unsigned int	i;

	i = 0;
	if (info->has_width && info->width > str_len)
	{
		while (i < info->width - str_len)
		{
			ft_putchar_fd(info->zero_pad ? '0' : ' ', 1);
			i++;
		}
	}
	return (i);
}

unsigned int	f_string_get_strlen(t_format_info *info, char *str)
{
	unsigned int	og_str_len;

	if (str == NULL)
		return (0);
	og_str_len = ft_strlen(str);
	if (info->has_precision && og_str_len > info->precision)
		return (info->precision);
	return (og_str_len);
}

void			f_string(t_format_info *info, va_list *args)
{
	char			*str;
	unsigned int	str_len;

	str = (char *)va_arg(*args, char *);
	str_len = f_string_get_strlen(info, str);
	f_string_handle_null(info, &str, &str_len);
	if (info->left_align)
		f_string_putstr(info, str);
	f_string_print_padding(info, str_len);
	if (!info->left_align)
		f_string_putstr(info, str);
}
