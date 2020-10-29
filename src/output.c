/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:19 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:19 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>
#include <ft_printf.h>
#include <output.h>
#include <stdarg.h>
#include <t_format_info.h>

int		output(t_format_info *info, va_list *args, int n)
{
	return (g_format_functions[info->type](info, args, n));
}
