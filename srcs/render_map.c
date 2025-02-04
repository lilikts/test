/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:01:35 by lkloters          #+#    #+#             */
/*   Updated: 2025/02/04 18:16:51 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void    load_texture(t_texture *texture)
{
    texture-> background = mlx_load_png("./images/background.png");
    texture-> wall = mlx_load_png("./images/wall.png");
    texture-> exit = mlx_load_png("./images/exit.png");
    texture-> player = mlx_load_png("./images/player.png");
    texture-> collectable = mlx_load_png("./images/collectable.png");
}
static void load_images(t_game *game, t_texture *texture, t_image *image)
{
    image-> background = mlx_texture_to_image(game->mlx, texture->background);
    image-> wall = mlx_texture_to_image(game->mlx, texture->wall);
    image-> exit = mlx_texture_to_image(game->mlx, texture->exit);
    image-> player = mlx_texture_to_image(game->mlx, texture->player);
    image-> collectable = mlx_texture_to_image(game->mlx, texture->collectable);
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
static void render_tile(t_game *game, t_image *image, int x, int y)
{
	mlx_image_t	*background;
	mlx_image_t	*loaded_image;	
	background = texture_to_image('0', image);
	if (!background || mlx_image_to_window(game->mlx, background, x * TILE, y * TILE) < 0)
	{
		ft_printf("Error! Rendering background failed\n");
		exit(1);
	}
	loaded_image = texture_to_image(game->map_grid[y][x], image);
	if (!loaded_image || (mlx_image_to_window(game->mlx, loaded_image, x * TILE, y * TILE) < 0))
	{
		ft_printf("Error! Rendering tile failed\n");
		exit(1);
	}
}

void render_map(t_game *game, t_texture *texture, t_image *image)
{
	int x;
	int y;
	
	y = 0;	
	load_texture(texture);
	load_images(game, texture, image);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, image, x, y);
			x++;
		}
		y++;
	}
	//delete_texture(game->texture);
}
