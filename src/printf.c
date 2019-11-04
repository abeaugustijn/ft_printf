/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:02:47 by abe            #+#    #+#                */
/*   Updated: 2019/11/04 21:23:19 by abe           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_printf(const char *format, ...)
{
	t_list	*vars;

	vars = parse_format(format);
	while (vars->next)
	{
		ft_putnbr_fd(((t_var *)vars->content)->type, 1);
		ft_putchar_fd('\n', 1);
		ft_putendl_fd(((t_var *)vars->content)->format, 1);
		ft_putchar_fd('\n', 1);
		vars = vars->next;
	}
	return (0);
}