/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:49:25 by abe               #+#    #+#             */
/*   Updated: 2019/11/12 15:26:01 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <libft.h>
#include <stdlib.h>

/*
**	%[flags][width][.precision][length]specifier
*/

int		ft_printf(const char *format, ...)
{
	va_list	*args;

	args = (va_list *)malloc(sizeof(va_list));
	va_start(*args, format);
	while (*format)
	{
		if (*format == '%')
			handle_format((char **)&format, args);
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(*args);
	free(args);
	return (0);
}
