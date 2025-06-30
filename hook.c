/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:47:41 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/24 15:01:34 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_map *map)
{
	find_player(map);
	if (keycode == 53)
	{
		ft_close(map);
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
