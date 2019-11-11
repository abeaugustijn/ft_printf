/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:02:10 by abe            #+#    #+#                */
/*   Updated: 2019/11/11 10:50:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>

# ifndef NULL
#  define NULL ((void *)0)
# endif

typedef int		t_bool
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE 1
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

#endif
