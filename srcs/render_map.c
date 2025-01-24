/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:01:35 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/24 15:54:55 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void    load_texture(t_texture *texture)
{
    texture-> background = mlx_load_png("images/background.png");
    texture-> wall = mlx_load_png("images/wall.png");
    texture-> exit = mlx_load_png("images/exit.png");
    texture-> player = mlx_load_png("images/player.png");
    texture-> collectable = mlx_load_png("images/collectable.png");
}
static void load_images(t_game *game)
{
    game->image-> background = mlx_texture_to_image(game->mlx, game->texture-> background);
    game->image-> wall = mlx_texture_to_image(game->mlx, game->texture-> wall);
    game->image-> exit = mlx_texture_to_image(game->mlx, game->texture-> exit);
    game->image-> player = mlx_texture_to_image(game->mlx, game->texture-> player);
    game->image-> collectable = mlx_texture_to_image(game->mlx, game->texture-> collectable);
}
static mlx_image_t *texture_to_image(char character, t_image *image)
{
	if (character == '0')
		return (image-> background);
	else if (character == '1')
		return (image-> wall);
	else if (character == 'E')
		return (image-> exit);
	else if (character == 'P')
		return (image-> player);
	else if (character == 'C')
		return (image-> collectable);
	return (NULL);
}
static void render_tile(t_game *game, int x, int y)
{
	mlx_image_t	*background;
	mlx_image_t	*loaded_image;	
	background = texture_to_image('0', game->image);
	if (!background || mlx_image_to_window(game->mlx, background, x * TILE, y * TILE) < 0)
	{
		ft_printf("Error! Rendering background failed\n");
		exit(1);
	}
	loaded_image = texture_to_image(game->map->grid[y][x], game->image);
	if (!loaded_image || (mlx_image_to_window(game->mlx, loaded_image, x * TILE, y * TILE) < 0))
	{
		ft_printf("Error! Rendering tile failed\n");
		exit(1);
	}
}

void render_map(t_game *game)
{
	int x;
	int y;
	
	y = 0;	
	load_texture(game->texture);
	load_images(game);
	while (y < game->map-> height)
	{
		x = 0;
		while (x < game->map-> width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	delete_texture(game->texture);
}
