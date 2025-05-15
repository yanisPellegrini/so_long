/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:58:33 by ypellegr          #+#    #+#             */
/*   Updated: 2025/05/15 12:02:03 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_map(char *filename)
{
	int fd;
	char *extension;

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

int read_map(int fd, char **map)
{
	int i;
	char *line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	if (close(fd) < 0)
	{
		perror("Error closing file");
		return (-1);
	}
	return (1);
}

int check_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P')
			{
				free_tab(map);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}