/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacca <avacca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:08:18 by andi              #+#    #+#             */
/*   Updated: 2024/01/22 13:49:42 by avacca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_format(va_list args, char *str)
{
	if (*str == 'c')
		return (ft_putchard_pf(va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_printpointer_pf(va_arg(args, void *)));
	else if (*str == 'i' || *str == 'd')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_putunsnbr_pf(va_arg(args, unsigned int)));
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			return (ft_putlhex_pf(va_arg(args, unsigned int)));
		else
			return (ft_putuhex_pf(va_arg(args, unsigned int)));
	}
	else if (*str == '%')
		return (ft_putchard_pf(*str));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*string;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	string = (char *)str;
	va_start(args, str);
	while (*string && i >= 0)
	{
		if (*string != '%')
		{
			write(1, string, 1);
			i++;
		}
		else if (*string == '%')
		{
			string++;
			i = i + ft_format(args, string);
		}
		string++;
	}
	va_end(args);
	return (i);
}
