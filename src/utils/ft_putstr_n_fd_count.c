/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_n_fd_count.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:22:33 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:41:39 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

void	ft_putstr_n_fd_count(char **tgt, char *str, size_t n, int *count)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > n)
		len = n;
	ftp_write(str, tgt, len, count);
}
