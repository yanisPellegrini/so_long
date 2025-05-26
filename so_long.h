/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:00:33 by ypellegr          #+#    #+#             */
/*   Updated: 2025/05/26 10:34:54 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		player_nb;
	int		exit_nb;
	int		collectible_nb;
	int		player_x;
	int		player_y;
}			t_map;

int			flood_fill(char **map, int x, int y, int height);
int			find_path(t_map *map);
void		player_position(t_map *map);
int			find_path(t_map *map);
void		player_position(t_map *map);
void		free_tab(char **tab);
int			open_map(char *filename);
int			check_map_characters(char character, t_map *map);
int			check_map_validity(t_map *map);
int			is_rectangular(t_map *map_info);
int			are_borders_walls(t_map *map_info);
int			check_map(t_map *map_info);
int			check_map_size(t_map *map);
int			error_map(t_map *map);
int			map_exe(char *filename, t_map *map);
int			ft_strcmp(const char *s1, const char *s2);

#endif
