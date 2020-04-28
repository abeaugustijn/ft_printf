/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexlen_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 15:29:26 by aaugusti      #+#   #+#                  */
/*   Updated: 2019/11/28 11:28:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/*
**	Calculate the amount of digits in an unsigned long long if printed as hex
*/

size_t	ft_hexlen(unsigned long long n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		res++;
	}
	return (res);
}
