/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 19:47:59 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/14 17:53:22 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/gen_fncts.h"
#include "./include/print_fncts.h"
#include "./include/util_fncts.h"
#include "./libft/libft.h"
#include "./ft_printf.h"

int	converter(va_list arg, char **traverse, t_variable var)
{
	int count;

	count = 0;
	if (**traverse == 'c' || **traverse == 'C' ||
		**traverse == 's' || **traverse == 'S')
		count += printstring(arg, traverse, var);
	else if (**traverse == 'd' || **traverse == 'i' || **traverse == 'D')
		count += printdigit(arg, var);
	else if (**traverse == 'o' || **traverse == 'O')
		count += printoctal(arg, traverse);
	else if (**traverse == 'x' || **traverse == 'X')
		count += printhex(arg, traverse, var);
	else if (**traverse == 'u' || **traverse == 'U')
		count += printunsigned(arg, var);
	else if (**traverse == 'p')
		count += printpointer(arg);
	else
	{
		ft_putchar_fd(**traverse, 1);
		count++;
	}
	if ((var.flag == '-' || var.flag2 == '-') && count < var.width)
	{
		var.width -= count;
		while (var.width > 0)
		{
			ft_putchar_fd(' ', 1);
			var.width--;
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	char				*traverse;
	int					count;
	va_list				arg;
	t_variable			vars;
	char				*set;

	set = "cspdiuxX";
	va_start(arg, format);
	traverse = (char *)format;
	count = 0;
	while (*traverse != '\0')
	{
		while (*traverse != '%' && *traverse != '\0')
		{
			ft_putchar_fd(*traverse, 1);
			traverse++;
			count++;
			if (*traverse == '\0')
				return (count);
		}
		if (*traverse == '%')
		{
			traverse++;
			vars = populatevar(&traverse);
			count += converter(arg, &traverse, vars);
			traverse++;
		}
	}
	va_end(arg);
	return (count);
}
