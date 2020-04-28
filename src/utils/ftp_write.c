/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_write.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/28 13:26:15 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 14:20:36 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#ifdef SPRINTF
# include <libft.h>
#else
# include <unistd.h>
#endif

/*
**	The function which writes the characters to the output of the function.
**	This can either be stdout or a char buffer.
*/

#ifdef SPRINTF

void	ftp_write(char *to_write, char **target, size_t n, int *tot_written)
{
	ft_memcpy(*target, to_write, n);
	(*target) += sizeof(char) * n;
	if (tot_written)
		(*tot_written) += n;
}

#else


void	ftp_write(char *to_write, char **target, size_t n, int *tot_written)
{
	(void)target;
	write(FD, to_write, n);
	if (tot_written)
		(*tot_written) += n;
}

#endif
