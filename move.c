/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:22 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/13 15:32:44 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int handle_keypress(int keycode, t_map *map)
{
    if (keycode == 53)
    {
        ft_putstr_fd("Exiting game...\n", 1);
        exit(0);
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

void player_position(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
    {
        while (map->player.x < map->x)
        {
            if (map->array[map->player.y][map->player.x] == 'P')
			{
				map->player.x = map->player.x;
				map->player.y = map->player.y;
				return;
			}
            {
                map->player_x = j;
                map->player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
    ft_putstr_fd("Error: Player position not found\n", 2);
    exit(EXIT_FAILURE);
}

int start_game(t_map *map)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "So Long");
    mlx_hook(win, 2, 1L << 0, handle_keypress, map);
    mlx_loop(mlx);
    return (0);
}

