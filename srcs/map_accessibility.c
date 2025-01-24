/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:56:25 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/24 15:54:55 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**duplicate_map(t_map *map)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc (sizeof(char *) * map->height + 1);
	if (!map_copy)
		return (NULL);
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->grid[i]);
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

bool	is_accessible(t_map *map, char **map_copy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'E' || map->grid[y][x] == 'C')
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
