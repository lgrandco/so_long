/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:30:12 by root              #+#    #+#             */
/*   Updated: 2023/08/03 12:50:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	dfs(t_vars *vars, int x, int y)
{
	int	pos;

	pos = y * vars->map_width + y + x;
	if ((vars->file->str)[pos] == '\n' || (vars->file->str)[pos] == '1'
		|| (vars->file->tile_visited)[pos])
		return ;
	(vars->file->tile_visited)[pos] = 1;
	if ((vars->file->str)[pos] == 'C')
		vars->path_items++;
	if ((vars->file->str)[pos] == 'E')
		vars->path_exit++;
	dfs(vars, x + 1, y);
	dfs(vars, x - 1, y);
	dfs(vars, x, y + 1);
	dfs(vars, x, y - 1);
}

void	verif_path(t_vars *vars)
{
	vars->path_exit = 0;
	vars->path_items = 0;
	dfs(vars, vars->player_pos_x, vars->player_pos_y);
	if (vars->path_exit != 1 || vars->map_items != vars->path_items)
	{
		destroy_exit(vars, "Error\nNo correct path found\n");
	}
}
