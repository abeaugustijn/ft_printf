/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   next_format_char.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 21:07:01 by abe            #+#    #+#                */
/*   Updated: 2019/11/05 10:55:08 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	next_format_char(const char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' ||
			format[i] == 'd' || format[i] == 'i' || format[i] == 'u' ||
			format[i] == 'x' || format[i] == 'X')
			break ;
		i++;
		if (format[i] == '%')
			return (0);
	}
	return (format[i]);
}
