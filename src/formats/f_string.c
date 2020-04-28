/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_string.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:17:45 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:54:51 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <libft.h>
#include <utils.h>

/*
**	Output the string
*/

static void			f_string_putstr(t_format_info *info, char *str, int *res)
{
	if (info->has_precision)
		ft_putstr_n_fd_count(info->tgt, str, (size_t)info->precision, res);
	else
		ft_putstr_fd_count(info->tgt, str, res);
}

/*
**	Pring the right amount and the right type of padding before or after the
**	string.
*/

static unsigned int	f_string_print_padding(t_format_info *info,
		unsigned int str_len, int *res)
{
	unsigned int	i;

	i = 0;
	if (info->has_width && info->width > str_len)
	{
		while (i < info->width - str_len)
		{
			ft_putchar_fd_count(info->tgt, info->zero_pad ? '0' : ' ', res);
			i++;
		}
	}
	return (i);
}

/*
**	Get the strings length and take precision into account.
*/

static unsigned int	f_string_get_strlen(t_format_info *info, char *str)
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

int					f_string(t_format_info *info, va_list *args, int n)
{
	char			*str;
	unsigned int	str_len;
	int				res;

	(void)n;
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
