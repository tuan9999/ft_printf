/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_fncts.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 12:28:50 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/14 17:05:27 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gen_fncts.h"
#include "../include/util_fncts.h"
#include "../libft/libft.h"
#include "../ft_printf.h"

t_variable			populatevar(char **traverse)
{
	t_variable	v;

	v.flag = 0;
	v.flag2 = 0;
	v.pflag = 0;
	v.width = 0;
	v.precision = 0;
	v.specifier = NULL;
	if (**traverse == ' ' || **traverse == '-' || **traverse == '+'
			|| **traverse == '0' || **traverse == '#')
	{
		v.flag = **traverse;
		while (**traverse == ' ' || **traverse == '-' || **traverse == '+'
			|| **traverse == '0' || **traverse == '#')
		{
			if (**traverse != v.flag)
				v.flag2 = **traverse;
			(*traverse)++;
		}
	}
	if (ft_isdigit(**traverse) == 1)
	{
		v.width = ft_atoi(*traverse);
		while (ft_isdigit(**traverse) == 1)
			(*traverse)++;
	}
	if (**traverse == '.')
	{
		v.pflag = '.';
		(*traverse)++;
		if (ft_isdigit(**traverse) == 1)
		{
			v.precision = ft_atoi(*traverse);
			while (ft_isdigit(**traverse) == 1)
				(*traverse)++;
		}
		else
			v.precision = 0;
	}
	if (**traverse == 'l' || **traverse == 'h')
	{
		if (**traverse == 'l')
		{
			if (*(*(traverse + 1)) == 'l')
				v.specifier = "ll";
			else
				v.specifier = "l";
		}
		if (**traverse == 'h')
		{
			if (*(*(traverse + 1)) == 'h')
				v.specifier = "hh";
			else
				v.specifier = "h";
		}
		while (**traverse == 'l' || **traverse == 'h')
			(*traverse)++;
	}
	return (v);
}

int					ft_isin(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
