/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:17:15 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/30 07:27:00 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_map *map)
{
	int	a;

	a = 50;
	map->img.empty = mlx_xpm_file_to_image(map->mlx, "sprites/ground.xpm", &a,
			&a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx, "sprites/wall.xpm", &a,
			&a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, "sprites/tempexit.xpm", &a,
			&a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"sprites/coin.xpm", &a, &a);
	file_to_image_player(map);
}

void	file_to_image_player(t_map *map)
{
	int	a;

	a = 50;
	map->img.player_right1 = mlx_xpm_file_to_image(map->mlx,
			"sprites/right1.xpm", &a, &a);
	map->img.player_right2 = mlx_xpm_file_to_image(map->mlx,
			"sprites/right2.xpm", &a, &a);
	map->img.player_up1 = mlx_xpm_file_to_image(map->mlx,
			"sprites/up1.xpm", &a, &a);
	map->img.player_up2 = mlx_xpm_file_to_image(map->mlx,
			"sprites/up2.xpm", &a, &a);
	map->img.player_down1 = mlx_xpm_file_to_image(map->mlx,
			"sprites/dwn1.xpm", &a, &a);
	map->img.player_down2 = mlx_xpm_file_to_image(map->mlx,
			"sprites/dwn2.xpm", &a, &a);
	map->img.player_left1 = mlx_xpm_file_to_image(map->mlx,
			"sprites/left1.xpm", &a, &a);
	map->img.player_left2 = mlx_xpm_file_to_image(map->mlx,
			"sprites/left2.xpm", &a, &a);
}
