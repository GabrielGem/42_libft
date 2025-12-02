/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:39:03 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/11/18 10:01:30 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_LIMIT
#  define FD_LIMIT 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_bucket
{
	int				i;
	ssize_t			len;
	ssize_t			read_bytes;
	char			*content;
	struct s_bucket	*next;
}	t_bucket;

char		*get_next_line(int fd);
int			get_hunk_line(t_bucket **head, int fd);
int			get_info_node(t_bucket **node);
char		*join_line(t_bucket **head, char **line, int i_line);
t_bucket	*check_remain(t_bucket **head);
t_bucket	*init_node(void);
t_bucket	*last_node(t_bucket **head);
void		*free_list(t_bucket **head);

#endif
