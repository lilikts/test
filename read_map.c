/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:11:13 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/16 17:24:43 by lkloters         ###   ########.fr       */
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
	char	*map = NULL;
	char	*temp;

	while (line = get_next_line(fd))
	{
		if (map == NULL)
			temp = ft_strdup(line);
		else
			temp = ft_strjoin(map, line);
		free(line);
		free(map);
		if (!temp)
		{
			close(fd);
			exit(1);
		}
		map = temp;
		if (!map)
		{
			close(fd);
			exit(1);
		}
	}
	return (map);
}
void	read_map (char *path)
{
	int		fd;
	char	*map;

	valid_map_name(fd);
	fd = open_file(path);
	map = read_lines(fd);
	close (fd);
}

void bsp ( t_map *map)
{
	map-> grid =ergebniss der map;
	
}