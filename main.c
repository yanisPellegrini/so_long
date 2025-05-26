/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:02:00 by ypellegr          #+#    #+#             */
/*   Updated: 2025/05/26 11:01:18 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_map map;

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
	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "So Long");
	mlx_loop(mlx);
	free_tab(map.map);
	return (0);
}