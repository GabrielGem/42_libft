/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:18:39 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/07 18:29:25 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *s)
{
	int		sign;
	double	exponent;
	double	precission;
	double	mantissa;
	double	result;

	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	exponent = ft_atoi(s);
	while (*s != '.')
		s++;
	mantissa = ft_atoi(++s);
	precission = 10.0;
	while (ft_isdigit(*++s))
		precission *= 10.0;
	result = ((exponent + (mantissa / precission)) * sign);
	return (result);
}
