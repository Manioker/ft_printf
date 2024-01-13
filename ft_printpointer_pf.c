/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer_pf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacca <avacca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:59:31 by andi              #+#    #+#             */
/*   Updated: 2024/01/13 15:44:38 by avacca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_pp(unsigned long long num)
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

static int	ft_putlhex_pp(unsigned long long num)
{
	char				*base;
	char				*str;
	int					i;
	unsigned long long	n;

	n = num;
	if (n == 0)
		return (write(1, "0", 1));
	str = (char *)malloc((count_pp(n) + 1) * sizeof(char));
	if (!str)
		return (-1);
	base = "0123456789abcdef";
	i = 0;
	while (n > 0)
	{
		str[i++] = base[n % 16];
		n = n / 16;
	}
	str[i] = '\0';
	write(1, "0x", 2);
	ft_putstrrev_pf(str);
	free(str);
	return (i + 2);
}

int	ft_printpointer_pf(void *ptr)
{
	unsigned long long	num;

	if (!ptr)
		return (write(1, "(nil)", 5));
	num = (unsigned long long)ptr;
	return (ft_putlhex_pp(num));
}

// int main()
// {
// 	void *str = (char *)malloc(5 * sizeof(char));
// 	printf("%p\n", str);
// 	printf("\n%d\n", ft_printpointer(str));
// }