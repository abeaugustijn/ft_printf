/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format_info.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:45:27 by abe               #+#    #+#             */
/*   Updated: 2019/11/12 19:49:29 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FORMAT_INFO_H
# define T_FORMAT_INFO_H
# include <ft_printf.h>
# include <libft.h>

# ifndef T_VAR_TYPE
#  define T_VAR_TYPE
typedef int		t_var_type;
# endif

typedef struct	s_format_info
{
	int			width;
	t_var_type	type;
	t_bool		has_width;
	int			precision;
	t_bool		has_precision;
	t_bool		has_space;
	t_bool		left_align;
	t_bool		zero_pad;
	t_bool		expect_precision_arg;
	t_bool		expect_width_arg;
	t_bool		force_sign;
	t_bool		hex_identifier;
}				t_format_info;

t_format_info	*t_fi_create();
int				t_fi_get_info(t_format_info	*info, char **format);
void			t_fi_check_width_precision(t_format_info *info, va_list *args);
void			output(t_format_info *info, va_list *args);

#endif
