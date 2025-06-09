/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:50:21 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 21:42:59 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_values(t_game *game)
{
	game->map_grid = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->collectables = 0;
	game->move_count = 0;
	game->mlx = NULL;
}

void	map_size(t_game *game)
{
	int	height;

	height = 0;
	while (game->map_grid[height])
		height++;
	game->map_height = height;
	game->map_width = ft_strlen(game->map_grid[0]);
}

bool	has_double_newline(char *map_string)
{
	if (!map_string)
		return (false);
	if (map_string[0] == '\n')
		return (true);
	while (*map_string)
	{
		if (*map_string == '\n' && *(map_string + 1) == '\n')
			return (true);
		map_string++;
	}
	return (false);
}
