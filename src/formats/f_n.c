/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_n.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:08 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:22:08 by aaugusti      ########   odam.nl         */
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
