/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:36:24 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 20:53:56 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*texture_to_image(char character, t_image *image)
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

static void	render_tile(t_game *game, int x, int y)
{
	mlx_image_t	*background;
	mlx_image_t	*loaded_image;

	background = texture_to_image('0', game->image);
	if (!background)
		close_game(game);
	mlx_image_to_window(game->mlx, background, x * TILE, y * TILE);
	loaded_image = texture_to_image(game->map_grid[y][x], game->image);
	if (!loaded_image || \
		(mlx_image_to_window(game->mlx, loaded_image, x * TILE, y * TILE) < 0))
		close_game(game);
}

void	render_map(t_game *game)
{
	size_t	x;
	size_t	y;

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

void	create_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width * TILE, \
		game->map_height * TILE, WINDOW_NAME, false);
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
