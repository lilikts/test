/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:13:33 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/24 15:54:55 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	valid_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map-> height)
	{
		x = 0;
		while (x < game->map-> width)
		{
			if (game->map-> grid[y][x] == 'P')
			{
				game-> player_pos_x = x;
				game-> player_pos_y = y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

bool	valid_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map-> height)
	{
		x = 0;
		while (x < game->map-> width)
		{
			if (game->map-> grid[y][x] == 'E')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

bool	valid_collectable(t_game *game)
{
	int	x;
	int	y;
	int	num_collectables;

	y = 0;
	num_collectables = 0;
	while (y < game->map-> height)
	{
		x = 0;
		while (x < game->map-> width)
		{
			if (game->map-> grid[y][x] == 'C')
				num_collectables += 1;
			x++;
		}
		y++;
	}
	if (num_collectables < 1)
		return (false);
	game->count_collectables = num_collectables;
	return (true);	
}
