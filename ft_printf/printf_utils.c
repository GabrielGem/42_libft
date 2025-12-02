/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:56:03 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/02 17:44:35 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	isspecifier(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	isflag(char c)
{
	if (ft_strchr("-0.# +", c))
		return (1);
	return (0);
}

void	switch_flags(t_format *format, char c)
{
	if (c == '-')
		format->flags |= MINUS;
	if (c == '+')
		format->flags |= PLUS;
	if (c == ' ')
		flag_space(format);
	if (c == '#')
		format->flags |= HASHTAG;
	if (c == '0' && format->width == 0 && !(format->flags & MINUS))
		format->flags |= ZERO;
	if (c == '.')
		format->flags |= DOT;
}

t_format	initformat(void)
{
	t_format	form;

	form.flags = 0;
	form.precision = 0;
	form.width = 0;
	form.specifier = 0;
	form.ft_specifier = NULL;
	form.index_spec = 0;
	return (form);
}
