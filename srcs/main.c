/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:02:28 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/26 15:42:47 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	create_t_map(t_map *map, int mapsize)
{
	map->map = map_creat(mapsize, map);
	map->mapsize = mapsize;
}

int			main(int argc, char **argv)
{
	t_list	*buff;
	t_map	map[1];
	int		count[1];
	int		fd;
	int		size;

	if (argc > 1)
		if ((fd = open(argv[1], O_RDONLY)) > 0)
		{
			buff = ft_readfile(fd, count);
			map->map = NULL;
			size = 2;
			while (size * size < count[0])
				size++;
			create_t_map(map, size);
			while (!fillmap(buff, count[0], map))
			{
				map->mapsize++;
				map->map = map_creat(map->mapsize, map);
			}
			ft_print_map(map);
		}
	return (0);
}
