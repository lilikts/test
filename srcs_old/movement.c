/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:19:58 by lkloters          #+#    #+#             */
/*   Updated: 2025/02/03 18:11:20 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_old.h"

static void	player_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map->grid[y - 1][x] != '1')
	{
		if (game->map->grid[y - 1][x] == 'E' && (game->count_collectables == 0))
			return ;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		game->map->grid[y][x] = '0';
		y--;
		if (game->map->grid[y][x] == 'C')
			game->count_collectables--;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		mlx_image_to_window(game->mlx, game->image->player, x * TILE, y * TILE);
	}
	game->player_pos_y = y;
	game->map->grid[y][x] = 'P';
}

static void	player_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map->grid[y + 1][x] != '1')
	{
		if (game->map->grid[y + 1][x] == 'E' && (game->count_collectables == 0))
			return ;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		game->map->grid[y][x] = '0';
		y++;
		if (game->map->grid[y][x] == 'C')
			game->count_collectables--;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		mlx_image_to_window(game->mlx, game->image->player, x * TILE, y * TILE);
	}
	game->player_pos_y = y;
	game->map->grid[y][x] = 'P';
}

static void	player_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map->grid[y][x - 1] != '1')
	{
		if (game->map->grid[y][x - 1] == 'E' && (game->count_collectables == 0))
			return ;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		game->map->grid[y][x] = '0';
		x--;
		if (game->map->grid[y][x] == 'C')
			game->count_collectables--;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		mlx_image_to_window(game->mlx, game->image->player, x * TILE, y * TILE);
	}
	game->player_pos_x = x;
	game->map->grid[y][x] = 'P';
}

static void	player_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos_x;
	y = game->player_pos_y;
	if (game->map->grid[y][x + 1] != '1')
	{
		if (game->map->grid[y][x + 1] == 'E' && (game->count_collectables == 0))
			return ;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		game->map->grid[y][x] = '0';
		x++;
		if (game->map->grid[y][x] == 'C')
			game->count_collectables--;
		mlx_image_to_window(game->mlx, game->image->background, x * TILE, y * TILE);
		mlx_image_to_window(game->mlx, game->image->player, x * TILE, y * TILE);
	}
	game->player_pos_x = x;
	game->map->grid[y][x] = 'P';
}

void	keypress(int keycode, t_game *game)
{
	if (keycode == UP)
		player_up(game);
	else if (keycode == DOWN)
		player_down(game);
	else if (keycode == LEFT)
		player_left(game);
	else if (keycode == RIGHT)
		player_right(game);
	else if (keycode == ESCAPE)
	{
		cleanup_game(game);
		exit(0);
	}
}
