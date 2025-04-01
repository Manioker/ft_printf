/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacca <avacca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:03 by andi              #+#    #+#             */
/*   Updated: 2024/01/13 15:57:47 by avacca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_putchard_pf(char c);
int				ft_printpointer_pf(void *ptr);
int				ft_putlhex_pf(unsigned int num);
int				ft_putnbr_pf(int num);
int				ft_putstr_pf(char *str);
int				ft_putuhex_pf(unsigned int n);
unsigned int	ft_putunsnbr_pf(unsigned int num);
void			ft_putstrrev_pf(char *str);
int				ft_printf(const char *str, ...);

#endif