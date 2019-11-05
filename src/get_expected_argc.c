/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_expected_argc.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 11:24:36 by aaugusti       #+#    #+#                */
/*   Updated: 2019/11/05 11:27:51 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	condition(void *content)
{
	t_var	*var_data;

	var_data = (t_var *)content;
	return (var_data->type != UNDEFINED);
}

int	get_expected_argc(t_list *vars)
{
	return (ft_lstcount_condition(vars, condition));
}
