/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:58:02 by ibouram           #+#    #+#             */
/*   Updated: 2023/12/09 12:12:26 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arg, char target)
{
	int	value;

	value = 0;
	if (target == 'c')
		value += ft_putchar(va_arg(arg, int));
	else if (target == 's')
		value += ft_putstr(va_arg(arg, char *));
	else if (target == 'd' || target == 'i')
		value += ft_putdigit(va_arg(arg, int));
	else if (target == 'x' || target == 'X')
		value += ft_put_hex(va_arg(arg, unsigned int), target);
	else if (target == 'p')
		value += ft_printf_ptr(va_arg(arg, unsigned long));
	else if (target == 'u')
		value += ft_unsint(va_arg(arg, unsigned int));
	else if (target == '%')
		value += ft_putchar('%');
	else
		value += ft_putchar(target);
	return (value);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		value;
	int		i;

	value = 0;
	i = 0;
	va_start(arg, format);
	if (write (1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				value += ft_format(arg, format[i + 1]);
				i++;
			}
		}
		else
			value += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (value);
}
