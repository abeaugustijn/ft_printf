/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:47:53 by abe               #+#    #+#             */
/*   Updated: 2019/11/16 11:29:28 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ft_printf.h>
#include <stdio.h>
#include <string.h>

/*
**	Series of test for string output in printf.
*/

void	redirect_stdout(void)
{
		cr_redirect_stdout();
}

/*
** standard
*/

Test(standard, simple, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%s\n", "simple");
	sprintf(res, "%s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

/*
** padding
*/

Test(width, simple, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%5s\n", "simple");
	sprintf(res, "%5s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, zero_fill, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%05s\n", "simple");
	sprintf(res, "%05s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, big, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%50s\n", "simple");
	sprintf(res, "%50s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, left_align, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%-5s\n", "simple");
	sprintf(res, "%-5s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, left_align_and_zero, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%-05s\n", "simple");
	sprintf(res, "%-05s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, zero, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%0s\n", "simple");
	sprintf(res, "%0s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, left_align_width_is_smaller, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%-3s\n", "simple");
	sprintf(res, "%-3s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, negative, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%--3s\n", "simple");
	sprintf(res, "%--3s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, int_overflow, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%999999999999s\n", "simple");
	sprintf(res, "%999999999999s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, long_overflow, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%999999999999999999999999999s\n", "simple");
	sprintf(res, "%999999999999999999999999999s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, neg_int_overflow, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%--999999999999s\n", "simple");
	sprintf(res, "%--999999999999s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(width, neg_long_overflow, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%--999999999999999999999999999s\n", "simple");
	sprintf(res, "%--999999999999999999999999999s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

/*
**	precision
*/

Test(precision, standard, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%.2s\n", "simple");
	sprintf(res, "%.2s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(precision, negative, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%.-2s\n", "simple");
	sprintf(res, "%.-2s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(precision, big, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%.20s\n", "simplealskjdhahdlhdlahsdjlasdjl");
	sprintf(res, "%.20s\n", "simplealskjdhahdlhdlahsdjlasdjl");
	cr_assert_stdout_eq_str(res);
}

Test(precision, with_padding, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%3.2s\n", "simple");
	sprintf(res, "%3.2s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

Test(precision, zero_padding, .init=redirect_stdout)
{
	char res[1000];
	ft_printf("%0.2s\n", "simple");
	sprintf(res, "%0.2s\n", "simple");
	cr_assert_stdout_eq_str(res);
}

