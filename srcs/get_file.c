/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:15:05 by root              #+#    #+#             */
/*   Updated: 2023/08/02 15:15:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*get_file(char *file)
{
	t_list	*ret;
	t_list	*node;
	int		read_ret;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	ret = malloc(sizeof(*ret));
	node = ret;
	read_ret = 1;
	while (read_ret > 0)
	{
		if (read_ret == SIZE)
		{
			node->next = malloc(sizeof(*node));
			node = node->next;
		}
		read_ret = read(fd, node->str, SIZE);
		if (read_ret)
			node->len = read_ret;
	}
	node->next = 0;
	return (ret);
}
