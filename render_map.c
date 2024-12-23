/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:01:35 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/23 18:40:20 by lkloters         ###   ########.fr       */
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
void load_images(t_image *image, t_texture *texture, mlx_t *mlx)
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
void render_texture(t_map *map, t_texture *texture, t_image *image, mlx_t mlx)
{
	int x;
    int y;
	mlx_image_t	*image;
	
    
    y = 0;

    while (y < map-> height)
    {
        x = 0;
		while (x < map-> width)
        {
            image = texture_to_image(&map->grid[y][x], image);
			if (img)
				mlx_image_to_window(mlx, image, 100, 100)
            x++;
        }
        y++;
    }
}

void render_map(t_game *game)
{
	load_texture(&game->texture);
	load_images(&game->image, &game->texture, &game->mlx);
	render_texture();
	delete_texture(&game->texture);
}