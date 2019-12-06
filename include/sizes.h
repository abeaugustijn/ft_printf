/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 09:38:26 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/06 11:56:12 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZES_H
# define SIZES_H
# include <t_format_info.h>
# include <stdarg.h>

long long int	sz_int(t_format_info *info, va_list *args);
long long int	sz_hex(t_format_info *info, va_list *args);

#endif
