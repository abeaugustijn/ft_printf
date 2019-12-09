/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:02:10 by abe            #+#    #+#                */
/*   Updated: 2019/12/07 17:07:23 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# include <t_var_type.h>
# include <t_format_info.h>

# define FD 1

# ifndef NULL
#  define NULL ((void *)0)
# endif

int				ft_printf(const char *format, ...);
int				handle_format(char **format, va_list *args, int n);
t_format_info	get_var_type(char *format);

#endif
