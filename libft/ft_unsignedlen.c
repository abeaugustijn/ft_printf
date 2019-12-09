/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:30:33 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/06 15:41:38 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
**	Calculate the amount of digits in an unsigned long long if printed as a
**	decimal number.
*/

size_t	ft_unsignedlen(unsigned long long int n)
{
	size_t	res;

	if (!n)
		return (1);
	res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}
