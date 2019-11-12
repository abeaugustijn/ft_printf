/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:58:28 by aaugusti          #+#    #+#             */
/*   Updated: 2019/11/12 16:14:53 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H
# include <ft_printf.h>

void	f_string(t_format_info *info, va_list *args);
void	f_char(t_format_info *info, va_list *args);

#endif
