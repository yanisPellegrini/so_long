/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:15:06 by ypellegr          #+#    #+#             */
/*   Updated: 2025/04/18 08:41:05 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(int fd, char **buffer, int *bytes_read)
{
	char	temp[4096 + 1];
	char	*new_buffer;
	int		read_size;

	read_size = BUFFER_SIZE;
	if (BUFFER_SIZE > 4096)
		read_size = 4096;
	*bytes_read = read(fd, temp, read_size);
	if (*bytes_read <= 0)
		return (NULL);
	temp[*bytes_read] = '\0';
	new_buffer = ft_strjoin(*buffer, temp);
	free(*buffer);
	*buffer = new_buffer;
	return (new_buffer);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*new_buffer;
	int		i;

	i = ft_strchr_index(*buffer, '\n');
	if (i == -1)
		return (NULL);
	line = ft_substr(*buffer, 0, i + 1);
	if (!line)
		return (NULL);
	new_buffer = ft_substr(*buffer, i + 1, ft_strlen(*buffer) - i - 1);
	free(*buffer);
	*buffer = new_buffer;
	if (!*buffer)
		return (NULL);
	return (line);
}

char	*free_buffer(char **buffer, char *line)
{
	free(*buffer);
	*buffer = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	while (ft_strchr_index(buffer, '\n') == -1)
	{
		if (!read_line(fd, &buffer, &bytes_read))
		{
			if (bytes_read == 0 && *buffer != '\0')
			{
				line = ft_strdup(buffer);
				return (free_buffer(&buffer, line));
			}
			return (free_buffer(&buffer, NULL));
		}
	}
	line = extract_line(&buffer);
	return (line);
}
