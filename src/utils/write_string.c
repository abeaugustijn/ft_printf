/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:31 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:31 by aaugusti      ########   odam.nl         */
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
