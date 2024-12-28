/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:01:35 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/28 15:53:41 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_texture(t_texture *texture)
{
    texture-> background = mlx_load_png("images/background.png");
    texture-> wall = mlx_load_png("images/wall.png");
    texture-> exit = mlx_load_png("images/exit.png");
    texture-> player = mlx_load_png("images/player.png");
    texture-> collectable = mlx_load_png("images/collectable.png");
}
void load_images(t_image *image, t_texture *texture, mlx)
{
    image-> background = mlx_texture_to_image(mlx, texture-> background);
    image-> wall = mlx_texture_to_image(mlx, texture-> wall);
    image-> exit = mlx_texture_to_image(mlx, texture-> exit);
    image-> player = mlx_texture_to_image(mlx, texture-> player);
    image-> collectable = mlx_texture_to_image(mlx, texture-> collectable);
}
mlx_image_t *texture_to_image(char character, t_image *image)
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
void render_image(t_game *game)
{
	int x;
    int y;
	mlx_image_t	*background;
	mlx_image_t	*loaded_image;
	
    y = 0;
    while (y < game->map-> height)
    {
        x = 0;
		while (x < game->map-> width)
        {
        	
			background = texture_to_image('0', game->image);
			if (!background || mlx_put_image_to_window(game->mlx, background, x * TILE_SIZE, y * TILE_SIZE) < 0)
			{
				ft_printf("Error! Rendering background failed\n");
				exit(1);
			}
			loaded_image = texture_to_image(game->map->grid[y][x], game->image);
			if (!loaded_image || (mlx_put_image_to_window(game->mlx, loaded_image, x * TILE_SIZE, y * TILE_SIZE) < 0))
			{
				ft_printf("Error! Rendering tile failed\n");
				exit(1);
			}
            x++;
        }
        y++;
    }
}

void render_map(t_game *game)
{
	load_texture(&game->texture);
	load_images(&game->image, &game->texture, &game->mlx);
	render_image(game);
	delete_images(&game->image);
	delete_texture(&game->texture);
}