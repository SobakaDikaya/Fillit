/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createandresizefigure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:28:24 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/26 18:23:42 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		resizefigure(t_list **figures, t_point *points,
int fcount, int *cordmax)
{
	int			count;
	t_list		*tmp;
	t_figure	*newfigure;

	tmp = figures[0];
	count = 0;
	while (tmp->next)
		tmp = tmp->next;
	if ((newfigure = (t_figure*)malloc(2 * sizeof(t_figure))) != NULL)
	{
		while (count < 4)
		{
			newfigure[0].points[count] = points[count];
			count++;
		}
		newfigure[0].ch = 'A' + fcount;
		newfigure[0].cm[0] = cordmax[0];
		newfigure[0].cm[1] = cordmax[1];
		if ((tmp->next = ft_lstnew(newfigure, sizeof(t_figure))) == NULL)
			error();
	}
	else
		error();
}

static void		createfigure(t_list **figures, t_point *points,
int fcount, int *cordmax)
{
	t_figure	*newfigure;
	int			count;

	count = 0;
	if ((newfigure = (t_figure*)malloc(2 * sizeof(t_figure))) != NULL)
	{
		while (count < 4)
		{
			newfigure[0].points[count] = points[count];
			count++;
		}
		newfigure[0].ch = 'A' + fcount;
		newfigure[0].cm[0] = cordmax[0];
		newfigure[0].cm[1] = cordmax[1];
		if ((figures[0] = ft_lstnew(newfigure, sizeof(t_figure))) == NULL)
			error();
	}
	else
		error();
}

void			editfigureslist(t_list **figures, t_point *points,
int *count, int *cordmax)
{
	if (*figures == NULL)
		createfigure(figures, points, count[0], cordmax);
	else
		resizefigure(figures, points, count[0], cordmax);
}
