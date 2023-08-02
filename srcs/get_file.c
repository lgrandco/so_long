/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:15:05 by root              #+#    #+#             */
/*   Updated: 2023/08/02 22:23:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_open_file(char *file, t_list *ret)
{
	ret->fd = open(file, O_RDONLY);
	if (ret->fd < 0)
	{
		free(ret);
		destroy_exit(0, "Error\nMap not found\n");
	}
}

t_list	*get_file(char *file)
{
	t_list	*ret;
	t_list	*node;

	ret = malloc(sizeof(*ret));
	ft_open_file(file, ret);
	node = ret;
	ret->read_ret = 1;
	while (ret->read_ret > 0)
	{
		if (ret->read_ret == SIZE)
		{
			node->next = malloc(sizeof(*node));
			node = node->next;
		}
		ret->read_ret = read(ret->fd, node->str, SIZE);
		if (ret->read_ret < 0)
		{
			free(ret);
			destroy_exit(0, "Error\nDirectory found\n");
		}
		if (ret->read_ret)
			node->len = ret->read_ret;
	}
	node->next = 0;
	return (ret);
}
