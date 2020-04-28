/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_var_type.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:58:59 by aaugusti      #+#   #+#                  */
/*   Updated: 2020/04/28 12:16:53 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VAR_TYPE_H
# define T_VAR_TYPE_H

typedef enum	e_var_type {
	UNDEFINED = 0,
	CHAR = 1,
	STRING = 2,
	POINTER = 3,
	INT = 4,
	UNSIGNED = 5,
	HEX_LOW = 6,
	HEX_UP = 7,
	PERCENTAGE = 8,
	N = 9,
}				t_var_type;

#endif
