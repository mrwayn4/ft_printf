/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:32:27 by ibouram           #+#    #+#             */
/*   Updated: 2023/12/07 18:33:25 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenptr(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

void	ft_putptr(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	ft_printf_ptr(unsigned long ptr)
{
	int	result;

	result = 0;
	result += write(1, "0x", 2);
	if (ptr == 0)
		result += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		result += ft_lenptr(ptr);
	}
	return (result);
}
