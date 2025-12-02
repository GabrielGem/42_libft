/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrgarc <gabrgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:47:52 by gabrgarc          #+#    #+#             */
/*   Updated: 2025/12/02 17:10:24 by gabrgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static t_bucket	*head[FD_LIMIT] = {0};
	char			*line;
	int				break_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	break_line = 0;
	while (break_line == 0)
	{
		if (get_hunk_line(&head[fd], fd))
			return (free_list(&head[fd]));
		if (last_node(&head[fd])->content[0] == 0)
			break ;
		break_line = get_info_node(&head[fd]);
	}
	line = NULL;
	if (!head[fd]->read_bytes)
		return (free_list(&head[fd]));
	join_line(&head[fd], &line, 0);
	if (!line)
		return (free_list(&head[fd]));
	head[fd] = check_remain(&head[fd]);
	return (line);
}

int	get_hunk_line(t_bucket **head, int fd)
{
	t_bucket	*actual;

	if (!*head)
		*head = init_node();
	if (!*head)
		return (1);
	if ((*head)->len != (*head)->read_bytes)
		return (0);
	actual = last_node(head);
	actual->content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!actual->content)
		return (1);
	actual->read_bytes = read(fd, actual->content, BUFFER_SIZE);
	if (actual->read_bytes < 0)
		return (1);
	actual->content[actual->read_bytes] = '\0';
	return (0);
}

int	get_info_node(t_bucket **head)
{
	t_bucket	*actual;

	if (!head)
		return (0);
	actual = last_node(head);
	if (actual->content[0] == 0)
		return (++actual->len);
	actual->len = 0;
	while (actual->content[actual->len] != '\0')
	{
		if (actual->content[actual->len] == '\n'
			|| ((actual->content[actual->len] == 0)
				&& (actual->len < actual->read_bytes)))
			return (++actual->len);
		actual->len++;
	}
	if (actual->len > actual->read_bytes)
		actual->read_bytes = actual->len;
	actual->next = init_node();
	return (0);
}
