/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:23:24 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/10 07:37:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

# ifndef t_bool
typedef char	t_bool;
# endif

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

int				ft_atoi(const char *str);
unsigned long	ft_atoi_ul(const char *str);
size_t			ft_hexlen(unsigned long long n);
size_t			ft_intlen(long long int n);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
size_t			ft_unsignedlen(unsigned long long int n);
size_t			ft_strlen(const char *s);

#endif
