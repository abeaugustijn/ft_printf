/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:02:10 by abe            #+#    #+#                */
/*   Updated: 2019/11/05 10:32:22 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>

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
typedef	struct	s_var
{
	t_var_type	type;
	char		*format;
	void		*value;
}				t_var;
t_var			*var_new(void);

int				ft_printf(const char *format, ...);

t_list			*parse_format(const char *format);
t_var_type		char_to_var_type(const char *format);
char			next_format_char(const char *format);

#endif
