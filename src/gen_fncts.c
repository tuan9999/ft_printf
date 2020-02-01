/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_fncts.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 14:10:36 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/13 17:33:58 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gen_fncts.h"
#include "../libft/libft.h"

char	*convertupper(unsigned long num, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
	{
		ptr--;
		*ptr = '0';
	}
	while (num != 0)
	{
		--ptr;
		*ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convertlower(unsigned long num, int base)
{
	static char representation[] = "0123456789abcdef";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
	{
		ptr--;
		*ptr = '0';
	}
	while (num != 0)
	{
		--ptr;
		*ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

char	*converthex(float num, int base)
{
	static char representation[] = "0123456789abcdef";
	static char buffer[50];
	char		*ptr;
	int			nm;
	int			decimal;

	ptr = &buffer[49];
	*ptr = '\0';
	nm = num / 1;
	decimal = num;
	while (decimal != 0)
	{
		--ptr;
		*ptr = representation[decimal % base];
		decimal /= base;
	}
	return (ptr);
}

int		digitcount(long n)
{
	int		temp;
	int		count;

	count = 0;
	temp = n;
	if (temp == 0)
		count++;
	if (temp < 0)
	{
		count++;
		temp *= -1;
	}
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	return (count);
}
