/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:34:29 by abe               #+#    #+#             */
/*   Updated: 2019/11/12 10:11:24 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <stdlib.h>

/*
**	Handles a single format 'snippet'
**
**	format:	pointer to the string that points to the first character of the
**			'snippet'
*/

void		handle_format(char **format)
{
	t_format_info	*info;

	info = t_fi_create();
	// if (t_fi_get_info(info, *format)) TODO: handle bad snippet
	t_fi_get_info(info, *format);
	ft_putnbr_fd(info->type, 1);
	free(info);
}
