/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:38:15 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/08/22 19:31:48 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers_base(long int n, int base)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++length;
	}
	while (n > 0)
	{
		n /= base;
		++length;
	}
	return (length);
}

char	*ft_itoa_base(long int n, char *symbols)
{
	long int	num;
	char		*result;
	int			len;
	int			base;

	num = n;
	base = ft_strlen(symbols);
	len = count_numbers_base(num, base);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (num < 0)
		num *= -1;
	while (len--)
	{
		result[len] = symbols[num % base];
		num /= base;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
