/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:45:12 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/17 14:21:28 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool valid_start(t_map *map)
{
	int i;
	int j;
	int player_count;
	
	i = 0;
	j = 0;
	player_count = 0;
	while (map-> grid[i])
	{
		while (map-> grid[i][j])
		{
			if (map-> grid[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		ft_printf("Error! There is more than one player!\n");
		return (false);
	}
	return (true);
}

 bool valid_exit(t_map *map)
{
	int i;
	int j;
	int exit_count;
	
	i = 0;
	j = 0;
	exit_count = 0;
	while (map-> grid[i])
	{
		while (map-> grid[i][j])
		{
			if (map-> grid[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1)
	{
		ft_printf("Error! There is more than one exit!\n");
		return (false);
	}
	return (true);
}
bool valid_collectables(t_map *map)
{
	int i;
	int j;
	int collectable_count;
	
	i = 0;
	j = 0;
	collectable_count = 0;
	while (map-> grid[i])
	{
		while (map-> grid[i][j])
		{
			if (map-> grid[i][j] == 'E')
				collectable_count++;
			j++;
		}
		i++;
	}
	if (collectable_count == 0)
	{
		ft_printf("Error! There is no collectable!\n");
		return (false);
	}
	return (true);
}
bool valid_chars(t_map *map)
{
	int valid;

	valid = 0;
	valid += valid_start(map);
	valid += valid_exit(map);
	valid += valid_collectables(map);
	if (valid != 3)
		return (false);
	return (true);
}