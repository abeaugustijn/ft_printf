/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:02:10 by abe            #+#    #+#                */
/*   Updated: 2019/11/11 22:15:04 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# include <t_format_info.h>

# ifndef NULL
#  define NULL ((void *)0)
# endif

typedef int		t_var_type;
# define CHAR 1
# define STRING 2
# define POINTER 3
# define INT 4
# define UNSIGNED_INT 5
# define HEX_LOW 6
# define HEX_UP 7
# define UNDEFINED 8

int				ft_printf(const char *format, ...);
void			handle_format(char **format);
t_format_info	get_var_type(char *format);

#endif
