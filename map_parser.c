/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:58:33 by ypellegr          #+#    #+#             */
/*   Updated: 2025/05/21 11:26:51 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//map is rectangular
int	open_map(char *filename)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".ber") != 0)
	{
		ft_putstr_fd("Error: Invalid file extension\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

int	check_map_characters(char character, t_map *map)
{
	if (character == 'P')
	{
		map->player_nb++;
	}
	else if (character == 'E')
	{
		map->exit_nb++;
	}
	else if (character == 'C')
	{
		map->collectible_nb++;
	}
	return (0);
}

int	check_map_validity(t_map *map)
{
	if (map->player_nb != 1)
	{
		ft_putstr_fd("Error: Invalid number of players\n", 2);
		return (-1);
	}
	if (map->exit_nb != 1)
	{
		ft_putstr_fd("Error: Invalid number of exits\n", 2);
		return (-1);
	}
	if (map->collectible_nb < 1)
	{
		ft_putstr_fd("Error: Invalid number of collectibles\n", 2);
		return (-1);
	}
	if (error_map(map) < 0)
		return (-1);
	return (0);
}

int	are_borders_walls(t_map *map_info)
{
	int	i;
	int	j;
	int	width;
	int	height;

	height = 0;
	while (map_info->map[height])
		height++;
	width = ft_strlen(map_info->map[0]);
	for (j = 0; j < width; j++)
	{
		if (map_info->map[0][j] != '1' || map_info->map[height - 1][j] != '1')
			return (-1);
	}
	for (i = 0; i < height; i++)
	{
		if (map_info->map[i][0] != '1' || map_info->map[i][width - 1] != '1')
			return (-1);
	}
	return (1);
}

int	check_map(t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] != '1' && map_info->map[i][j] != '0'
				&& map_info->map[i][j] != 'C' && map_info->map[i][j] != 'E'
				&& map_info->map[i][j] != 'P')
			{
				ft_putstr_fd("Error: Invalid character in map\n", 2);
				free_tab(map_info->map);
				return (-1);
			}
			check_map_characters(map_info->map[i][j], map_info);
			j++;
		}
		i++;
	}
	return (check_map_validity(map_info));
}
