/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_ll_fd_count.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 10:51:24 by aaugusti      #+#   #+#                  */
/*   Updated: 2019/12/07 10:53:12 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <utils.h>

/*
**	Output the long long integer 'n' to 'fd'. Also add the amount of outputted
**	chars to *'count'.
*/

void		ft_putnbr_ll_fd_count(long long int n, int fd, int *count)
{
	if (n == LLONG_MIN)
	{
		ft_putnbr_ll_fd_count(-9, fd, count);
		ft_putnbr_ll_fd_count(223372036854775808, fd, count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd_count('-', fd, count);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd_count((char)(n + '0'), fd, count);
	else
	{
		ft_putnbr_ll_fd_count(n / 10, fd, count);
		ft_putchar_fd_count((char)((n % 10) + '0'), fd, count);
	}
}
