/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:09:26 by andi              #+#    #+#             */
/*   Updated: 2023/11/13 20:23:28 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchard_p2(char c)
{
	write(1, &c, 1);
}

static int	countdig2(unsigned int num)
{
	unsigned int	i;

	i = 0;
	if (num == 0)
		i = 1;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

unsigned int	ft_putunsnbr_pf(unsigned int num)
{
	unsigned int	n;

	n = num;
	if (n > 9)
	{
		ft_putunsnbr_pf(n / 10);
	}
	ft_putchard_p2((n % 10) + '0');
	return (countdig2(num));
}
