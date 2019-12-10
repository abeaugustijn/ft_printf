/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_parse_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:09:37 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/10 09:06:06 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
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
	precision = ft_atoi_ul(*format);
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
	else if (**format == 'p')
		info->type = POINTER;
	else if (**format == 'u')
		info->type = UNSIGNED;
	else if (**format == 'n')
		info->type = N;
	else
		return (1);
	(*format)++;
	return (0);
}

/*
**	Retrieves the size flag for format strings.
*/

void	size(t_format_info *info, char **format)
{
	if (**format == 'l')
	{
		info->has_size = TRUE;
		if ((*format)[1] == 'l')
		{
			info->size = LL;
			(*format)++;
		}
		else
			info->size = L;
		(*format)++;
		return ;
	}
	if (**format == 'h')
	{
		info->has_size = TRUE;
		if ((*format)[1] == 'h')
		{
			info->size = HH;
			(*format)++;
		}
		else
			info->size = H;
		(*format)++;
	}
}
