/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd_count.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:12:18 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 13:35:28 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <t_format_info.h>
#include <unistd.h>
#include <utils.h>

void	ft_putchar_fd_count(char **tgt, char c, int *count)
{
	(void)tgt;
	ftp_write(&c, tgt, 1, count);
	(*count)++;
}
