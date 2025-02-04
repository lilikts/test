/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:50:59 by lkloters          #+#    #+#             */
/*   Updated: 2025/02/03 18:11:20 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_old.h"

// static void	validate_map(t_game *game, char *path)
// {
// 	valid_map_size(game);
// 	valid_map_sides(game);
// 	valid_chars(game);
// 	valid_accessibilty(game);
// }

int	main(int argc, char **argv)
{
	t_game *game;
	int i = 0;

	game = NULL;
	if (argc != 2)
	{
		ft_printf("Error! Invalid number of arguments!\n");
		return (1);
	}
	read_map(argv[1], game);

	// validate_map(&game, argv[1]);
	// (void)argv;
	// game.mlx = mlx_init(game.map_width * TILE, game.map_height * TILE, WINDOW_NAME, false);
	// mlx_loop(game.mlx);

	// render_map(&game);
	// mlx_key_hook(game.mlx, keypress, &game);
	// cleanup_game(&game);
	return (0);
}
