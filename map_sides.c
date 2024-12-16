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

#include "so_long.h"

bool	calc_map_sides (t_map *map)
{
	int height;

	height = 0;
	while (map->grid[height])
		height++;
	map-> height = height;
	map->width = ft_strlen(map->grid[0]);
	if ()
}

bool	left_map_side (t_map *map)
{
	int	i;

	i = 0;
	while (map-> grid[i])
	{
		if (map-> grid[i][0] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool right_map_side (t_map *map)
{
	int	i;
	int height;

	height = 0;
	while (map->grid[height])
		height++;
	map-> width = ft_strlen(map-> grid[0]);
	map-> height = height;
	i = map-> height - 1;
	while (map-> grid[i][map-> width - 1])
	{
		if (map-> grid[i][map-> width - 1] != '1')
			return (false);
		i--;
	}
	return (true);
}

bool top_map_side (t_map *map)
{
	int	i;

	map-> width = ft_strlen(map-> grid[0]);
	i = 0;
	while (i < map-> width)
	{
		if (map-> grid[0][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool bottom_map_side (t_map *map)
{
	int	i;
	int height;

	height = 0;
	while (map->grid[height])
		height++;
	map-> width = ft_strlen(map-> grid[0]);
	map-> height = height;
	i = 0;
	while (i < map-> width)
	{
		if (map-> grid[map-> height - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}
