/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:49:50 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/13 10:37:46 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(t_map *map)
{
	int					x;
	int					y;
	long unsigned int	old_x;

	x = 0;
	y = 0;
	x = ft_strlen(map->map[y]);
	old_x = x;
	while (map->map[y])
	{
		if (ft_strlen(map->map[y]) != old_x)
		{
			ft_putstr_fd("Error: Map is not rectangular\n", 2);
			return (-1);
		}
		y++;
	}
	if (x < 3 || y < 3)
	{
		ft_putstr_fd("Error: Map size is too small\n", 2);
		return (-1);
	}
	map->width = x;
	map->height = y;
	return (0);
}

int	error_map(t_map *map)
{
	if (!are_borders_walls(map))
	{
		ft_putstr_fd("Error: Map borders are not surrounded by walls\n", 2);
		free_tab(map->map);
		return (-1);
	}
	// if (find_path(map) < 0)
	// {
	// 	ft_putstr_fd("Error: Invalid map size\n", 2);
	// 	free_tab(map->map);
	// 	return (-1);
	// }
	return (0);
}

int	map_exe(char *filename, t_map *map)
{
	int		fd;
	int		bytes_read;
	char	buffer[4096];

	fd = open_map(filename);
	if (fd < 0)
		return (-1);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read < 0)
	{
		perror("Error reading file");
		close(fd);
		return (-1);
	}
	buffer[bytes_read] = '\0';
	map->map = ft_split(buffer, '\n');
	if (!map->map)
	{
		ft_putstr_fd("Error: Failed to split map\n", 2);
		close(fd);
		return (-1);
	}
	if (check_map_size(map) < 0)
	{
		free_tab(map->map);
		close(fd);
		return (-1);
	}
	return (0);
}
