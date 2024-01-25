/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazari <mamazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:12 by mamazari          #+#    #+#             */
/*   Updated: 2024/01/25 18:09:26 by mamazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_type(char c)
{
	if (c == 'd' || c == 's' || c == 'c' || \
		c == 'p' || c == 'i' || c == 'u' || \
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_spec(char a, char b)
{
	if (a == '%' && is_type(b) == 1)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	get_type(char c)
{
	if (c == 's')
		return (1);
	else if (c == 'd' || c == 'i')
		return (2);
	else if (c == 'c')
		return (3);
	else if (c == 'x')
		return (4);
	else if (c == 'X')
		return (5);
	else if (c == 'p')
		return (6);
	else if (c == 'u')
		return (7);
	else if (c == '%')
		return (8);
	return (0);
}
