/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:43:48 by root              #+#    #+#             */
/*   Updated: 2023/08/03 01:07:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_file_to_window(t_vars vars, char *file, int x, int y)
{
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, file, &vars.img.img_width,
		&vars.img.img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, x * 16, y * 16);
	mlx_destroy_image(vars.mlx, vars.img.img);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac > 1)
		vars.file = get_file(av[1]);
	else
		destroy_exit(0, "Error\nEnter a map\n");
	vars.map_width = -1;
	vars.map_height = 0;
	vars.collected_items = 0;
	vars.map_items = 0;
	vars.mlx = mlx_init();
	vars.win = 0;
	verif_map(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.map_width * 16, vars.map_height
		* 16, "so_long");
	parse_map(&vars);
	vars.move_counter = 0;
	mlx_hook(vars.win, 2, 1L << 0, keyboard, &vars);
	mlx_hook(vars.win, 17, 0, destroy_exit_event, &vars);
	mlx_hook(vars.win, 25, 1L << 18, resize, &vars);
	mlx_loop(vars.mlx);
}
