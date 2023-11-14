/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer_pf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:59:31 by andi              #+#    #+#             */
/*   Updated: 2023/11/13 20:22:31 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_pp(int num)
{
	int	i;

	i = 0;
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

static int	ft_putlhex_pp(unsigned long long num)
{
	char				*base;
	char				*str;
	int					i;
	unsigned long long	n;

	n = num;
	str = (char *)malloc(count_pp(n) * sizeof(char));
	if (!str)
		return (-1);
	if (n == 0)
	{
		free(str);
		return (write(1, "0", 1));
	}
	base = "0123456789abcdef";
	i = 0;
	while (n > 0)
	{
		str[i++] = base[n % 16];
		n = n / 16;
	}
	write(1, "0x", 2);
	ft_putstrrev_pf(str);
	return (i + 2);
}

int	ft_printpointer_pf(void *ptr)
{
	unsigned long long	num;

	num = (unsigned long long)ptr;
	return (ft_putlhex_pp(num));
}

// int main()
// {
// 	void *str = (char *)malloc(5 * sizeof(char));
// 	printf("%p\n", str);
// 	printf("\n%d\n", ft_printpointer(str));
// }