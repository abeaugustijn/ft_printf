/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd_count.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:12:18 by aaugusti      #+#   #+#                  */
/*   Updated: 2019/12/09 11:55:35 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <unistd.h>

void	ft_putchar_fd_count(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}
