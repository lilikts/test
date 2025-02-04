/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:15:33 by lkloters          #+#    #+#             */
/*   Updated: 2025/02/04 17:44:47 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void print_map(char **map)
// {
// 	int i = 0;
// 	while (map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }

int main(int argc, char **argv)
{
	t_game *game;
	t_texture *texture;
	t_image *image;
	game = malloc(sizeof(t_game));
	texture = malloc(sizeof(t_texture));
	image = malloc(sizeof(t_image));
	if (!game || !texture || !image)
	{
		printf("Error! Structs failed!");
		//free
		exit(1);
	}
		exit(1);

	if (argc != 2)
	{
		printf("Error");
		return (1);
	}
	valid_map_name(argv[1]);
	read_map(argv[1], game);
	//print_map(game->map_grid);
	valid_map_size(game);
	valid_map_sides(game);
	valid_chars(game);
	valid_accessibilty(game);
	render_map(game, texture, image);
	// char **copy = duplicate_map(game);
	// flood_fill_target(copy, game->player_pos_x, game->player_pos_y, '1');
	// printf("\n");
	// print_map(copy);
	// if (!is_accessible(game, copy))
	// 	printf("Error Accessibility\n");
	return (0);
}
