/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:21:11 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/09 11:52:51 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <unistd.h>

void	ft_putstr_fd_count(char *str, int fd, int *res)
{
	const size_t	strlen = ft_strlen(str);

	write(fd, str, strlen);
	*res += strlen;
}
