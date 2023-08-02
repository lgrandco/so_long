/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:43:48 by root              #+#    #+#             */
/*   Updated: 2023/08/02 16:49:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	ft_put_file_to_window(t_vars vars, char *file, int x, int y)
{
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, file, &vars.img.img_width,
		&vars.img.img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, x * 16, y * 16);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac > 1)
		vars.file = get_file(av[1]);
	if (ac < 2 || !vars.file)
		return (1);
	vars.map_width = -1;
	vars.map_height = 0;
	vars.mlx = mlx_init();
	vars.collected_items = 0;
	vars.map_items = 0;
	if (verif_map(&vars) == -1)
		return (1);
	vars.win = mlx_new_window(vars.mlx, vars.map_width * 16, vars.map_height
		* 16, "");
	parse_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, keyboard, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse, &vars);
	mlx_hook(vars.win, 17, 0, destroy_exit, &vars);
	mlx_hook(vars.win, 25, 1L << 18, resize, &vars);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// &img.line_length,
	// 	&img.endian);
	// my_mlx_pixel_put(&img, 500, 500, 0x00FFFFFF);
	mlx_loop(vars.mlx);
}
