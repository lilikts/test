/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:30:02 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/24 15:54:55 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	valid_map_name(char *path)
{
	int		len;
	char	*valid_ending;

	valid_ending = ".ber";
	len = ft_strlen(path);
	if (!path || (len < 4) || (ft_strncmp(path + len - 4, valid_ending, 4)))
	{
		ft_printf("Error! Invalid map name!\n");
		exit(1);
	}
}

void	valid_map_size(t_map *map)
{
	int	i;

	i = 0;
	int str_length = ft_strlen(map->grid[i]);
	while (i < map-> height)
	{
		if (str_length != map->width)
		{
			ft_printf("Error! Map sides are not the same length!\n");
			exit(1);
		}
		i++;
	}
}

void	valid_map_sides(t_map *map)
{
	int	valid;

	valid = left_map_side(map);
	valid += right_map_side(map);
	valid += top_map_side(map);
	valid += bottom_map_side(map);
	if (valid != 4)
	{
		ft_printf("Error! Map sides contain invalid characters!\n");
		exit(1);
	}
}

void	valid_chars(t_game *game)
{
	int	valid;

	valid = 0;
	valid = valid_player(game);
	valid += valid_exit(game);
	valid += valid_collectable(game);
	if (valid != 3)
	{
		ft_printf("Error! Map contains invalid charachters!\n");
		exit(1);
	}
}

void	valid_accessibilty(t_game *game)
{
	char	**map_copy;

	map_copy = duplicate_map(game->map);
	if (!map_copy)
	{
		ft_printf("Error! Failed to duplicate map!\n");
		exit(1);
	}
	flood_fill_target(map_copy, game->player_pos_x, game->player_pos_y, '1');
	if (is_accessible(game->map, map_copy) != 1)
	{
		free_map(map_copy);
		ft_printf("Error! Exit/Collectables are not accessible!");
		exit(1);
	}
	free_map(map_copy);
}
