/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:13:27 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:40:10 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <libft.h>
# include <stdbool.h>

int		write_string(char **format);
void	ft_putchar_fd_count(char **tgt, char c, int *count);
void	ft_puthex_fd_count(char **tgt, unsigned long long n, bool cap, int *count);
void	ft_putnbr_ll_fd_count(char **tgt, long long int n, int *count);
void	ft_putstr_fd_count(char **tgt, char *str, int *count);
void	ft_putstr_n_fd_count(char **tgt, char *str, size_t n, int *count);
void	ft_putunsigned_fd_count(char **tgt, unsigned long long n, int *count);
void	ftp_write(char *to_write, char **target, size_t n, int *tot_written);

#endif
