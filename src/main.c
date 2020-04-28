/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 18:49:25 by abe           #+#   #+#                  */
/*   Updated: 2020/04/28 14:33:04 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <utils.h>

/*
**	%[flags][width][.precision][length]specifier
*/

#ifdef SPRINTF

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = 0;
	while (*format)
	{
		res += write_string(&str, (char **)&format);
		if (*format == '%')
			res += handle_format(&str, (char **)&format, &args, res);
	}
	va_end(args);
	*str = '\0';
	return (res);
}

#else

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = 0;
	while (*format)
	{
		res += write_string(NULL, (char **)&format);
		if (*format == '%')
			res += handle_format(NULL, (char **)&format, &args, res);
	}
	va_end(args);
	return (res);
}

#endif
