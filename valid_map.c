/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:30:02 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/23 18:00:23 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map_name(char *path)
{
	int		i;
	int		j;
	int		length;
	char	*valid_ending;
	
	valid_ending = ".ber";
	length = ft_strlen(path);
	if (!path || (length < 4))
	{
		ft_printf("Error! Invalid map name!\n");
		exit(1);
	}
	i = length - 4;
	j = 0;
	while (path[i] == valid_ending[j])
	{
		i++;
		j++;
	}
	if (path[i] != valid_ending[j])
	{
		ft_printf("Error! Invalid map name!\n");
		exit(1);
	}
}
bool	valid_map_sides (t_map *map)
{
	int height;
	int i;

	i = 0;
	height = 0;
	while (map->grid[height])
		height++;
	map-> height = height;
	while (i < map-> height)
	{
		if (ft_strlen(map-> grid[i]) != ft_strlen(map-> grid[0]))
		{
			ft_printf("Error! Map sides are not the same length!\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool    valid_chars(t_map *map)
{
    int valid;

    valid = 0;
    valid = valid_start(map);
    valid += valid_exit(map);
    valid += valid_collectables(map);
    if (valid != 3)
    {
        ft_printf("Error! Map contains invalid charachters!\n");
        return (false);
    }
    return (true);
}
 bool    valid_player(t_map *map, t_game *game)
{
    int x;
    int y;

    y = 0;

    while (y < map-> height)
    {
        x = 0;
		while (x < map-> width)
        {
            if (map-> grid[y][x] == 'P')
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
bool    valid_collectable(t_map *map, t_game *game)
{
	int x;
    int y;
	int num_collectables;

    y = 0;
	num_collectables = 0;

    while (y < map-> height)
    {
        x = 0;
		while (x < map-> width)
        {
            if (map-> grid[y][x] == 'C')
                num_collectables += 1;
            x++;
        }
        y++;
    }
	if (num_collectables < 1)
    	return (false);
	return (true);	
}