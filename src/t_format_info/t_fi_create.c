/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:49:53 by abe               #+#    #+#             */
/*   Updated: 2019/11/12 11:30:07 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>
#include <libft.h>
#include <stdlib.h>

t_format_info	*t_fi_create()
{
	t_format_info	*res;

	res = (t_format_info *)malloc(sizeof(t_format_info));
	if (res == NULL)
		return (NULL);
	res->expect_precision_arg = FALSE;
	res->force_sign = FALSE;
	res->has_precision = FALSE;
	res->left_align = FALSE;
	res->presicion = 0;
	res->type = UNDEFINED;
	res->hex_identifier = FALSE;
	res->has_space = FALSE;
	return (res);
}
