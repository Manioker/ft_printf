/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:38 by andi              #+#    #+#             */
/*   Updated: 2023/11/13 20:23:20 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countdigit(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i = 1;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int	ft_putuhex_pf(unsigned int num)
{
	char			*base;
	char			*str;
	int				i;
	unsigned int	n;

	n = num;
	str = (char *)malloc((countdigit(n) + 1) * sizeof(char));
	if (!str)
		return (-1);
	if (n == 0)
	{
		free(str);
		return (write(1, "0", 1));
	}
	base = "0123456789ABCDEF";
	i = 0;
	while (n > 0)
	{
		str[i++] = base[n % 16];
		n = n / 16;
	}
	str[i] = '\0';
	ft_putstrrev_pf(str);
	free(str);
	return (i);
}

// int	main(void)
// {
// 	printf("\n%d\n", ft_putuhex_pf(-1));
// 	printf("%d\n", printf("%X", -1));
// }