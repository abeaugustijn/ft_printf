/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_n.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 17:05:14 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 12:11:47 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <stdarg.h>

/*
**	The format function for a single character. Has to take width into account.
*/

int		f_n(t_format_info *info, va_list *args, int n)
{
	int	*ptr;

	(void)info;
	ptr = (int *)va_arg(*args, int *);
	*ptr = n;
	return (0);
}
