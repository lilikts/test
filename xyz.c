#include "so_long.h"

void    load_texture(t_texture *texture, mlx_t)
{
    texture-> background = mlx_load_png("images/background.png");
    texture-> wall = mlx_load_png("images/wall.png");
    texture-> exit = mlx_load_png("images/exit.png");
    texture-> player = mlx_load_png("images/player.png");
    texture-> collectable = mlx_load_png("images/collectable.png");
}
void texture_to_image(t_image *image, t_texture *texture, mlx_t)
{
    image-> background = mlx_texture_to_image(mlx, texture-> background);
    image-> wall = mlx_texture_to_image(mlx, texture-> wall);
    image-> exit = mlx_texture_to_image(mlx, texture-> exit);
    image-> player = mlx_texture_to_image(mlx, texture-> player);
    image-> collectable = mlx_texture_to_image(mlx, texture-> collectable);
}