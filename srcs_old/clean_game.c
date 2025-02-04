/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:15:52 by lkloters          #+#    #+#             */
/*   Updated: 2025/02/03 18:11:20 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_old.h"

void	cleanup_game(t_game *game)
{
	if (game)
		free(game);
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
}

void	exit_game(void)
{
	ft_printf("Error! Failed to initialize mlx or mlx window!\n");
	exit (1);
}

void delete_texture(t_texture *texture)
{
	mlx_delete_texture(texture->background);
	mlx_delete_texture(texture->wall);
	mlx_delete_texture(texture->exit);
	mlx_delete_texture(texture->player);
	mlx_delete_texture(texture->collectable);
}
