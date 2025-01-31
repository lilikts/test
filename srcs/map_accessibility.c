/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:56:25 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/31 16:08:00 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**duplicate_map(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc (sizeof(char *) * game->map_height + 1);
	if (!map_copy)
		return (NULL);
	while (i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map_grid[i]);
		if (!map_copy[i])
		{
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	free_map(char **map_copy)
{
	int	i;

	i = 0;
	if (!map_copy)
		return ;
	while (map_copy[i] != NULL)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

bool	is_accessible(t_game *game, char **map_copy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_height)
	{
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
