/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:17:40 by andi              #+#    #+#             */
/*   Updated: 2023/11/13 20:22:56 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchard_p1(char c)
{
	write(1, &c, 1);
}

static int	countdig(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i = 1;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_pf(int num)
{
	int	n;

	n = num;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_pf(n / 10);
		}
		ft_putchard_p1((n % 10) + '0');
	}
	return (countdig(num));
}
