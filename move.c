/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:22 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/24 14:16:01 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_collectible(t_map *map, int x, int y, int time)
{
    if (map->array[y][x] == 'C')
    {
        map->array[y][x] = '0';
        map->c_check++;
    }

    if (map->array[y][x] == 'E' && map->c_check == map->c)
    {
        ft_putstr_fd("You win!\n", 1);
        exit(0);
    }
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y - 1;
	if (y > 0 && map->array[y][x] != '1')
	{
		check_collectible(map, x, y + 1, 13);
		if (map->array[y][x] == 'E' && map->c_check == map->c)
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * 50, y
			* 50);
		map->array[y + 1][x] = '0';
		print_moves(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up1, x * 50,
			y * 50);
		map->array[y][x] = 'P';
		map->player.y = y;
	}
}
void	move_down(t_map *map)
{
	int	x;
	int	new_y;
	int	y;

	x = map->player.x;
	y = map->player.y;
	new_y = map->player.y + 1;
	if (y > 0 && map->array[new_y][x] != '1')
	{
		check_collectible(map, x, new_y, 13);
		if (map->array[new_y][x] == 'E' && map->c_check == map->c)
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * 50, y
			* 50);
		map->array[y][x] = '0';
		print_moves(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x
			* 50, y * 50);
		map->array[new_y][x] = 'P';
		map->player.y = new_y;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;
	int	new_x;

	x = map->player.x;
	y = map->player.y;
	new_x = map->player.x + 1;
	if (y > 0 && map->array[y][new_x] != '1')
	{
		check_collectible(map, new_x, y, 13);
		if (map->array[y][new_x] == 'E' && map->c_check == map->c)
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * 50, y
			* 50);
		map->array[y][new_x] = '0';
		print_moves(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x
			* 50, y * 50);
		map->array[y][new_x] = 'P';
		map->player.x = new_x;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;
	int	new_x;

	x = map->player.x;
	y = map->player.y;
	new_x = map->player.x - 1;
	if (y > 0 && map->array[y][new_x] != '1')
	{
		check_collectible(map, new_x, y, 13);
		if (map->array[y][new_x] == 'E' && map->c_check == map->c)
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * 50, y
			* 50);
		map->array[y][new_x] = '0';
		print_moves(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x
			* 50, y * 50);
		map->array[y][new_x] = 'P';
		map->player.x = new_x;
	}
}
