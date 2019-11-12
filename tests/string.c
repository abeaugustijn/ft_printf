/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:47:53 by abe               #+#    #+#             */
/*   Updated: 2019/11/12 21:46:34 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ft_printf.h>
#include <stdio.h>
#include <string.h>

void	redirect_stdout(void)
{
		cr_redirect_stdout();
}

/*
**	Series of test for string output in printf.
*/

Test(simple, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%s\n", "simple");
	sprintf(res, "%s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%5s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding_and_precision, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%5.5s\n", "simple");
	sprintf(res, "%5.5s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding_and_zero_fill, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%05s\n", "simple");
	sprintf(res, "%05s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding_big, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%50s\n", "simple");
	sprintf(res, "%50s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding_left_align, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%-5s\n", "simple");
	sprintf(res, "%-5s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding_left_align_and_zero, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%-05s\n", "simple");
	sprintf(res, "%-05s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding_zero, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%0s\n", "simple");
	sprintf(res, "%0s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(padding_left_align_width_is_smaller, ft_printf, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%-3s\n", "simple");
	sprintf(res, "%-3s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

