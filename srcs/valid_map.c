/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:30:02 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/31 16:13:43 by lkloters         ###   ########.fr       */
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

void	valid_map_size(t_game *game)
{
	int	i;

	i = 0;
	int str_length = ft_strlen(game->map_grid[i]);
	while (i < game->map_height)
	{
		if (str_length != game->map_width)
		{
			ft_printf("Error! Map sides are not the same length!\n");
			exit(1);
		}
		i++;
	}
}

void	valid_map_sides(t_game *game)
{
	int	valid;

	valid = left_map_side(game);
	valid += right_map_side(game);
	valid += top_map_side(game);
	valid += bottom_map_side(game);
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

	map_copy = duplicate_map(game);
	if (!map_copy)
	{
		ft_printf("Error! Failed to duplicate map!\n");
		exit(1);
	}
	flood_fill_target(map_copy, game->player_pos_x, game->player_pos_y, '1');
	if (is_accessible(game->map_grid, map_copy) != 1)
	{
		free_map(map_copy);
		ft_printf("Error! Exit/Collectables are not accessible!");
		exit(1);
	}
	free_map(map_copy);
}
