/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:41:39 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/07 16:39:18 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_rectangular(t_game *game)
{
	size_t	i;

	i = 0;
	if(!game->map_grid || !game->map_grid[0])
		return (false);
	while (game->map_grid[i])
	{
		if (ft_strlen(game->map_grid[i]) != game->map_width)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_map_walls(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!game->map_grid || !game->map_grid[0])
		return (false);
	while (j < game->map_width)
	{
		if (game->map_grid[0][j] != '1' || game->map_grid[game->map_height - 1][j] != '1')
			return (false);
		j++;
	}
	i = 1;
	while (i < game->map_height - 1)
	{
		if (game->map_grid[i][0] != '1' || game->map_grid[i][game->map_width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool check_map_name(char *path)
{
	int	len;
	char	*valid_ending;
	
	valid_ending = ".ber";
	len = ft_strlen(path);
	if (!path || (len < 4) || (ft_strncmp(path + len - 4, valid_ending, 4)))
		return (false);
	return (true);
}

int validate_map(t_game *game)
{
	if (!is_rectangular(game))
		handle_error(-1, "Map is not rectangular!", game->map_grid, NULL);
	if (!check_map_walls(game))
		handle_error(-1, "Map is not surrounded by walls!", game->map_grid, NULL);
	if (!check_chars(game))
		handle_error(-1, "Invalid chars!", game->map_grid, NULL);
	if (!check_accessibilty(game))
		handle_error(-1, "Collectables/Exit not accessible!", game->map_grid, NULL);
	return (0);
}