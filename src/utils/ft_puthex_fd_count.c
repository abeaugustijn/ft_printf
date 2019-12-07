/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:13:25 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/07 11:17:59 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <utils.h>
#include <libft.h>

/*
**	Output the unsigned long long 'n' to 'fd' as a hexadecimal number. Also add
**	the amount of printed chars to *'count'.
*/

void	ft_puthex_fd_count(unsigned long long n, int fd, t_bool cap, int *count)
{
	char *base;

	base = cap ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n < 10)
		ft_putchar_fd_count((base[n]), fd, count);
	else
	{
		ft_putunsigned_fd_count(n / 16, fd, count);
		ft_putchar_fd_count((base[(n % 16)]), fd, count);
	}
}
