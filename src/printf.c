/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:02:47 by abe            #+#    #+#                */
/*   Updated: 2019/11/05 14:16:18 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	t_list	*vars;
	va_list	*args;
	int		expected_argc;

	vars = parse_format(format);
	expected_argc = get_expected_argc(vars);
	args = (va_list *)malloc(sizeof(va_list));
	va_start(*args, expected_argc);
	get_arg_values(vars, args, expected_argc);
	va_end(*args);
	while (vars)
	{
		ft_putnbr_fd(((t_var *)vars->content)->type, 1);
		ft_putchar_fd('\n', 1);
		ft_putendl_fd(((t_var *)vars->content)->format, 1);
		ft_putchar_fd('\n', 1);
		vars = vars->next;
	}
	return (0);
}

int	main(void)
{
	char	*str;

	str = "dnf%sdndg%%djfgn%s%djfg";
	ft_putendl_fd(str, 1);
	ft_printf(str, "test", "test2", 123);
}
