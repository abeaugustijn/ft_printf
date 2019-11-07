/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   var_new.c                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:36:10 by abe            #+#    #+#                */
/*   Updated: 2019/11/07 20:24:24 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

t_var	*var_new(void)
{
	t_var	*res;

	res = (t_var *)malloc(sizeof(t_var));
	if (res == NULL)
		return (NULL);
	res->type = 0;
	res->format = NULL;
	res->value = NULL;
	res->res = NULL;
	return (res);
}
