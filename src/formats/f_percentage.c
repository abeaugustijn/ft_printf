/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f_percentage.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 15:41:49 by abe           #+#   #+#                  */
/*   Updated: 2020/04/28 13:53:56 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <formats.h>
#include <ft_printf.h>
#include <t_format_info.h>
#include <utils.h>

/*
**	Handle the precentage format
*/

int		f_percentage(t_format_info *info, va_list *args, int n)
{
	unsigned int	i;
	int				res;

	(void)args;
	(void)n;
	res = 0;
	if (info->left_align)
		ft_putchar_fd_count(info->tgt, '%', &res);
	i = 0;
	if (info->has_width && info->width > 0)
	{
		while (i < info->width - 1)
		{
			ft_putchar_fd_count(info->tgt, info->zero_pad ? '0' : ' ', &res);
			i++;
		}
	}
	if (!info->left_align)
		ft_putchar_fd_count(info->tgt, '%', &res);
	return (res);
}
