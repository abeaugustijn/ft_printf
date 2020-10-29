/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_ll_fd_count.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:26 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <utils.h>

/*
**	Output the long long integer 'n' to 'fd'. Also add the amount of outputted
**	chars to *'count'.
*/

void	ft_putnbr_ll_fd_count(char **tgt, long long int n, int *count)
{
	if (n == LLONG_MIN)
	{
		ft_putnbr_ll_fd_count(tgt, -9, count);
		ft_putnbr_ll_fd_count(tgt, 223372036854775808, count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd_count(tgt, '-', count);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd_count(tgt, (char)(n + '0'), count);
	else
	{
		ft_putnbr_ll_fd_count(tgt, n / 10, count);
		ft_putchar_fd_count(tgt, (char)((n % 10) + '0'), count);
	}
}
