/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd_count.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:21:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:21:27 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>

void	ft_putstr_fd_count(char **tgt, char *str, int *count)
{
	const size_t	len = ft_strlen(str);

	ftp_write(str, tgt, len, count);
}
