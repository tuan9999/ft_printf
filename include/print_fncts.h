/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_fncts.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 18:56:49 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/13 15:07:59 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FNCTS_H
# define PRINT_FNCTS_H
# include <unistd.h>
# include <stdarg.h>
# include "util_fncts.h"

int	printdigit(va_list arg, t_variable var);
int	printstring(va_list arg, char **traverse, t_variable var);
int	printoctal(va_list arg, char **traverse);
int	printhex(va_list arg, char **traverse, t_variable var);
int	printunsigned(va_list arg, t_variable var);
int	printpointer(va_list arg);
int	ft_putnbrul_fd(unsigned long n);

#endif
