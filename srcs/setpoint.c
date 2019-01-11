/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:03:28 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/26 18:40:19 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		setpoint(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

void		minuspoints(t_point *points, int count, int x, int y)
{
	while (count--)
	{
		points[count].x -= x;
		points[count].y -= y;
	}
}

int			findxmin(t_point *points, int count)
{
	int	i;
	int	xmin;

	xmin = 4;
	i = 0;
	while (i < count)
	{
		if (xmin > points[i].x)
			xmin = points[i].x;
		i++;
	}
	return (xmin);
}

static void	createpointserror(int iter2, char ch)
{
	if (ch != '.' && ch != '#')
		error();
	if (iter2 >= 5)
		error();
}

void		createpoints(t_point *cord, const char *str)
{
	int iter[3];

	iter[0] = 0;
	iter[2] = 0;
	while (*str)
	{
		iter[1] = 0;
		while (*str != '\n')
		{
			createpointserror(iter[2], *str);
			if (*str == '#')
			{
				cord[iter[2]] = setpoint(iter[1], iter[0]);
				iter[2]++;
			}
			iter[1]++;
			str++;
		}
		iter[0]++;
		str++;
	}
	if (iter[2] == 0)
		error();
}
