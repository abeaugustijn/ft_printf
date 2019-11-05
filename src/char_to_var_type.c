/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_to_var_type.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:43:39 by abe            #+#    #+#                */
/*   Updated: 2019/11/05 10:53:37 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_var_type	char_to_var_type(const char *format)
{
	char	c;

	c = next_format_char(format);
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	if (c == 'd' || c == 'i')
		return (INT);
	if (c == 'u')
		return (UNSIGNED_INT);
	if (c == 'x')
		return (HEX_LOW);
	if (c == 'X')
		return (HEX_UP);
	return (UNDEFINED);
}
