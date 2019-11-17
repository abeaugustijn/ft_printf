/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_handle_plus_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:27:15 by abe               #+#    #+#             */
/*   Updated: 2019/11/16 21:29:20 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>

/*
**	Handle the case where both + and ' ' flags are set.
*/

void	t_fi_handle_plus_space(t_format_info *info)
{
	if (info->has_space && info->force_sign)
		info->has_space = TRUE;
}
