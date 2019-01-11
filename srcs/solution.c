/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:43:00 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/27 14:22:29 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	returnsetfigure(t_map *map, t_figure *figure, int *cord, int i)
{
	int	cords[2];

	while (i >= 0)
	{
		i--;
		if (i < 0)
			break ;
		cords[0] = cord[0] + figure->points[i].y;
		cords[1] = cord[1] + figure->points[i].x;
		if ((cords[0] >= 0) && (cords[1] >= 0) && (cords[0] < map->mapsize)
		&& (cords[1] < map->mapsize))
			map->map[cords[0]][cords[1]] = '.';
	}
}

static int	fig_disp(t_figure *fig, t_map *map, int *cord)
{
	int	i;
	int	cords[2];

	i = 0;
	while (i < 4)
	{
		cords[0] = cord[0] + fig->points[i].y;
		cords[1] = cord[1] + fig->points[i].x;
		if ((cords[0] >= 0) && (cords[1] >= 0) && (cords[0] < map->mapsize)
		&& (cords[1] < map->mapsize) && map->map[cords[0]][cords[1]] == '.')
		{
			map->map[cords[0]][cords[1]] = fig->ch;
			i++;
		}
		else
		{
			returnsetfigure(map, fig, cord, i);
			return (0);
		}
	}
	return (1);
}

int			fillmap(t_list *fig, int q, t_map *map)
{
	int			cord[2];

	if (fig == NULL)
		return (1);
	cord[0] = 0;
	while (cord[0] < map->mapsize - ((t_figure*)fig->content)->cm[0] + 1)
	{
		cord[1] = 0;
		while (cord[1] < map->mapsize - ((t_figure*)fig->content)->cm[1] + 1)
		{
			if ((fig_disp(((t_figure*)fig->content), map, cord)))
			{
				if (fillmap(fig->next, q, map))
					return (1);
				else
					returnsetfigure(map, ((t_figure*)fig->content), cord, 4);
			}
			cord[1]++;
		}
		cord[0]++;
	}
	return (0);
}
