/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsigned_fd_count.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:29 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:29 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

/*
**	Output the unsigned long long 'n' to 'fd'. Also add the amount of printed
**	chars to *'count'.
*/

void	ft_putunsigned_fd_count(char **tgt, unsigned long long n, int *count)
{
	if (n < 10)
		ft_putchar_fd_count(tgt, (char)(n + '0'), count);
	else
	{
		ft_putunsigned_fd_count(tgt, n / 10, count);
		ft_putchar_fd_count(tgt, (char)((n % 10) + '0'), count);
	}
}
