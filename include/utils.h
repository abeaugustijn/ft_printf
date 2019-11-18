/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:13:27 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/18 15:17:16 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_putchar_fd_count(char c, int fd, int *count);
void	ft_putstr_fd_count(char *str, int fd, int *res);
void	ft_putstr_n_fd_count(char *str, int n, int fd, int *res);

#endif
