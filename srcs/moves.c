/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:04:45 by root              #+#    #+#             */
/*   Updated: 2023/08/02 16:58:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	move_up(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/up.xpm", vars->x, vars->y);
	if (verif_move(vars->x, vars->y - 1, vars) == -1)
		return ;
	vars->y--;
	ft_put_file_to_window(*vars, "imgs/up.xpm", vars->x, vars->y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->x, vars->y + 1);
}

void	move_down(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/down.xpm", vars->x, vars->y);
	if (verif_move(vars->x, vars->y + 1, vars) == -1)
		return ;
	vars->y++;
	ft_put_file_to_window(*vars, "imgs/down.xpm", vars->x, vars->y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->x, vars->y - 1);
}

void	move_left(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/left.xpm", vars->x, vars->y);
	if (verif_move(vars->x - 1, vars->y, vars) == -1)
		return ;
	vars->x--;
	ft_put_file_to_window(*vars, "imgs/left.xpm", vars->x, vars->y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->x + 1, vars->y);
}

void	move_right(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/right.xpm", vars->x, vars->y);
	if (verif_move(vars->x + 1, vars->y, vars) == -1)
		return ;
	vars->x++;
	ft_put_file_to_window(*vars, "imgs/right.xpm", vars->x, vars->y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->x - 1, vars->y);
}
