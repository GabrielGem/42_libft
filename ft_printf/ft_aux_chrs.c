/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_chrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:36:20 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/02 17:44:04 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_aux_char(va_list ap, t_format *format)
{
	char	c;
	int		count;

	c = '%';
	if (format->specifier == 'c')
		c = va_arg(ap, int);
	count = 1;
	if (format->width > 1 && format->specifier == 'c')
		count += ft_pad(format->width - 1, format);
	ft_putchar_fd(c, 1);
	return (count);
}

int	ft_aux_str(va_list ap, t_format *format)
{
	int		count;
	int		print;
	int		i;
	char	*str;

	count = 0;
	i = -1;
	str = va_arg(ap, char *);
	if (!str && (format->flags & DOT) && format->precision < 6)
		str = "";
	if (!str)
		str = "(null)";
	count = ft_strlen(str);
	print = count;
	if ((format->flags & DOT) && format->precision < count)
	{
		print = format->precision;
		count = print;
	}
	if (format->width > count)
		count += ft_pad(format->width - print, format);
	while (++i < print)
		ft_putchar_fd(str[i], 1);
	return (count);
}
