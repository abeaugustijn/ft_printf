/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_percentage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:41:49 by abe               #+#    #+#             */
/*   Updated: 2019/12/09 12:12:01 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>
#include <t_format_info.h>

/*
**	Handle the precentage format
*/

int		f_percentage(t_format_info *info)
{
	unsigned int	i;

	if (info->left_align)
		ft_putchar_fd('%', FD);
	i = 0;
	if (info->has_width && info->width > 0)
	{
		while (i < info->width - 1)
		{
			ft_putchar_fd(info->zero_pad ? '0' : ' ', FD);
			i++;
		}
	}
	if (!info->left_align)
		ft_putchar_fd('%', FD);
	return (i + 1);
}
