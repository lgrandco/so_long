/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:56:42 by root              #+#    #+#             */
/*   Updated: 2023/08/03 19:12:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define SIZE 32768

# include "mlx.h"
# include "mlx_int.h"

typedef struct s_list
{
	char			str[SIZE];
	int				item_visited[SIZE];
	int				tile_visited[SIZE];
	int				len;
	struct s_list	*next;
	int				fd;
	int				read_ret;
}					t_list;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_data			img;
	int				parsing_x;
	int				parsing_y;
	int				player_pos_x;
	int				player_pos_y;
	t_list			*file;
	int				map_width;
	int				map_height;
	int				collected_items;
	int				map_items;
	int				map_exit;
	int				map_start;
	int				last_line_is_wall;
	int				screen_height;
	int				screen_width;
	int				move_counter;
	int				path_exit;
	int				path_items;
}					t_vars;

int					verif_move(int x, int y, t_vars *vars);
int					verif_map(t_vars *vars);
void				parse_map(t_vars *vars);
void				ft_put_file_to_window(t_vars vars, char *file, int x,
						int y);
int					move_up(t_vars *vars);
int					move_down(t_vars *vars);
int					move_left(t_vars *vars);
int					move_right(t_vars *vars);
t_list				*get_file(char *file);
int					keyboard(int keycode, t_vars *vars);
int					destroy_exit(t_vars *vars, char *str);
int					destroy_exit_event(t_vars *vars);
int					resize(t_vars *vars);
void				verif_path(t_vars *vars);
void				init_map(t_vars *vars);

#endif // !FT_H
