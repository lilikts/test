/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:12:08 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 20:58:11 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		if (map_copy[i])
			free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

void	handle_error(int fd, char *msg, void *ptr1)
{
	if (fd >= 0)
		close(fd);
	if (ptr1)
		free(ptr1);
	ft_printf("Error! %s\n", msg);
	exit(1);
}

void	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	delete_images(game);
	mlx_close_window(game->mlx);
	free_map_copy(game->map_grid, game->map_height);
	free(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
