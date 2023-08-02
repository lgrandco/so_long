/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:43:01 by root              #+#    #+#             */
/*   Updated: 2023/08/02 22:09:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	resize(t_vars *vars)
{
	(void)vars;
	return (0);
}

int	keyboard(int keycode, t_vars *vars)
{
	int	move_res;

	if (keycode == XK_Escape)
		destroy_exit(vars, "Escape key pressed\n");
	else if (keycode == 'w')
		move_res = move_up(vars);
	else if (keycode == 's')
		move_res = move_down(vars);
	else if (keycode == 'a')
		move_res = move_left(vars);
	else if (keycode == 'd')
		move_res = move_right(vars);
	if (move_res)
	{
		vars->move_counter++;
		printf("%d\n", vars->move_counter);
	}
	return (0);
}

int	destroy_exit(t_vars *vars, char *str)
{
	if (vars)
	{
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->file);
		free(vars->mlx);
	}
	while (*str)
		write(2, str++, 1);
	exit(0);
}
