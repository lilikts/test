/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:50:59 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/24 15:56:26 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	validate_map(t_game *game, char *path)
{
	valid_map_size(game->map);
	valid_map_sides(game->map);
	valid_chars(game);
	valid_accessibilty(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error! Invalid number of arguments!\n");
		return (1);
	}
	read_map(argv[1], game.map);
	validate_map(&game, argv[1]);
	game.mlx = mlx_init(game.map-> width * TILE, game.map-> height * TILE, "so_long", true);
	if (!game.mlx)
		exit_game();
	render_map(&game);
	mlx_key_hook(game.mlx, keypress, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
