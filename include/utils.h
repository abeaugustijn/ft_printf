/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:43 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:23:54 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <libft.h>
# include <stdbool.h>

int		write_string(char **tgt, char **format);
void	ft_putchar_fd_count(char **tgt, char c, int *count);
void	ft_puthex_fd_count(char **tgt, unsigned long long n, bool cap,
		int *count);
void	ft_putnbr_ll_fd_count(char **tgt, long long int n, int *count);
void	ft_putstr_fd_count(char **tgt, char *str, int *count);
void	ft_putstr_n_fd_count(char **tgt, char *str, size_t n, int *count);
void	ft_putunsigned_fd_count(char **tgt, unsigned long long n, int *count);
void	ftp_write(char *to_write, char **target, size_t n, int *tot_written);

#endif
