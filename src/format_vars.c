/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:23:01 by abe               #+#    #+#             */
/*   Updated: 2019/11/07 20:59:04 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

size_t	string_len(t_list *vars)
{
	t_var_type	type;

	type = vars->type;
	if (type == CHAR)
		return (1);
	if (type == STRING)
		return (ft_strlen((char *)vars->value));
	if (type == POINTER)
		return (

}

void	format_vars(t_list *vars)
{
	char	*res;

	while (vars)
	{
		res = (char *)malloc(string_len(vars));
	}
}
