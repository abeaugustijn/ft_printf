/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:34:29 by abe               #+#    #+#             */
/*   Updated: 2019/12/09 11:58:55 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdlib.h>
#include <stdarg.h>

/*
**	Handles a single format 'snippet'
*/

int		handle_format(char **format, va_list *args, int n)
{
	t_format_info	*info;
	int				res;

	info = t_fi_create();
	if (info == NULL)
		return (-1);
	if (t_fi_get_info(info, format))
		return (-1);
	t_fi_check_width_precision(info, args);
	res = output(info, args, n);
	free(info);
	return (res);
}
