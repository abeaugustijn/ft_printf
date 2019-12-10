/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:40:59 by aaugusti       #+#    #+#                */
/*   Updated: 2019/11/28 11:25:39 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	Write zeroes to a byte string.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
