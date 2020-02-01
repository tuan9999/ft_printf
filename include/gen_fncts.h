/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_fncts.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 19:47:52 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/14 11:44:37 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_FNCTS_H
# define GEN_FNCTS_H
# include <unistd.h>
# include <stdarg.h>

char	*convertupper(unsigned long num, int base);
char	*convertlower(unsigned long num, int base);
char	*converthex(float num, int base);
int		digitcount(long n);

#endif
