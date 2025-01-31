/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:50:59 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/31 14:06:48 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	validate_map(t_game *game, char *path)
// {
// 	valid_map_size(game->map);
// 	valid_map_sides(game->map);
// 	valid_chars(game);
// 	valid_accessibilty(game);
// }

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Error! Invalid number of arguments!\n");
		return (1);
	}
	read_map(argv[1], &game);
	// validate_map(&game, argv[1]);
	(void)argv;
	game.mlx = mlx_init(game.map_width * TILE, game.map_height * TILE, "so_long", false);
	mlx_loop(game.mlx);

	// render_map(&game);
	// mlx_key_hook(game.mlx, keypress, &game);
	// cleanup_game(&game);
	return (0);
}
