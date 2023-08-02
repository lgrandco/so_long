/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:43:01 by root              #+#    #+#             */
/*   Updated: 2023/08/02 16:52:32 by root             ###   ########.fr       */
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
	if (keycode == XK_Escape)
		destroy_exit(vars);
	else if (keycode == 'w')
	{
		move_up(vars);
	}
	else if (keycode == 's')
	{
		move_down(vars);
	}
	else if (keycode == 'a')
	{
		move_left(vars);
	}
	else if (keycode == 'd')
	{
		move_right(vars);
	}
	return (0);
}

int	mouse(int keycode, t_vars *vars)
{
	(void)vars;
	printf("%d\n", keycode);
	return (0);
}

int	destroy_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
