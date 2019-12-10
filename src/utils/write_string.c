/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:57:07 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/10 09:01:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <ft_printf.h>
#include <unistd.h>

int	write_string(char **format)
{
	size_t	strlen;

	strlen = 0;
	while ((*format)[strlen] && (*format)[strlen] != '%')
		strlen++;
	write(FD, *format, strlen);
	(*format) += strlen;
	return ((int)strlen);
}
