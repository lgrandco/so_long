/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:04:45 by root              #+#    #+#             */
/*   Updated: 2023/08/02 21:25:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	move_up(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/up.xpm", vars->player_pos_x,
		vars->player_pos_y);
	if (verif_move(vars->player_pos_x, vars->player_pos_y - 1, vars) == -1)
		return (0);
	vars->player_pos_y--;
	ft_put_file_to_window(*vars, "imgs/up.xpm", vars->player_pos_x,
		vars->player_pos_y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->player_pos_x,
		vars->player_pos_y + 1);
	return (1);
}

int	move_down(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/down.xpm", vars->player_pos_x,
		vars->player_pos_y);
	if (verif_move(vars->player_pos_x, vars->player_pos_y + 1, vars) == -1)
		return (0);
	vars->player_pos_y++;
	ft_put_file_to_window(*vars, "imgs/down.xpm", vars->player_pos_x,
		vars->player_pos_y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->player_pos_x,
		vars->player_pos_y - 1);
	return (1);
}

int	move_left(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/left.xpm", vars->player_pos_x,
		vars->player_pos_y);
	if (verif_move(vars->player_pos_x - 1, vars->player_pos_y, vars) == -1)
		return (0);
	vars->player_pos_x--;
	ft_put_file_to_window(*vars, "imgs/left.xpm", vars->player_pos_x,
		vars->player_pos_y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->player_pos_x + 1,
		vars->player_pos_y);
	return (1);
}

int	move_right(t_vars *vars)
{
	ft_put_file_to_window(*vars, "imgs/right.xpm", vars->player_pos_x,
		vars->player_pos_y);
	if (verif_move(vars->player_pos_x + 1, vars->player_pos_y, vars) == -1)
		return (0);
	vars->player_pos_x++;
	ft_put_file_to_window(*vars, "imgs/right.xpm", vars->player_pos_x,
		vars->player_pos_y);
	ft_put_file_to_window(*vars, "imgs/background.xpm", vars->player_pos_x - 1,
		vars->player_pos_y);
	return (1);
}
