/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:30:02 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/13 16:46:52 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map_name(char *path)
{
	int		i;
	int		j;
	int		length;
	char	*valid_ending;
	
	valid_ending = ".ber";
	length = ft_strlen(path);
	if (!path || (length < 4))
	{
		ft_printf("Error! Invalid map name!\n");
		exit(1);
	}
	i = length - 4;
	j = 0;
	while (path[i] == valid_ending[j])
	{
		i++;
		j++;
	}
	if (path[i] != valid_ending[j])
	{
		ft_printf("Error! Invalid map name!\n");
		exit(1);
	}
}
