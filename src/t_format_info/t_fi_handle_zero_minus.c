/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_handle_zero_minus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:49:23 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/19 15:45:59 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>

/*
**	Disable zero pad when left align is active
*/

void	t_fi_handle_zero_minus(t_format_info *info)
{
	if (info->left_align)
		info->zero_pad = 0;
}
