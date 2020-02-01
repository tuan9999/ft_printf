/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_fncts.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 12:53:19 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/14 16:38:28 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_FNCTS_H
# define UTIL_FNCTS_H

typedef struct		s_variable
{
	char			flag;
	char			flag2;
	char			pflag;
	int				width;
	int				precision;
	char			*specifier;
}					t_variable;

t_variable			populatevar(char **traverse);
int					ft_isin(char c, char const *set);

#endif
