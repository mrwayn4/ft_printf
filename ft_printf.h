/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:57:57 by ibouram           #+#    #+#             */
/*   Updated: 2023/12/09 11:22:33 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	ft_putptr(unsigned long nb);
void	ft_putunbr(unsigned int nb);
void	ft_putnbr(int n);
int		ft_length(int n);
int		ft_ulength(unsigned int n);
int		ft_unsint(unsigned int nb);
int		ft_put_hex(unsigned int nb, char target);
int		ft_lenhex(unsigned int nb);
int		ft_lenptr(unsigned long nb);
int		ft_printf_ptr(unsigned long ptr);
int		ft_printf(const char *format, ...);
int		ft_format(va_list arg, char target);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_format(va_list arg, char target);
int		ft_putdigit(int nb);
#endif