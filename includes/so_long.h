/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:59:44 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/31 14:17:46 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>
#include "./MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"

#define TILE 50
#define UP 13
#define DOWN 1
#define LEFT 0
#define RIGHT 2
#define ESCAPE 53
#define WINDOW_NAME "so_long"


typedef struct s_texture
{
	mlx_texture_t	*background;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*collectable;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*collectable;
}	t_image;

typedef struct s_game
{
	mlx_t			*mlx;
	int				map_width;
	int				map_height;
	char			**map_grid;
	
	
	int				player_pos_x;
	int				player_pos_y;
	int				count_collectables;
	t_texture		*texture;
	t_image			*image;
}	t_game;

void	read_map(char *path, t_game *game);
// bool	left_map_side(t_map *map);
// bool	right_map_side(t_map *map);
// bool	top_map_side(t_map *map);
// bool	bottom_map_side(t_map *map);
// bool	valid_player(t_game *game);
// bool	valid_exit(t_game *game);
// bool	valid_collectable(t_game *game);
void	valid_map_name(char *path);
// void	valid_map_size(t_map *map);
// void	valid_map_sides(t_map *map);
// void	valid_chars(t_game *game);
// void	valid_accessibilty(t_game *game);
// void	cleanup_game(t_game *game);
// void	exit_game(void);
// void	delete_texture(t_texture *texture);
// void	render_map(t_game *game);
// void		keypress(int keycode, t_game *game);
// char	**duplicate_map(t_map *map);
// bool	is_accessible(t_map *map, char **map_copy);
// void	free_map(char **map_copy);