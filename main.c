/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:02:00 by ypellegr          #+#    #+#             */
/*   Updated: 2025/05/27 13:30:51 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_map *map)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "So Long");
	mlx_loop(mlx);
	ft_putstr_fd("Starting the game...\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	map.map = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file.ber>\n", 2);
		return (-1);
	}
	if (map_exe(argv[1], &map) < 0)
		return (-1);
	if (check_map(&map) < 0)
	{
		free_tab(map.map);
		return (-1);
	}
	ft_putstr_fd("Map is valid!\n", 1);
	start_game(&map);
	free_tab(map.map);
	return (0);
}
