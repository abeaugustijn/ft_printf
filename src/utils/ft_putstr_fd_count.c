/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd_count.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:21:11 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:41:50 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

void	ft_putstr_fd_count(char **tgt, char *str, int *count)
{
	const size_t	len = ft_strlen(str);

	ftp_write(str, tgt, len, count);
}
