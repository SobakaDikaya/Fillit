/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:39:53 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/26 18:24:40 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->mapsize)
	{
		ft_putendl(map->map[y]);
		y++;
	}
}

void	free_map(char **map, int mapsize)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < mapsize)
	{
		free(map[i]);
		i++;
	}
}

char	**map_creat(int map_size, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	free_map(map->map, map->mapsize - 1);
	if (!(map->map = (char**)malloc(sizeof(char *) * map_size)))
		return (NULL);
	while (y < map_size)
	{
		map->map[y] = ft_strnew(map_size);
		while (x < map_size)
		{
			map->map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	map->mapsize = map_size;
	return (map->map);
}
