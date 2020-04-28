/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 08:57:07 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:43:18 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <ft_printf.h>
#include <unistd.h>

int	write_string(char **format)
{
	size_t	len;

	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	write(FD, *format, len);
	(*format) += len;
	return ((int)len);
}
