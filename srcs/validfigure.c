/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validfigure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:14:10 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/26 18:08:17 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validup(char **buff, int *cord)
{
	if (buff[cord[0]][cord[1]] == '#' &&
	cord[0] - 1 >= 0 && buff[cord[0] - 1][cord[1]] == '#')
		return (1);
	return (0);
}

static int	validdown(char **buff, int *cord)
{
	if (buff[cord[0]][cord[1]] == '#' &&
	cord[0] + 1 <= 3 && buff[cord[0] + 1][cord[1]] == '#')
		return (1);
	return (0);
}

static int	validleft(char **buff, int *cord)
{
	if (buff[cord[0]][cord[1]] == '#' &&
	cord[1] - 1 >= 0 && buff[cord[0]][cord[1] - 1] == '#')
		return (1);
	return (0);
}

static int	validright(char **buff, int *cord)
{
	if (buff[cord[0]][cord[1]] == '#' &&
	cord[1] <= 3 && buff[cord[0]][cord[1] + 1] == '#')
		return (1);
	return (0);
}

int			valid(char *buff)
{
	int		c[2];
	int		result;
	char	**b;

	c[0] = 0;
	result = 0;
	b = ft_strsplit(buff, '\n');
	while (c[0] < 4)
	{
		c[1] = 0;
		while (c[1] < 4)
		{
			if (validup(b, c))
				result++;
			if (validright(b, c))
				result++;
			if (validdown(b, c))
				result++;
			if (validleft(b, c))
				result++;
			c[1]++;
		}
		c[0]++;
	}
	return (result == 6 || result == 8 ? 1 : 0);
}
