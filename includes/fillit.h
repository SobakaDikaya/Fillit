/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:03:09 by gdaniel           #+#    #+#             */
/*   Updated: 2018/12/26 18:30:36 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef	struct	s_figure
{
	t_point		points[4];
	char		ch;
	int			cm[2];
}				t_figure;

typedef struct	s_map
{
	char	**map;
	int		mapsize;
}				t_map;

void			error();
int				errorinputfile(int argc);
t_list			*ft_readfile(const int fd, int *count);
int				valid(char *buff);
void			createpoints(t_point *cord, const char *str);
t_point			setpoint(int x, int y);
t_point			minuspoint(t_point p, int x, int y);
void			minuspoints(t_point *points, int count, int x, int y);
void			editfigureslist(t_list **figures, t_point *points,
int *count, int *cordmax);
void			free_map(char **map, int mapsize);
char			**map_creat(int map_size, t_map *map);
int				fillmap(t_list *fig, int q, t_map *map);
void			ft_print_map(t_map *map);
int				findxmin(t_point *points, int count);

#endif
