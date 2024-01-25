/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazari <mamazari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:51:55 by mamazari          #+#    #+#             */
/*   Updated: 2024/01/25 18:13:42 by mamazari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
void	ft_putchar(char c);
int		ft_putstr(const char *s);
void	ft_putnbr_base_pt(unsigned long nbr, char *base, int *i);
void	ft_putnbr_base_16(unsigned int nb, char *base, int *i);
void	ft_putnbr_base(int nb, char *base, int *i);
int		ft_putstr_till_spec(const char *str, int i);
int		ft_putstr_end(const char *str, int i);
int		is_spec(char a, char b);
int		is_type(char c);
int		get_type(char c);
int		ft_strcmp(const char *s1, const char *s2);

#endif