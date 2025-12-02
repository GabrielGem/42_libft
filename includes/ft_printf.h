/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:41:06 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/11/19 18:51:33 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_format	t_format;

typedef int				(*t_spec)(va_list ap, t_format *flags);

struct s_format
{
	char	flags;
	int		width;
	int		precision;
	char	specifier;
	t_spec	ft_specifier;
	int		index_spec;
};

enum e_flags
{
	MINUS = 0b1,
	PLUS = 0b10,
	SPACE = 0b100,
	HASHTAG = 0b1000,
	ZERO = 0b10000,
	DOT = 0b100000
};

int			ft_printf(char const *s, ...);

t_format	initformat(void);
int			parse(const char *str, t_format *parameters);
int			isspecifier(char c);
int			isflag(char c);

void		flag_space(t_format *parameters);
void		flag_minus(t_format *parameters);
void		flag_width(t_format *parameters, char c);
void		switch_flags(t_format *format, char c);

int			ft_pad(int size, t_format *parameters);
char		sign(t_format *format, int num);
int			prefix(t_format *format);
char		*precision(t_format *format, char *num);

int			ft_aux_char(va_list ap, t_format *format);
int			ft_aux_str(va_list ap, t_format *format);
int			ft_aux_ptr(va_list ap, t_format *format);
int			ft_aux_nbr(va_list ap, t_format *format);
int			ft_aux_unbr(va_list ap, t_format *format);
int			ft_aux_hex(va_list ap, t_format *format);

#endif
