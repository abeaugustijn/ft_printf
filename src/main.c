/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:49:25 by abe               #+#    #+#             */
/*   Updated: 2019/11/18 14:14:58 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <libft.h>
#include <stdlib.h>
#include <utils.h>

/*
**	%[flags][width][.precision][length]specifier
*/

int		ft_printf(const char *format, ...)
{
	va_list	*args;
	int		res;
	int		tmp_res;

	args = (va_list *)malloc(sizeof(va_list));
	if (args == NULL)
		return (-1);
	va_start(*args, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp_res = handle_format((char **)&format, args);
			if (tmp_res == -1)
				return (-1);
			res += tmp_res;
		}
		else
			ft_putchar_fd_count(*format, 1, &res);
		format++;
	}
	va_end(*args);
	free(args);
	return (res);
}
