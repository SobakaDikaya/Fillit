/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:53:03 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/26 18:39:08 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	findmax(t_point *points, int *cordmax)
{
	int i;

	i = 0;
	cordmax[0] = 0;
	cordmax[1] = 0;
	while (i < 4)
	{
		if (cordmax[0] < points[i].y)
			cordmax[0] = points[i].y;
		if (cordmax[1] < points[i].x)
			cordmax[1] = points[i].x;
		i++;
	}
}

static void	checkvalidread(int readfile, int count, char *buff)
{
	if (readfile != 21 && readfile != 20)
		error();
	if (count == 26)
		error();
	if (buff[20] != '\n' && buff[20] != '\0')
		error();
	if (buff[4] != '\n' && buff[9] != '\n' &&
	buff[14] != '\n' && buff[19] != '\n')
		error();
}

static void	crutch(t_point *points, int readfile, char *buff, int count)
{
	checkvalidread(readfile, count, buff);
	createpoints(points, buff);
	minuspoints(points, 4, findxmin(points, 4), points[0].y);
}

t_list		*ft_readfile(const int fd, int *count)
{
	char	buff[22];
	t_point	points[4];
	t_list	*figures;
	int		readfile[2];
	int		cordmax[2];

	count[0] = 0;
	figures = NULL;
	while ((readfile[0] = read(fd, buff, 21)) > 0)
	{
		buff[readfile[0]] = '\0';
		crutch(points, readfile[0], buff, count[0]);
		if (valid(buff))
		{
			findmax(points, cordmax);
			editfigureslist(&figures, points, count, cordmax);
		}
		else
			error();
		count[0]++;
		readfile[1] = readfile[0];
	}
	readfile[0] == 0 && readfile[1] == 21 ? error() : 0;
	readfile[0] == 0 && count[0] == 0 ? error() : 0;
	return (figures);
}
