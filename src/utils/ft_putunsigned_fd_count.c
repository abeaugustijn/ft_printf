/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd_count.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:04:28 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/07 11:05:24 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <utils.h>

/*
**	Output the unsigned long long 'n' to 'fd'. Also add the amount of printed
**	chars to *'count'.
*/

void		ft_putunsigned_fd_count(unsigned long long n, int fd, int *count)
{
	if (n < 10)
		ft_putchar_fd_count((char)(n + '0'), fd, count);
	else
	{
		ft_putunsigned_fd_count(n / 10, fd, count);
		ft_putchar_fd_count((char)((n % 10) + '0'), fd, count);
	}
}
