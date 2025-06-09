/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_accessibilty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:40:40 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 20:59:57 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**duplicate_map(t_game *game)
{
	char	**map_copy;
	size_t	i;

	map_copy = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map_grid[i]);
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static bool	is_accessible(t_game *game, char **map_copy)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map_grid[y][x] == 'E' || game->map_grid[y][x] == 'C')
			{
				if (map_copy[y][x] != 'F')
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	check_accessibilty(t_game *game)
{
	char	**map_copy;
	bool	result;

	if (!game || !game->map_grid)
		return (false);
	map_copy = duplicate_map(game);
	if (!map_copy)
		return (false);
	flood_fill_target(map_copy, game->player_pos_x, game->player_pos_y, '1');
	result = is_accessible(game, map_copy);
	free_map_copy(map_copy, game->map_height);
	return (result);
}
