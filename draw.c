/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:42:49 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/13 13:36:49 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / 50][x / 50];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x,
			y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
}

void	map_printer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	file_to_image(map);
	while (y < map->y)
	{
		while (x < map->x)
		{
			map_type(map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	while (x <= map->x)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x * 50,
			map->y * 50);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x * 50,
			map->y * 50 + 50);
		x++;
	}
}
