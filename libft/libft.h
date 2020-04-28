/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 15:23:24 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:14:20 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>

char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
size_t			ft_hexlen(unsigned long long n);
size_t			ft_intlen(long long int n);
size_t			ft_strlen(const char *s);
size_t			ft_unsignedlen(unsigned long long int n);
unsigned long	ft_atoi_ul(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);

#endif
