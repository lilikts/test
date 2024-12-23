/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:59:44 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/23 18:31:03 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>


typedef struct s_map
{
	char **grid;
	int width;
	int height;
} t_map;

typedef struct s_texture
{
    mlx_texture_t   *background;
    mlx_texture_t   *wall;
    mlx_texture_t   *exit;
    mlx_texture_t   *player;
    mlx_texture_t   *collectable;
} t_texture;

typedef struct s_image
{
    mlx_image_t *background;
    mlx_image_t *wall;
    mlx_image_t *exit;
    mlx_image_t *player;
    mlx_image_t *collectable;
} t_image;
typedef struct s_game
{
    int player_pos_x;
    int player_pos_y;
	t_map *map;
    t_texture *texture;
    t_image *image;
    mlx_t *mlx;
} t_game;

bool	calc_map_sides (t_map *map);