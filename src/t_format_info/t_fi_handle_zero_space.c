/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_handle_zero_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:11:13 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/18 16:14:04 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>

void	t_fi_handle_zero_space(t_format_info *info)
{
	if (info->zero_pad && info->has_space)
		info->zero_pad = FALSE;
}
