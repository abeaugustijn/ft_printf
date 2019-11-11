/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fi_get_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:55:14 by abe               #+#    #+#             */
/*   Updated: 2019/11/11 21:52:19 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>

/*
**	Deal with the flags.
*/

void	flags(t_format_info *info, char **format)
{
	while (**format)
	{
		if (**format == '-')
			info->left_align = TRUE;
		else if (**format == '0')
			info->zero_pad = TRUE;
		else if (**format == '+')
			info->force_sign = TRUE;
		else if (**format == '#')
			info->hex_identifier = TRUE;
		else
			return ;
		(*format)++;
	}
}

/*
**	Retrieves the info of a format 'snippet'
**
**	info:	format_info struct to store the info in
**	format:	pointer to the first char of the format 'snippet'
*/

int		t_fi_get_info(t_format_info	*info, char *format)
{
	flags(info, &format);
	return (0);
}
