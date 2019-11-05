/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_format.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:31:04 by abe            #+#    #+#                */
/*   Updated: 2019/11/05 16:07:57 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

t_list	*parse_format(const char *format)
{
	t_list	*res;
	t_var	*to_add;
	int		i;

	res = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			to_add = var_new();
			if (to_add == NULL)
				return (NULL);
			to_add->type = char_to_var_type(&(format[i]));
			if (to_add->type == 0)
				to_add->type = 8;
			to_add->format = (char *)&(format[i]);
			if (to_add->type == UNDEFINED && format[i + 1] == '%')
				i++;
			ft_lstadd_back(&res, ft_lstnew(to_add));
		}
		i++;
	}
	return (res);
}
