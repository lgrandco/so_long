/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:15:05 by root              #+#    #+#             */
/*   Updated: 2023/08/03 19:08:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_open_file(char *file, t_list *ret, t_list **node)
{
	ret->fd = open(file, O_RDONLY);
	if (ret->fd < 0)
	{
		free(ret);
		destroy_exit(0, "Error\nMap not found\n");
	}
	*node = ret;
	ret->len = 0;
	ret->read_ret = 1;
}

t_list	*get_file(char *file)
{
	t_list	*ret;
	t_list	*node;

	ret = malloc(sizeof(*ret));
	ft_open_file(file, ret, &node);
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
