/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_handle_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:21:33 by abe               #+#    #+#             */
/*   Updated: 2019/11/16 21:22:56 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>

void	t_fi_handle_sign(t_format_info *info, int to_put)
{
	info->has_sign = info->force_sign || to_put < 0;
}
