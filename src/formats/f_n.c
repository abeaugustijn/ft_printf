/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_n.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:05:14 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/09 12:18:48 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <stdarg.h>

/*
**	The format function for a single character. Has to take width into account.
*/

int		f_n(va_list *args, int n)
{
	int	*ptr;

	ptr = (int *)va_arg(*args, int *);
	*ptr = n;
	return (0);
}
