/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   var_dup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 12:27:10 by aaugusti       #+#    #+#                */
/*   Updated: 2019/11/05 15:38:54 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>

void	*var_dup_ptr(void *src)
{
	void	*res;

	res = malloc(sizeof(void *));
	*((char *)res) = *((char *)src);
	return (res);
}

void	*var_dup_char(char c)
{
	void	*res;

	res = malloc(1);
	((char *)res)[0] = c;
	return (res);
}

void	*var_dup_int(int i)
{
	void	*res;

	res = malloc(sizeof(int));
	((int *)res)[0] = i;
	return (res);
}

void	*var_dup_uint(unsigned int i)
{
	void	*res;

	res = malloc(sizeof(unsigned int));
	((unsigned int *)res)[0] = i;
	return (res);
}

void	*var_dup_ulong(unsigned long i)
{
	void	*res;

	res = malloc(sizeof(unsigned long));
	((unsigned long *)res)[0] = i;
	return (res);
}
