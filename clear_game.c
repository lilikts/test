/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:12:08 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 19:57:22 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_split(char **array)
{
	int i = 0;

	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map_copy(char ** map_copy, int height)
{
	int i;
	
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

void handle_error(int fd, char *msg, void *ptr1, void *ptr2)
{
	if (fd >= 0)
		close(fd);
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	ft_printf("Error! %s\n", msg);
	exit(1);
}

void delete_textures(t_game *game)
{
	mlx_delete_texture(game->texture->background);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->collectable);
	free(game->texture);
}

void delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->image->background);
	mlx_delete_image(game->mlx, game->image->wall);
	mlx_delete_image(game->mlx, game->image->exit);
	mlx_delete_image(game->mlx, game->image->player);
	mlx_delete_image(game->mlx, game->image->collectable);
	free(game->image);
}

void close_game(void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	delete_images(game);
	mlx_close_window(game->mlx);
	free_map_copy(game->map_grid, game->map_height);
	free(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}