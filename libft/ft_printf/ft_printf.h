/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:52:29 by akechedz          #+#    #+#             */
/*   Updated: 2026/01/29 20:14:21 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# if defined(__linux__)
#  define PTRNULL "(nil)"
#  define NPTRSIZE 5
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
#  define NPTRSIZE 3
# endif

//ft_printf.c
int		ft_printf(const char	*format, ...);
int		swtch_fmt(const char *fmt, va_list list);
int		ft_putptr(unsigned long ptr);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_print_intern(va_list	arg, const char *fmt);

//ft_putnbr.c
int		ft_putnbr(int n);

//ft_putnbr_unsigned.c
int		ft_putnbr_unsigned(unsigned int n);

//ft_putptr_ul.c
int		ft_putptr_ul(unsigned long ptr);

//ft_puthex_unsigned.c
int		ft_puthex_unsigned(unsigned int n, int uppercase);

//ft_strlen.c
size_t	ft_strlen(const char *str);
#endif