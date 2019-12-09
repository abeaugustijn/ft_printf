/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n_fd_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:22:33 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/09 12:00:36 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <unistd.h>

void	ft_putstr_n_fd_count(char *str, size_t n, int fd, int *res)
{
	size_t	strlen;

	strlen = ft_strlen(str);
	strlen = strlen > n ? n : strlen;
	write(fd, str, strlen);
	*res += strlen;
}
