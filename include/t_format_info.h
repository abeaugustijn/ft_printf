/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format_info.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:45:27 by abe               #+#    #+#             */
/*   Updated: 2019/11/18 13:59:42 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FORMAT_INFO_H
# define T_FORMAT_INFO_H
# include <libft.h>
# include <ft_printf.h>
# include <t_var_type.h>

typedef struct		s_format_info
{
	t_var_type		type;
	unsigned int	width;
	t_bool			has_width;
	unsigned int	precision;
	t_bool			has_precision;
	t_bool			has_space;
	t_bool			left_align;
	t_bool			zero_pad;
	t_bool			expect_precision_arg;
	t_bool			expect_width_arg;
	t_bool			force_sign;
	t_bool			hex_identifier;
	t_bool			has_sign;
}					t_format_info;

t_format_info	*t_fi_create();
int				t_fi_get_info(t_format_info	*info, char **format);
void			t_fi_check_width_precision(t_format_info *info, va_list *args);
void			t_fi_handle_sign(t_format_info *info, int to_put);
void			t_fi_handle_plus_space(t_format_info *info);
void			output(t_format_info *info, va_list *args);

#endif
