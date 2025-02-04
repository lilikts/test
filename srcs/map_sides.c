/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sides.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:58:54 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/16 17:41:16 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	left_map_side(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_grid[i] && i < game->map_height)
	{
		if (game->map_grid[i][0] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	right_map_side(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_grid[i] && i < game->map_height)
	{
		if (game-> map_grid[i][game->map_width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	top_map_side(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_grid[0] && i < game->map_width)
	{
		if (game-> map_grid[0][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	bottom_map_side(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_grid[game->map_height] && i < game->map_width)
	{
		if (game->map_grid[game->map_height - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}
