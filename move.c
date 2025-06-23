/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:22 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/23 14:45:44 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_map *map)
{
	find_player(map);
	if (keycode == 53)
	{
		ft_putstr_fd("Exiting game...\n", 1);
		exit(0); // need to do a function for this
	}
	else if (keycode == 13)
		ft_putstr_fd("Move up\n", 1);
	else if (keycode == 0)
		ft_putstr_fd("Move left\n", 1);
	else if (keycode == 1)
		ft_putstr_fd("Move down\n", 1);
	else if (keycode == 2)
		ft_putstr_fd("Move right\n", 1);
	return (0);
}

void	find_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				return ;
			map->player.x++;
		}
		map->player.x = 0;
		map->player.y++;
	}
	ft_putstr_fd("Error: Player position not found\n", 2);
	exit(EXIT_FAILURE);
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y - 1;
	if (y > 0 && map->array[y][x] != '1')
	{
		change_player_coord(map, x, y + 1, 13);
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
		change_player_coord(map, x, y, 13);
		if (map->array[new_y][x] == 'E' && map->c_check == map->c)
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * 50, y
			* 50);
		map->array[y][x] = '0';
		print_moves(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x * 50,
			y * 50);
		map->array[new_y][x] = 'P';
		map->player.y = new_y;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;
	int new_x;

	x = map->player.x;
	y = map->player.y;
	new_x = map->player.x + 1;
	if (y > 0 && map->array[y][new_x] != '1')
	{
		change_player_coord(map, x, y, 13);
		if (map->array[y][new_x] == 'E' && map->c_check == map->c)
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x * 50, y
			* 50);
		map->array[y][new_x] = '0';
		print_moves(map);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down1, x * 50,
			y * 50);
		map->array[y][new_x] = 'P';
		map->player.x = new_x;
	}
}

}
