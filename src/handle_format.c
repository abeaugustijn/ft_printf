/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_format.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:21 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:21 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>

/*
**	Handles a single format 'snippet'
*/

int		handle_format(char **tgt, char **format, va_list *args, int n)
{
	t_format_info	info;

	ft_bzero(&info, sizeof(t_format_info));
	t_fi_get_info(&info, format);
	t_fi_check_width_precision(&info, args);
	info.tgt = tgt;
	return (output(&info, args, n));
}
