/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:47:56 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 19:53:16 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(-1, "Wrong path!", NULL, NULL);
	return (fd);
}

static char	*read_lines(int fd)
{
	char	*line = NULL;
	char	*map_string;
	char	*temp;

	map_string = ft_strdup("");
	if (!map_string)
	{
		close(fd);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(map_string, line);
		free(line);
		free(map_string);
		if (!temp)
		{
			close(fd);
			return (NULL);
		}
		map_string = temp;
		line = get_next_line(fd);
	}
	return (map_string);
}

void	read_map(char *path, t_game *game)
{
	int		fd;
	char	*map_string;
	
	if (!check_map_name(path))
		handle_error(-1, "Invalid Map Name!", NULL, NULL);
	fd = open_file(path);
	map_string = read_lines(fd);
	if (!map_string || map_string[0] == '\0')
		handle_error(fd, "Empty map!", map_string, NULL);
	game->map_grid = ft_split(map_string, '\n');
	free(map_string);
	if (!game->map_grid)
		handle_error(fd, "Empty map!", NULL, NULL);
	close(fd);
}

void	create_map(char *path, t_game *game)
{
	init_game_values(game);
	read_map(path, game);
	map_size(game);
	if (validate_map(game))
		handle_error(-1, "Map is not valid!", game->map_grid, NULL);
}
