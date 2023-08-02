/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:25:19 by root              #+#    #+#             */
/*   Updated: 2023/08/02 16:58:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_map_char(t_vars *vars, int x, int y)
{
	ft_put_file_to_window(*vars, "imgs/background.xpm", x, y);
	if ((vars->file->str)[(vars->map_width * y) + x + y] == '1')
		ft_put_file_to_window(*vars, "imgs/wall.xpm", x, y);
	else if ((vars->file->str)[(vars->map_width * y) + x + y] == 'C')
	{
		ft_put_file_to_window(*vars, "imgs/item.xpm", x, y);
		vars->map_items++;
		(vars->file->visited)[(vars->map_width * y) + x + y] = 0;
	}
	else if ((vars->file->str)[(vars->map_width * y) + x + y] == 'P')
	{
		ft_put_file_to_window(*vars, "imgs/down.xpm", x, y);
		vars->x = x;
		vars->y = y;
	}
	else if ((vars->file->str)[(vars->map_width * y) + x + y] == 'E')
		ft_put_file_to_window(*vars, "imgs/exit.xpm", x, y);
	// printf("%d %c \n", (vars->file->str)[(vars->map_width * y) + x],
	// 	(vars->file->str)[(vars->map_width * y) + x + (y)]);
	x++;
}

void	parse_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map_height)
	{
		x = 0;
		while (x < vars->map_width)
		{
			ft_put_map_char(vars, x, y);
			x++;
		}
		y++;
	}
}
