/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazari <mamazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:50:49 by mamazari          #+#    #+#             */
/*   Updated: 2024/01/25 19:14:09 by mamazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr_base_16(unsigned int nb, char *base, int *i)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		*i += 1;
		nb *= -1;
	}
	if (nb < base_len)
	{
		ft_putchar(base[nb]);
		*i += 1;
		return ;
	}
	else
		ft_putnbr_base(nb / base_len, base, i);
	ft_putchar(base[nb % base_len]);
	*i += 1;
}

void	ft_putnbr_base(int nbr, char *base, int *i)
{
	long	nb;
	int		base_len;

	base_len = ft_strlen(base);
	nb = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		*i += 1;
		nb *= -1;
	}
	if (nb < base_len)
	{
		ft_putchar(base[nb]);
		*i += 1;
		return ;
	}
	else
		ft_putnbr_base(nb / base_len, base, i);
	ft_putchar(base[nb % base_len]);
	*i += 1;
}

void	ft_putnbr_base_pt(unsigned long nbr, char *base, int *i)
{
	unsigned long	nb;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	nb = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		*i += 1;
		nb *= -1;
	}
	if (nb < base_len)
	{
		ft_putchar(base[nb]);
		*i += 1;
		return ;
	}
	else
		ft_putnbr_base_pt(nb / base_len, base, i);
	ft_putchar(base[nb % base_len]);
	*i += 1;
}
