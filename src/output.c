/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:49:17 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 12:10:17 by aaugusti      ########   odam.nl         */
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
