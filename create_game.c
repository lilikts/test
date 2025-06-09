/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:36:24 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 18:05:19 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    load_texture(t_game *game)
{
	game->texture = malloc(sizeof(t_texture));
	if (!game->texture)
		close_game(game);
	game->texture->background = mlx_load_png("./images/background.png");
    game->texture->wall = mlx_load_png("./images/wall.png");
    game->texture->exit = mlx_load_png("./images/exit.png");
    game->texture->player = mlx_load_png("./images/player.png");
    game->texture->collectable = mlx_load_png("./images/collectable.png");
	if(!game->texture->background || !game->texture->wall || !game->texture->exit ||
		!game->texture->player || !game->texture->collectable )
		close_game(game);
}

static void load_images(t_game *game)
{
	game->image = malloc(sizeof(t_image));
	if (!game->image)
		close_game(game);
    game->image->background = mlx_texture_to_image(game->mlx, game->texture->background);
    game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
    game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
    game->image->player = mlx_texture_to_image(game->mlx, game->texture->player);
    game->image->collectable = mlx_texture_to_image(game->mlx, game->texture->collectable);
	if(!game->image->background || !game->image->wall || !game->image->exit ||
		!game->image->player || !game->image->collectable )
		close_game(game);
	mlx_resize_image(game->image->background, TILE, TILE);
	mlx_resize_image(game->image->wall, TILE, TILE);
	mlx_resize_image(game->image->exit, TILE, TILE);
	mlx_resize_image(game->image->player, TILE, TILE);
	mlx_resize_image(game->image->collectable, TILE, TILE);
}

static mlx_image_t *texture_to_image(char character, t_image *image)
{
	if (character == '0')
		return (image->background);
	else if (character == '1')
		return (image->wall);
	else if (character == 'E')
		return (image->exit);
	else if (character == 'P')
		return (image->player);
	else if (character == 'C')
		return (image->collectable);
	return (NULL);
}
static void render_tile(t_game *game ,int x, int y)
{
	mlx_image_t	*background;
	mlx_image_t	*loaded_image;	
	background = texture_to_image('0', game->image);
	if (!background)
		close_game(game);
	mlx_image_to_window(game->mlx, background, x * TILE, y * TILE);
	loaded_image = texture_to_image(game->map_grid[y][x], game->image);
	if (!loaded_image || (mlx_image_to_window(game->mlx, loaded_image, x * TILE, y * TILE) < 0))
		close_game(game);
}

void render_map(t_game *game)
{
	size_t x;
	size_t y;
	
	y = 0;	
	while (game->map_grid[y] != NULL)
	{
		x = 0;
		while (game->map_grid[y][x] != '\0')
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
void create_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width * TILE, game->map_height * TILE, WINDOW_NAME, false);
	if (!game->mlx)
		close_game(game);
	load_texture(game);
	load_images(game);
	delete_textures(game);
	render_map(game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_key_hook(game->mlx, keypress, game);
	mlx_loop(game->mlx);
}
