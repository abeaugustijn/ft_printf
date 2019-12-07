/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_get_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:55:14 by abe               #+#    #+#             */
/*   Updated: 2019/12/07 12:26:31 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <parsing.h>

/*
**	Retrieves the info of a format 'snippet'
**
**	info:	format_info struct to store the info in
**	format:	pointer to the first char of the format 'snippet'
*/

int		t_fi_get_info(t_format_info *info, char **format)
{
	int	res;

	flags(info, format);
	width(info, format);
	precision(info, format);
	size(info, format);
	res = specifier(info, format);
	t_fi_handle_plus_space(info);
	t_fi_handle_zero_minus(info);
	return (res);
}
