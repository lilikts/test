/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:11:13 by lkloters          #+#    #+#             */
/*   Updated: 2025/02/03 18:13:06 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_old.h"

static	int	open_file(char *path)
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

static char	*read_lines(int fd)
{
	char	*line = NULL;
	char	*map_string = NULL;
	char	*temp;

	map_string = ft_strdup("");
	if (!map_string)
	{
		close(fd);
		exit(1);
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
			exit(1);
		}
		map_string = temp;
		line = get_next_line(fd);
	}
	return (map_string);
}

static void	map_size(t_game *game)
{
	int	height;

	height = 0;
	while (game->map_grid[height])
		height++;
	game->map_height = height;
	game-> map_width = ft_strlen(game->map_grid[0]);
}

void	read_map(char *path, t_game *game)
{
	int		fd;
	char	*map_string;

	fd = open_file(path);
	// valid_map_name(path);
	map_string = read_lines(fd);
	if (!map_string)
	{
		ft_printf("Error! Map is empty!\n");
		free(map_string);
		exit(1);
	}
	game->map_grid = ft_split(map_string, '\n');
	free (map_string);
	if (!game->map_grid)
	{
		ft_printf("Error! Map is empty!\n");
		close(fd);
		return ;
	}
	close(fd);
	map_size(game);
}
