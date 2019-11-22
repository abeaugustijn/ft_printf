/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_get_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:55:14 by abe               #+#    #+#             */
/*   Updated: 2019/11/22 15:32:14 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>

/*
**	Deal with the flags.
**	- Skips the '%' char
**	- Loops through the flags and sets the appropiate variable until another
**		character is encountered
*/

void	flags(t_format_info *info, char **format)
{
	(*format)++;
	while (**format)
	{
		if (**format == '-')
			info->left_align = TRUE;
		else if (**format == '0')
			info->zero_pad = TRUE;
		else if (**format == '+')
			info->force_sign = TRUE;
		else if (**format == '#')
			info->hex_identifier = TRUE;
		else if (**format == ' ')
			info->has_space = TRUE;
		else
			return ;
		(*format)++;
	}
}

/*
**	Deal with the width parameter.
**	- Just calls atoi on the format. Atoi will automatically stop when a
**		non-digit char is encountered.
*/

void	width(t_format_info *info, char **format)
{
	int	width;

	if (**format == '*')
	{
		info->expect_width_arg = TRUE;
		info->has_width = TRUE;
		(*format)++;
		return ;
	}
	width = ft_atoi(*format);
	if (width > 0)
	{
		info->width = width;
		info->has_width = TRUE;
		while (ft_isdigit(**format))
			(*format)++;
	}
}

/*
**	Deal with the precision parameter
**	- will check for a period
**	- check for an asterisk
**	- just run atoi
**
**	! should be interpreted as a non-negative decimal integer
*/

void	precision(t_format_info *info, char **format)
{
	unsigned int	precision;

	if (**format != '.')
		return ;
	info->has_precision = TRUE;
	(*format)++;
	if (**format == '*')
	{
		info->expect_precision_arg = TRUE;
		(*format)++;
		return ;
	}
	precision = ft_atoi_ui(*format);
	info->precision = precision;
	while (ft_isdigit(**format))
		(*format)++;
}

/*
**	Parse the specifier for the format string
**	Returns a 0 if a valid specifier was found, 1 if there was none
*/

int		specifier(t_format_info *info, char **format)
{
	if (**format == 's')
		info->type = STRING;
	else if (**format == 'c')
		info->type = CHAR;
	else if (**format == 'i' || **format == 'd')
		info->type = INT;
	else if (**format == '%')
		info->type = PERCENTAGE;
	else if (**format == 'X')
		info->type = HEX_UP;
	else if (**format == 'x')
		info->type = HEX_LOW;
	else
		return (1);
	return (0);
}

/*
**	Retrieves the info of a format 'snippet'
**
**	info:	format_info struct to store the info in
**	format:	pointer to the first char of the format 'snippet'
*/

int		t_fi_get_info(t_format_info	*info, char **format)
{
	int	res;

	res = 0;
	flags(info, format);
	width(info, format);
	precision(info, format);
	res = specifier(info, format);
	t_fi_handle_plus_space(info);
	t_fi_handle_zero_minus(info);
	return (res);
}
