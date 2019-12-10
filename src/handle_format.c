/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:34:29 by abe               #+#    #+#             */
/*   Updated: 2019/12/10 08:52:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdarg.h>

/*
**	Handles a single format 'snippet'
*/

int		handle_format(char **format, va_list *args, int n)
{
	t_format_info	info;

	ft_bzero(&info, sizeof(t_format_info));
	t_fi_get_info(&info, format);
	t_fi_check_width_precision(&info, args);
	return (output(&info, args, n));
}
