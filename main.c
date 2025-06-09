/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:40:31 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/09 18:09:03 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error! Invalid number of arguments!\n");
		return (EXIT_FAILURE);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		handle_error(-1, "Creating game failed!", NULL, NULL);
	create_map(argv[1], game);
	create_game(game);
	return (0);
}
