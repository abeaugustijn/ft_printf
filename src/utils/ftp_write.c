/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_write.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/28 13:26:15 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/06/16 18:09:56 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>

/*
**	The function which writes the characters to the output of the function.
**	This can either be stdout or a char buffer.
*/

void	ftp_write(char *to_write, char **target, size_t n, int *tot_written)
{
	int	write_return;

	if (target)
	{
		ft_memcpy(*target, to_write, n);
		(*target) += sizeof(char) * n;
	}
	else
	{
		write_return = write(FD, to_write, n);
		if (write_return == -1)
			return;
	}
	if (tot_written)
		(*tot_written) += n;
}
