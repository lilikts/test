/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:43:59 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 20:57:31 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_textures(t_game *game)
{
	mlx_delete_texture(game->texture->background);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->collectable);
	free(game->texture);
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->image->background);
	mlx_delete_image(game->mlx, game->image->wall);
	mlx_delete_image(game->mlx, game->image->exit);
	mlx_delete_image(game->mlx, game->image->player);
	mlx_delete_image(game->mlx, game->image->collectable);
	free(game->image);
}

void	load_texture(t_game *game)
{
	game->texture = malloc(sizeof(t_texture));
	if (!game->texture)
		close_game(game);
	game->texture->background = mlx_load_png("./images/background.png");
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->texture->exit = mlx_load_png("./images/exit.png");
	game->texture->player = mlx_load_png("./images/player.png");
	game->texture->collectable = mlx_load_png("./images/collectable.png");
	if (!game->texture->background || !game->texture->wall || \
		!game->texture->exit || !game->texture->player || \
		!game->texture->collectable)
		close_game(game);
}

void	load_images(t_game *game)
{
	game->image = malloc(sizeof(t_image));
	if (!game->image)
		close_game(game);
	game->image->background = mlx_texture_to_image(game->mlx, \
		game->texture->background);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->player = mlx_texture_to_image(game->mlx, \
		game->texture->player);
	game->image->collectable = mlx_texture_to_image(game->mlx, \
		game->texture->collectable);
	if (!game->image->background || !game->image->wall || !game->image->exit || \
		!game->image->player || !game->image->collectable)
		close_game(game);
	mlx_resize_image(game->image->background, TILE, TILE);
	mlx_resize_image(game->image->wall, TILE, TILE);
	mlx_resize_image(game->image->exit, TILE, TILE);
	mlx_resize_image(game->image->player, TILE, TILE);
	mlx_resize_image(game->image->collectable, TILE, TILE);
}
