/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:50:59 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/28 15:52:44 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    validate_map(t_game *game)
{
	valid_map_name(path);
	valid_map_size(game->map);
	valid_map_sides(game->map);
	valid_chars(game->map);
	valid_accessibilty(game);
}