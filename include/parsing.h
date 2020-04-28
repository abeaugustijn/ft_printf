/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 12:10:14 by aaugusti      #+#   #+#                  */
/*   Updated: 2019/12/07 12:11:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <t_format_info.h>

void	flags(t_format_info *info, char **format);
void	width(t_format_info *info, char **format);
void	precision(t_format_info *info, char **format);
int		specifier(t_format_info *info, char **format);
void	size(t_format_info *info, char **format);

#endif
