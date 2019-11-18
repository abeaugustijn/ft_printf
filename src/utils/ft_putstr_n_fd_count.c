/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n_fd_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:33 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/18 15:16:19 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <utils.h>

void	ft_putstr_n_fd_count(char *str, int n, int fd, int *res)
{
	int	i;

	i = 0;
	while (*str && i < n)
	{
		ft_putchar_fd_count(*str, fd, res);
		str += sizeof(char);
		i++;
	}
}
