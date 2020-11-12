/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:35 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/12 13:32:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "t_format_info.h"
# include "formats.h"

# define FD 1

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				handle_format(char **tgt, char **format,
					t_format_func_args args);
int				output(t_format_func_args args);

#endif
