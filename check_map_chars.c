/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:29:20 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/08 13:13:43 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool valid_end(t_game *game)
{
	int	y;
	int	x;
	int exit_count;
	
	y = 0;
	exit_count = 0;
	while (game->map_grid[y])
	{
		x = 0;
		while(game->map_grid[y][x])
		{
			if (game->map_grid[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	if (exit_count != 1)
		return (false);
	return (true);
}

static bool	valid_start(t_game *game)
{
	int	y;
	int	x;
	int	player_count;

	y = 0;
	player_count = 0;
	while (game->map_grid[y])
	{
		x = 0;
		while(game->map_grid[y][x])
		{
			if (game->map_grid[y][x] == 'P')
			{
				player_count++;
				game->player_pos_x = x;
				game->player_pos_y = y;
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (false);
	return (true);
}

static bool	valid_collectables(t_game *game)
{
	int	i;
	int	j;
	int	collect_count;

	i = 0;
	collect_count = 0;
	while (game->map_grid[i])
	{
		j = 0;
		while(game->map_grid[i][j])
		{
			if (game->map_grid[i][j] == 'C')
				collect_count++;
			j++;
		}
		i++;
	}
	if (collect_count < 1)
		return (false);
	game->collectables = collect_count;
	return (true);
}

bool	check_chars(t_game *game)
{
	char	c;
	int	y;
	int	x;

	y = 0;
	while (game->map_grid[y])
	{
		x = 0;
		while(game->map_grid[y][x])
		{
			c = game->map_grid[y][x];
			if (c != 'P' && c != 'E' && c != 'C' && c != '1' && c != '0')
				return (false);
			x++;
		}
		y++;
	}
	if (!valid_collectables(game) || !valid_end(game) || !valid_start(game))
		return (false);
	return (true);
}
