#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "./MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"

#define TILE 50
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
	int	map_height;
	int map_width;
	char **	map_grid;
	int	player_pos_x;
	int player_pos_y;
	int	count_collectables;
	mlx_t *mlx;
}	t_game;

int	open_file(char *path);
char	*read_lines(int fd);
void	read_map(char *path, t_game *game);
void	valid_map_name(char *path);
void	valid_map_size(t_game *game);
void	valid_map_sides(t_game *game);
bool	left_map_side(t_game *game);
bool	right_map_side(t_game *game);
bool	top_map_side(t_game *game);
bool	bottom_map_side(t_game *game);
bool	valid_player(t_game *game);
bool	valid_exit(t_game *game);
bool	valid_collectable(t_game *game);
void	valid_chars(t_game *game);
char	**duplicate_map(t_game *game);
bool	is_accessible(t_game *game, char **map_copy);
void	valid_accessibilty(t_game *game);
void render_map(t_game *game, t_texture *texture, t_image *image);
