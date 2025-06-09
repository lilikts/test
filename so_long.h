/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:48:57 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 21:30:28 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE 50
# define WINDOW_NAME "so_long"

typedef struct s_image
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*collectable;
}	t_image;

typedef struct s_texture
{
	mlx_texture_t	*background;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*collectable;
}	t_texture;

typedef struct s_game
{
	char		**map_grid;
	size_t		map_height;
	size_t		map_width;
	int			collectables;
	int			player_pos_x;
	int			player_pos_y;
	int			move_count;
	mlx_t		*mlx;
	t_texture	*texture;
	t_image		*image;
}	t_game;

void	create_map(char *path, t_game *game);
void	render_map(t_game *game);
void	create_game(t_game *game);
void	keypress(mlx_key_data_t keycode, void *param);
void	delete_textures(t_game *game);
void	delete_images(t_game *game);
void	free_split(char **array);
void	handle_error(int fd, char *msg, void *ptr1);
void	free_map_copy(char **map_copy, int height);
bool	check_map_name(char *path);
int		validate_map(t_game *game);
bool	check_chars(t_game *game);
bool	check_accessibilty(t_game *game);
void	init_game_values(t_game *game);
void	map_size(t_game *game);
void	close_game(void *param);
void	load_texture(t_game *game);
void	load_images(t_game *game);
bool	has_double_newline(char *map_string);
#endif
