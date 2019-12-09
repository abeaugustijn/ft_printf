/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:45 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/09 12:11:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>
#include <libft.h>
#include <utils.h>

/*
**	Output the string
*/

void			f_string_putstr(t_format_info *info, char *str, int *res)
{
	if (info->has_precision)
		ft_putstr_n_fd_count(str, (size_t)info->precision, FD, res);
	else
		ft_putstr_fd_count(str, FD, res);
}

/*
**	Pring the right amount and the right type of padding before or after the
**	string.
*/

unsigned int	f_string_print_padding(t_format_info *info,
		unsigned int str_len, int *res)
{
	unsigned int	i;

	i = 0;
	if (info->has_width && info->width > str_len)
	{
		while (i < info->width - str_len)
		{
			ft_putchar_fd_count(info->zero_pad ? '0' : ' ', 1, res);
			i++;
		}
	}
	return (i);
}

/*
**	Get the strings length and take precision into account.
*/

unsigned int	f_string_get_strlen(t_format_info *info, char *str)
{
	size_t	og_str_len;

	if (str == NULL)
		return (0);
	og_str_len = ft_strlen(str);
	if (info->has_precision && info->precision > 0 &&
			og_str_len > (size_t)info->precision)
		return (info->precision);
	return (og_str_len);
}

/*
**	Function to output a string with different format rules.
*/

int				f_string(t_format_info *info, va_list *args)
{
	char			*str;
	unsigned int	str_len;
	int				res;

	res = 0;
	str = (char *)va_arg(*args, char *);
	if (str == NULL)
		str = "(null)";
	str_len = f_string_get_strlen(info, str);
	if (info->left_align)
		f_string_putstr(info, str, &res);
	f_string_print_padding(info, str_len, &res);
	if (!info->left_align)
		f_string_putstr(info, str, &res);
	return (res);
}
