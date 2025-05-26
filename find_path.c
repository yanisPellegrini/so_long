/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:05:53 by ypellegr          #+#    #+#             */
/*   Updated: 2025/05/26 09:28:27 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int flood_fill(char **map, int x, int y, int height)
// {
// 	printf("x: %d, y: %d\n, height: %d, map[y]: %s,", x, y, height, map[y]);
//     if (x < 0 || y < 0 || y >= height || !map[y] || x >= (int)ft_strlen(map[y]))
//         return (0);
//     if (map[y][x] == 'E')
//         return (1);
//     if (map[y][x] == '1' || map[y][x] == 'V')
//         return (0);
//     map[y][x] = 'V';
//     if (flood_fill(map, x + 1, y, height) ||
//         flood_fill(map, x - 1, y, height) ||
//         flood_fill(map, x, y + 1, height) ||
//         flood_fill(map, x, y - 1, height))
//         return (1);
//     return (0);
// }

// void player_position(t_map *map)
// {
//     int i;
//     int j;

//     i = 0;
//     while (map->map[i])
//     {
//         j = 0;
//         while (map->map[i][j])
//         {
//             if (map->map[i][j] == 'P')
//             {
//                 map->player_x = j;
//                 map->player_y = i;
//                 return;
//             }
//             j++;
//         }
//         i++;
//     }
//     ft_putstr_fd("Error: Player position not found\n", 2);
//     exit(EXIT_FAILURE);
// }

// int	find_path(t_map *map)
// {
// 	char	**copy;
// 	int		i;

// 	copy = malloc(sizeof(char *) * (map->height + 1));
// 	if (!copy)
// 		return (-1);
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		copy[i] = ft_strdup(map->map[i]);
// 		if (!copy[i])
// 		{
// 			free_tab(copy);
// 			return (-1);
// 		}
// 		i += 1;
// 	}
// 	copy[i] = NULL;
// 	if (!flood_fill(copy, map->player_x, map->player_y, map->height))
// 	{
// 		ft_putstr_fd("Error: No path to exit\n", 2);
// 		free_tab(copy);
// 		return (-1);
// 	}
// 	free_tab(copy);
// 	return (0);
// }
