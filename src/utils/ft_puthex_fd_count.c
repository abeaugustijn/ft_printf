/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_fd_count.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 11:13:25 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:35:25 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include <stdbool.h>
#include <utils.h>

/*
**	Output the unsigned long long 'n' to 'fd' as a hexadecimal number. Also add
**	the amount of printed chars to *'count'.
*/

void	ft_puthex_fd_count(char **tgt, unsigned long long n, bool cap, int *count)
{
	const char	*base = cap ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n < 16)
		ft_putchar_fd_count(tgt, (base[n]), count);
	else
	{
		ft_puthex_fd_count(tgt, n / 16, cap, count);
		ft_putchar_fd_count(tgt, (base[n % 16]), count);
	}
}
