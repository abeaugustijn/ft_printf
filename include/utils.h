/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:13:27 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/07 11:17:18 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <libft.h>

void	ft_putchar_fd_count(char c, int fd, int *count);
void	ft_putstr_fd_count(char *str, int fd, int *res);
void	ft_putstr_n_fd_count(char *str, int n, int fd, int *res);
void	ft_putnbr_ll_fd_count(long long int n, int fd, int *count);
void	ft_putunsigned_fd_count(unsigned long long n, int fd, int *count);
void	ft_puthex_fd_count(unsigned long long n, int fd, t_bool cap,
		int *count);

#endif
