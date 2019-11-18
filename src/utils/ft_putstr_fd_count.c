/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:21:11 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/18 15:06:46 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <utils.h>

void	ft_putstr_fd_count(char *str, int fd, int *res)
{
	while (*str)
	{
		ft_putchar_fd_count(*str, fd, res);
		str += sizeof(char);
	}
}
