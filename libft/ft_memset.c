/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:28:34 by aaugusti       #+#    #+#                */
/*   Updated: 2019/11/30 13:51:53 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Set 'len' bytes in the buffer 'b' to 'c'. Returns 'b'.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cpy;

	b_cpy = b;
	while (len > 0)
	{
		*b_cpy = (unsigned char)c;
		len--;
		b_cpy++;
	}
	return (b);
}
