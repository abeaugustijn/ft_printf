/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 08:57:07 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 14:31:29 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <ft_printf.h>
#include <unistd.h>

int	write_string(char **tgt, char **format)
{
	size_t	len;

	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	ft_putstr_n_fd_count(tgt, *format, len, NULL);
	(*format) += len;
	return ((int)len);
}
