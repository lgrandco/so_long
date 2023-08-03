/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:11:17 by root              #+#    #+#             */
/*   Updated: 2023/08/03 19:11:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_map(t_vars *vars)
{
	vars->parsing_x = 0;
	vars->parsing_y = 0;
	vars->map_exit = 0;
	vars->map_start = 0;
}
