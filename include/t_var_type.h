/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_var_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:58:59 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/06 15:21:57 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VAR_TYPE_H
# define T_VAR_TYPE_H

typedef enum	e_var_type {
	CHAR,
	STRING,
	POINTER,
	INT,
	UNSIGNED,
	HEX_LOW,
	HEX_UP,
	PERCENTAGE,
	UNDEFINED
}				t_var_type;

#endif
