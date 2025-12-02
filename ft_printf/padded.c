/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padded.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:42:18 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/02 17:44:05 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pad(int size, t_format *parameters)
{
	char	c;
	int		printd;

	printd = size;
	c = ' ';
	if (parameters->flags & ZERO && !(parameters->flags & DOT))
		c = '0';
	if (size < 0)
		return (0);
	while (size--)
		ft_putchar_fd(c, 1);
	return (printd);
}

char	sign(t_format *format, int num)
{
	if ((format->flags & PLUS) && num >= 0)
		return ('+');
	if ((format->flags & SPACE) && num >= 0)
		return (' ');
	if (num < 0)
		return ('-');
	return (0);
}

int	prefix(t_format *format)
{
	if (format->specifier == 'x')
		ft_putstr_fd("0x", 1);
	if (format->specifier == 'X')
		ft_putstr_fd("0X", 1);
	return (2);
}

char	*precision(t_format *format, char *str_nbr)
{
	int		len;
	int		i;
	int		lending_zeros;
	char	*new_str;

	if (str_nbr[0] == '0' && format->precision == 0)
	{
		free(str_nbr);
		new_str = ft_calloc(1, 1);
		return (new_str);
	}
	len = ft_strlen(str_nbr);
	if (format->precision <= len)
		return (str_nbr);
	lending_zeros = format->precision - len;
	if (format->precision > len)
		new_str = ft_calloc(sizeof(char), format->precision + 1);
	i = 0;
	while (i < lending_zeros)
		new_str[i++] = '0';
	while (len--)
		new_str[i + len] = str_nbr[len];
	free(str_nbr);
	return (new_str);
}
