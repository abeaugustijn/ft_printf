/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:11:57 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/19 16:17:27 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <formats.h>
#include <libft.h>

int	f_hex(t_format_info *info, t_bool is_cap, va_list *args)
{
	unsigned int	to_put;
	unsigned int	n_len;

	to_put = (unsigned int)va_arg(*args, unsigned int);
	n_len = ft_ull_len((unsigned long long)to_put);
}
