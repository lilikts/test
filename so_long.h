/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:59:44 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/17 13:53:18 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct s_map
{
	char **grid;
	int width;
	int height;
} t_map;

bool	calc_map_sides (t_map *map);