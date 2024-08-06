/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:31:24 by ibouram           #+#    #+#             */
/*   Updated: 2023/12/09 10:49:56 by ibouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenhex(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		count ++;
		nb = nb / 16;
	}
	return (count);
}

int	ft_put_hex(unsigned int nb, char target)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
	{
		if (nb >= 16)
		{
			ft_put_hex(nb / 16, target);
			ft_put_hex(nb % 16, target);
		}
		else
		{
			if (nb <= 9)
				ft_putchar(nb + '0');
			else
			{
				if (target == 'x')
					ft_putchar(nb - 10 + 'a');
				else if (target == 'X')
					ft_putchar(nb - 10 + 'A');
			}
		}
	}
	return (ft_lenhex(nb));
}
