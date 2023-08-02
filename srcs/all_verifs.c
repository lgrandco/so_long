/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_verifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:31:34 by root              #+#    #+#             */
/*   Updated: 2023/08/02 16:17:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	verif_move(int x, int y, t_vars *vars)
{
	int	pos;

	pos = y * vars->map_width + y + x;
	if ((vars->file->str)[pos] == '1' || ((vars->file->str)[pos] == 'E'
			&& vars->collected_items != vars->map_items))
	{
		return (-1);
	}
	else if ((vars->file->str)[pos] == 'C' && !(vars->file->visited)[pos])
	{
		(vars->file->str)[pos] = 1;
		vars->collected_items++;
		return (1);
	}
	else if ((vars->file->str)[pos] == 'E')
	{
		exit(0);
		return (2);
	}
	return (0);
}

int	verif_end_of_line(t_list *node, t_vars *vars, int *i, int *j)
{
	char	c;

	c = (node->str)[*i];
	if (c == '\n')
	{
		if (*i + 1 != node->len)
			vars->last_line_is_wall = 1;
		if ((vars->map_width != -1 && *j != vars->map_width) || (node->str)[*i
			- 1] != '1')
		{
			return (-1);
		}
		vars->map_width = *j;
		*j = -1;
		vars->map_height++;
	}
	return (0);
}

int	loop_to_end_of_buff(t_list *node, t_vars *vars, int *i, int *j)
{
	char	c;

	vars->last_line_is_wall = 1;
	while (*i < node->len)
	{
		c = (node->str)[*i];
		if (c != '\n' && (!*j || vars->map_height == 0) && c != '1')
			return (-1);
		vars->last_line_is_wall = vars->last_line_is_wall * (c == '1'
			|| c == '\n');
		if (verif_end_of_line(node, vars, i, j) == -1)
			return (-1);
		if (c != '\n' && c != '1' && c != '0' && c != 'E' && c != 'C'
			&& c != 'P')
		{
			return (-1);
		}
		(*i)++;
		(*j)++;
	}
	if (!vars->last_line_is_wall)
		return (-1);
	return (0);
}

int	verif_map(t_vars *vars)
{
	t_list	*node;
	int		j;
	int		i;

	j = 0;
	node = vars->file;
	while (node)
	{
		i = 0;
		if (loop_to_end_of_buff(node, vars, &i, &j) == -1)
			return (-1);
		node = node->next;
	}
	return (0);
}
