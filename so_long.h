/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:59:44 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/28 15:47:09 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>
#include <mlx.h>

#define TILE_SIZE 50
#define UP 13
#define DOWN 1
#define LEFT 0
#define RIGHT 2
#define ESCAPE 53
#define WINDOW_NAME "so_long"

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
	int count_collectables;
	void *window;
	t_map *map;
    t_texture *texture;
    t_image *image;
    void *mlx;
} t_game;

char	**read_map (char *path, t_map *map);
void map_size(t_map *map);
bool	left_map_side (t_map *map);
bool right_map_side (t_map *map);
bool top_map_side (t_map *map);
bool bottom_map_side (t_map *map);
bool    valid_player(t_game *game);
bool    valid_exit(t_game *game);
bool    valid_collectable(t_game *game);
void	valid_map_name(char *path);
void	valid_map_size(t_map *map);
void valid_map_sides (t_map *map);
void    valid_chars(t_map *map);
void	valid_accessibilty(t_game *game);

bool	calc_map_sides (t_map *map);
int keypress(int keycode, t_game *game);
