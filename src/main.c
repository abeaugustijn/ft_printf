/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:49:25 by abe               #+#    #+#             */
/*   Updated: 2019/12/09 11:59:46 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <stdlib.h>
#include <utils.h>

/*
**	%[flags][width][.precision][length]specifier
*/

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;
	int		tmp_res;

	va_start(args, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp_res = handle_format((char **)&format, &args, res);
			if (tmp_res == -1)
				return (-1);
			res += tmp_res;
		}
		else
			ft_putchar_fd_count(*format, 1, &res);
		format++;
	}
	va_end(args);
	return (res);
}
