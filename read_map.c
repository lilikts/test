/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:11:13 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/17 09:56:49 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error! Wrong path!\n");
		exit(1);

	}
	return (fd);
}
char *read_lines(int fd)
{
	char	*line;
	char	*map_string = NULL;
	char	*temp;

	while (line = get_next_line(fd))
	{
		if (map_string == NULL)
			temp = ft_strdup(line);
		else
			temp = ft_strjoin(map_string, line);
		free(line);
		free(map_string);
		if (!temp)
		{
			close(fd);
			exit(1);
		}
		map_string = temp;
		if (!map_string)
		{
			close(fd);
			exit(1);
		}
	}
	return (map_string);
}

char	**read_map (char *path, t_map *map)
{
	int		fd;
	char	*map_string;

	fd = open_file(path);
	valid_map_name(fd);
	map_string = read_lines(fd);
	if (!map_string)
	{
		ft_printf("Error! Map is empty!\n");
		close(fd);
		return (NULL);
	}
	map->grid = ft_split(map_string, '\n');
	free (map_string);
	if(!map->grid)
	{
		ft_printf("Error! Map is empty!\n");
		close(fd);
		return (NULL);
	}
	close (fd);
	return (map->grid);
}