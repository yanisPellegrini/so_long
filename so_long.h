/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:00:33 by ypellegr          #+#    #+#             */
/*   Updated: 2025/06/24 13:59:45 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_player
{
	int			y;
	int			x;

}				t_player;

typedef struct s_img
{
	void		*empty;
	void		*collectible;
	void		*wall;
	void		*exit;
	void		*player_left1;
	void		*player_right1;
	void		*player_up1;
	void		*player_down1;
	void		*player_left2;
	void		*player_right2;
	void		*player_up2;
	void		*player_down2;
	void		*enemy;
}				t_img;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;

}				t_map;


int				handle_keypress(int keycode, t_map *map);
void			find_player(t_map *map);
int				ft_close(t_map *map);
void			file_to_image(t_map *map);
int				flood_fill(char **map, int x, int y, int height);
int				find_path(t_map *map);
void			player_position(t_map *map);
int				find_path(t_map *map);
int				key_hook(int keycode, t_map *map);
void			player_position(t_map *map);
void			free_tab(char **tab);
int				open_map(char *filename);
int				check_map_characters(char character, t_map *map);
int				check_map_validity(t_map *map);
int				is_rectangular(t_map *map_info);
int				are_borders_walls(t_map *map_info);
int				check_map(t_map *map_info);
int				check_map_size(t_map *map);
int				error_map(t_map *map);
int				map_exe(char *filename, t_map *map);
int				ft_strcmp(const char *s1, const char *s2);

#endif
