/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_fncts.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 18:55:58 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/14 17:57:23 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/gen_fncts.h"
#include "../include/util_fncts.h"
#include "../libft/libft.h"

int	printdigit(va_list arg, t_variable var)
{
	int				count;
	long			i;

	count = 0;
	i = va_arg(arg, long);
	if (i < 0)
	{
		// i *= -1;
		// if (var.flag == '+')
		// 	var.flag = 0;
		// if (var.flag == '0' || var.flag2 == '0')
		// {
		// 	ft_putchar_fd('-', 1);
		// 	count++;
		// }
	}
	if (var.flag || var.width)
	{
		if (var.width && var.flag != '-')
		{
			var.width -= digitcount(i);
			if (var.flag && var.flag != '0')
				var.width--;
			while (var.width > 0)
			{
				if (var.flag == '0' || var.flag2 == '0')
					ft_putchar_fd('0', 1);
				else
					ft_putchar_fd(' ', 1);
				var.width--;
				count++;
			}
		}
	}
	if ((var.flag == '+' && i >= 0))
	{
		ft_putchar_fd(var.flag, 1);
		count++;
	}
	if (var.precision)
	{
		var.precision -= digitcount(i);
		while (var.precision > 0)
		{
			ft_putchar_fd('0', 1);
			var.precision--;
			count++;
		}
	}
	ft_putnbr_fd(i, 1);
	count += digitcount(i);
	return (count);
}

int	printstring(va_list arg, char **traverse, t_variable var)
{
	char			*s;
	int				count;
	unsigned int	i;

	count = 0;
	if ((**traverse) == 'c' || (**traverse) == 'C')
	{
		if (var.width && var.flag != '-')
			while (var.width > 1)
			{
				ft_putchar_fd(' ', 1);
				var.width--;
				count++;
			}
		i = va_arg(arg, int);
		ft_putchar_fd(i, 1);
		count++;
	}
	else
	{
		s = va_arg(arg, char *);
		if (!s && var.width > 0 && var.pflag == '.' && var.precision == 0)
		{
			while (var.width > 0)
			{
				ft_putchar_fd(' ', 1);
				var.width--;
				count++;
			}
			return (count);
		}
		if (var.width && var.flag != '-')
		{
			if (var.pflag && s)
				var.width -= ft_strlen(ft_substr(s, 0, var.precision));
			else if (s)
				var.width -= ft_strlen(s);
			else
				var.width -= 6;
			while (var.width > 0)
			{
				ft_putchar_fd(' ', 1);
				var.width--;
				count++;
			}
		}
		if (!s)
		{
			if (var.precision && var.pflag == '.')
			{
				ft_putstr_fd(ft_substr("(null)", 0, var.precision), 1);
				count += ft_strlen(ft_substr("(null)", 0, var.precision));
			}
			else
			{
				ft_putstr_fd("(null)", 1);
				count += 6;
			}
		}
		else
		{
			if (var.pflag)
			{
				if (var.precision == 0 || !var.precision)
				{
					ft_putstr_fd("", 1);
					count++;
				}
				else
				{
					ft_putstr_fd(ft_substr(s, 0, var.precision), 1);
					count += ft_strlen(ft_substr(s, 0, var.precision));
				}
			}
			else
			{
				ft_putstr_fd(s, 1);
				count += ft_strlen(s);
			}
		}
	}
	return (count);
}

int	printoctal(va_list arg)
{
	int				count;
	unsigned int	i;

	count = 0;
	i = va_arg(arg, unsigned int);
	if (i == 0)
	{
		ft_putnbr_fd(i, 1);
		count++;
	}
	count += ft_strlen(convertlower(i, 8));
	ft_putstr_fd(convertlower(i, 8), 1);
	return (count);
}

int	printhex(va_list arg, char **traverse, t_variable var)
{
	unsigned long	i;
	int				count;
	char			*s;

	count = 0;
	i = va_arg(arg, unsigned long);
	if (**traverse == 'X')
		s = convertupper(i, 16);
	else
		s = convertlower(i, 16);
	count += ft_strlen(s);
	if (var.width && (var.flag != '-' && var.flag2 != '-'))
	{
		if (var.precision > count)
			var.width -= var.precision;
		else
			var.width -= count;
		if (var.flag == '#' && i != 0)
			var.width -= 2;
		while (var.width > 0)
		{
			if (var.flag == '0' && var.pflag != '.')
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			count++;
			var.width--;
		}
	}
	if ((var.flag == '#' || var.flag2 == '#') && i != 0)
	{
		if (**traverse == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		count += 2;
	}
	if (var.precision && var.pflag == '.')
	{
		var.precision -= ft_strlen(s);
		while (var.precision > 0)
		{
			ft_putchar_fd('0', 1);
			var.precision--;
			count++;
		}
	}
	ft_putstr_fd(s, 1);
	return (count);
}

int	ft_putnbrul_fd(unsigned long n)
{
	char		c;
	static int	count = 0;

	count++;
	if (n >= 10)
		ft_putnbrul_fd(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count);
}

int	printunsigned(va_list arg, t_variable var)
{
	unsigned long	i;
	int				count;
	int				wchek;

	count = 0;
	wchek = 0;
	i = va_arg(arg, unsigned long);
	if (var.width && var.flag != '-')
	{
		wchek = 1;
		if (var.pflag == '.')
		{
			if (digitcount(i) > var.precision)
				var.width -= digitcount(i);
			else
				var.width -= (var.precision);
		}
		else
			var.width -= digitcount(i);
		while (var.width > 0)
		{
			if (var.flag == '0' && var.pflag != '.')
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			var.width--;
			count++;
		}
	}
	if (var.pflag == '.')
	{
		if (!var.precision && i == 0)
		{
			if (wchek == 1)
			{
				ft_putchar_fd(' ', 1);
				count++;
			}
			return (count);
		}
		var.precision -= digitcount(i);
		while (var.precision > 0)
		{
			ft_putchar_fd('0', 1);
			var.precision--;
			count++;
		}
	}
	count += ft_putnbrul_fd(i);
	return (count);
}

int	printpointer(va_list arg)
{
	void			*s;
	int				count;

	count = 0;
	s = va_arg(arg, void *);
	ft_putstr_fd(s, 1);
	count += ft_strlen(s);
	return (count);
}
