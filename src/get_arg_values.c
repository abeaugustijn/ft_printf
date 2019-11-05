/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arg_values.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 11:41:39 by aaugusti       #+#    #+#                */
/*   Updated: 2019/11/05 15:40:01 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

void	get_arg_values(t_list *vars, va_list *args, int expected_argc)
{
	t_var	*var_data;

	while (vars)
	{
		var_data = (t_var *)vars->content;
		if (var_data->type == CHAR)
			var_data->value = (char *)var_dup_char(va_arg(*args, int));
		else if (var_data->type == STRING)
			var_data->value = (char *)va_arg(*args, char *);
		else if (var_data->type == POINTER)
			var_data->value = (int *)var_dup_ulong(va_arg(*args, unsigned long));
		else if (var_data->type == INT || var_data->type == HEX_LOW
			|| var_data->type == HEX_UP)
			var_data->value = (int *)var_dup_int(va_arg(*args, int));
		else if (var_data->type == UNSIGNED_INT)
			var_data->value = (unsigned int *)var_dup_uint(va_arg(*args, unsigned int));
		vars = vars->next;
	}
}
