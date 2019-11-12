/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format_info.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:45:27 by abe               #+#    #+#             */
/*   Updated: 2019/11/12 11:30:41 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FORMAT_INFO_H
# define T_FORMAT_INFO_H
# include <libft.h>
# include <ft_printf.h>

typedef struct	s_format_info
{
	int	type;
	t_bool		left_align;
	t_bool		zero_pad;
	t_bool		has_precision;
	int			presicion;
	t_bool		expect_precision_arg;
	t_bool		force_sign;
	t_bool		hex_identifier;
	t_bool		has_space;
}				t_format_info;

t_format_info	*t_fi_create();
int				t_fi_get_info(t_format_info	*info, char *format);

#endif
