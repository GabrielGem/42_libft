/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:36:24 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/10/08 19:17:17 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len_str(char **tab)
{
	int	num_chr;
	int	i;

	i = 0;
	num_chr = 0;
	while (*(tab + i))
	{
		num_chr += ft_strlen(tab[i]);
		i++;
	}
	num_chr += i - 1;
	return (num_chr);
}

char	*ft_rsplit(char **tab, char c)
{
	char	*str;
	char	*temp;
	int		len;

	len = count_len_str(tab);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (*(tab))
	{
		temp = *(tab);
		while (*temp)
			*str++ = *temp++;
		if (*(tab + 1))
			*str++ = c;
		tab++;
	}
	*str = '\0';
	return (&str[-len]);
}
