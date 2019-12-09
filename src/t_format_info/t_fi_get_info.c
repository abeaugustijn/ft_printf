/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_get_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:55:14 by abe               #+#    #+#             */
/*   Updated: 2019/12/09 12:02:32 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <parsing.h>

/*
**	Retrieves the info from a format 'snippet'
*/

int		t_fi_get_info(t_format_info *info, char **format)
{
	int	res;

	flags(info, format);
	width(info, format);
	precision(info, format);
	size(info, format);
	res = specifier(info, format);
	t_fi_handle_zero_minus(info);
	return (res);
}
