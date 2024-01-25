/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazari <mamazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:15:48 by mamazari          #+#    #+#             */
/*   Updated: 2024/01/25 19:15:37 by mamazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg(int type, va_list list, int j)
{
	if (type == 1)
		j = ft_putstr(va_arg(list, char *));
	else if (type == 2)
		ft_putnbr_base(va_arg(list, int), "0123456789", &j);
	else if (type == 3)
	{
		ft_putchar(va_arg(list, int));
		j = 1;
	}
	else if (type == 4)
		ft_putnbr_base_16(va_arg(list, unsigned int), "0123456789abcdef", &j);
	else if (type == 5)
		ft_putnbr_base_16(va_arg(list, unsigned int), "0123456789ABCDEF", &j);
	else if (type == 6)
	{
		j = ft_putstr("0x");
		ft_putnbr_base_pt(va_arg(list, unsigned long), "0123456789abcdef", &j);
	}
	else if (type == 7)
		ft_putnbr_base_pt(va_arg(list, unsigned int), "0123456789", &j);
	else if (type == 8)
		j = ft_putstr("%");
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		j;
	int		count;

	va_start(list, str);
	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if (is_spec(str[i], str[i + 1]))
		{
			count += get_arg(get_type(str[i + 1]), list, j);
			i += 2;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			count++;
		}
	}
	va_end(list);
	return (count);
}
