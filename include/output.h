/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:36 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:22:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include <formats.h>
# include <t_format_info.h>
# include <t_var_type.h>

int	(*g_format_functions[])(t_format_info *, va_list *, int) = {
	[STRING] = f_string,
	[CHAR] = f_char,
	[INT] = f_int,
	[PERCENTAGE] = f_percentage,
	[HEX_UP] = f_hex,
	[HEX_LOW] = f_hex,
	[POINTER] = f_pointer,
	[UNSIGNED] = f_pointer,
	[N] = f_n,
};

#endif
