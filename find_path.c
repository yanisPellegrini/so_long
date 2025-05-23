/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:05:53 by ypellegr          #+#    #+#             */
/*   Updated: 2025/05/23 12:12:52 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood_fill(char **map, int x, int y, int height)
{
    if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]) || y >= height)
		return (0);

    if (map[x][y] == 'E')
        return (1);
    if (map[x][y] == '1' || map[x][y] == 'V')
        return (0);
    map[x][y] = 'V';
    if (flood_fill(map, x + 1, y, height) ||
        flood_fill(map, x - 1, y, height) ||
        flood_fill(map, x, y + 1, height) ||
        flood_fill(map, x, y - 1, height))
        return (1);
    return (0);
}

void player_position(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'P')
            {
                map->player_x = i;
                map->player_y = j;
                return;
            }
            j++;
        }
        i++;
    }
    ft_putstr_fd("Error: Player position not found\n", 2);
    exit(EXIT_FAILURE);
}

int	find_path(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (-1);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			free_tab(copy);
			return (-1);
		}
		i += 1;
	}
	copy[i] = NULL;
	if (!flood_fill(copy, map->player_x, map->player_y, map->height))
	{
		ft_putstr_fd("Error: No path to exit\n", 2);
		free_tab(copy);
		return (-1);
	}
	free_tab(copy);
	return (0);
}
