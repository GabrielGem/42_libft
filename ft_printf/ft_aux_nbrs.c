/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:11:59 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/02 17:44:04 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_aux_nbr(va_list ap, t_format *format)
{
	long int	num;
	int			count;
	char		signal;
	char		*result;

	num = va_arg(ap, int);
	count = 0;
	signal = sign(format, num);
	if (signal)
		count = 1;
	if (num < 0)
		num *= -1;
	result = ft_itoa_base(num, "0123456789");
	if (signal && format->flags & ZERO && !(format->flags & DOT))
		ft_putchar_fd(signal, 1);
	if (format->flags & DOT)
		result = precision(format, result);
	count += ft_strlen(result);
	if (format->width > count)
		count += ft_pad(format->width - count, format);
	if (signal && (!(format->flags & ZERO) || (format->flags & DOT)))
		ft_putchar_fd(signal, 1);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}

int	ft_aux_unbr(va_list ap, t_format *format)
{
	int		count;
	char	*result;

	count = 0;
	result = ft_uitoa_base(va_arg(ap, unsigned int), "0123456789");
	if (!*result)
	{
		free(result);
		result = ft_calloc(2, 1);
		result[0] = '0';
	}
	if (format->flags & DOT)
		result = precision(format, result);
	count = ft_strlen(result);
	if (format->width > count)
		count += ft_pad((format->width - count), format);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}

int	ft_aux_hex(va_list ap, t_format *format)
{
	char	*result;
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	if (format->specifier == 'X')
		symbols = "0123456789ABCDEF";
	result = ft_itoa_base(va_arg(ap, unsigned int), symbols);
	if (format->flags & DOT)
		result = precision(format, result);
	count = ft_strlen(result);
	if (format->flags & HASHTAG && result[0] != '0')
		count += prefix(format);
	if ((format->flags & HASHTAG) && format->width > count + 2)
		count += ft_pad(format->width - count, format);
	if (!(format->flags & HASHTAG) && format->width > count)
		count += ft_pad((format->width - count), format);
	ft_putstr_fd(result, 1);
	free(result);
	return (count);
}
