/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 11:19:09 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:19:04 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	ft_printf(const char *format, ...);

# ifdef SPRINTF

int	ft_sprintf(char *str, const char *format, ...);

# endif

#endif
