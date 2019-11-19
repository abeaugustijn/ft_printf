/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_percentage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:41:49 by abe               #+#    #+#             */
/*   Updated: 2019/11/19 16:05:54 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <t_format_info.h>

/*
**	Handle the precentage format
*/

int		f_percentage()
{
	ft_putchar_fd('%', FD);
	return (1);
}
