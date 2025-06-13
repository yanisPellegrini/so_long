/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:02:00 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/13 15:16:27 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_initializer(t_map *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file.ber>\n", 2);
		return (-1);
	}
	map_initializer(&map, argv);
	map_checker(&map, argv[1]); // todo
	map.mlx = mlx_init();
	map.wnd = mlx_new_window(map.mlx,800 ,600, "So Long"); // map.x * 50, map.y * 50
	file_to_image(&map);
	draw_map(&map);
	mlx_hook(map.wnd, 17, 0, ft_close, &map);
	mlx_key_hook(map.wnd, key_hook, &map);
	return (0);
}
