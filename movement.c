/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:21:03 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 13:52:36 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_movement(t_game *game, int new_x, int new_y)
{
	if (game->map_grid[new_y][new_x] != '1')
	{
		if (game->map_grid[new_y][new_x] == 'E' && (game->collectables == 0))
			close_game(game);
		else if (game->map_grid[new_y][new_x] == 'C')
			game->collectables--;
		if (game->map_grid[new_y][new_x] != 'E')
		{
			game->map_grid[game->player_pos_y][game->player_pos_x] = '0';
			game->map_grid[new_y][new_x] = 'P';
			game->player_pos_x = new_x;
			game->player_pos_y = new_y;
		}
		render_map(game);
	}
}

void	keypress(mlx_key_data_t keycode, void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	if (keycode.action == MLX_RELEASE)
	{
		if (keycode.key == MLX_KEY_W)
			player_movement(game, game->player_pos_x, game->player_pos_y - 1);
		else if (keycode.key == MLX_KEY_A)
			player_movement(game, game->player_pos_x - 1, game->player_pos_y);
		else if (keycode.key == MLX_KEY_S)
			player_movement(game, game->player_pos_x, game->player_pos_y + 1);
		else if (keycode.key == MLX_KEY_D)
			player_movement(game, game->player_pos_x + 1, game->player_pos_y);
		else if (keycode.key == MLX_KEY_ESCAPE)
			close_game(game);
	}
}
