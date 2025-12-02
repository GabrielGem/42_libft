/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:56:01 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/02 17:44:05 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_aux_ptr(va_list ap, t_format *format)
{
	char				*address;
	int					count;
	unsigned long int	ptr;

	count = 0;
	ptr = va_arg(ap, unsigned long int);
	if (!ptr)
	{
		if (format->width > 5)
			count = ft_pad(format->width - 5, format);
		ft_putstr_fd("(nil)", 1);
		return (count + 5);
	}
	address = ft_uitoa_base(ptr, "0123456789abcdef");
	count = ft_strlen(address) + 2;
	if (format->width > count)
		count += ft_pad(format->width - count, format);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(address, 1);
	free(address);
	return (count);
}
