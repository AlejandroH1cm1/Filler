/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:39:16 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/20 13:01:29 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

static t_coor	get_clopp(char *map, int i, int len, char pl)
{
	t_coor	forw;
	t_coor	back;

	forw = get_c(clopp_forw(map, i, len, pl), len + 1);
	back = get_c(clopp_back(map, i, len, pl), len + 1);
	if (diff_c(len, forw, i) < diff_c(len, back, i))
		return (forw);
	return (back);
}

int				diff_c(int len, t_coor coor, int i)
{
	int x;
	int y;
	int diffx;
	int diffy;

	x = i % (len + 1) - 4;
	y = i / (len + 1) - 1;
	diffx = ft_diff(coor.x, x);
	diffy = ft_diff(coor.y, y);
	return (diffx + diffy);
}

static int		calc_val(char *map, int i, int len, char pl)
{
	t_coor	center;
	t_coor	op;
	int		dir;

	dir = choose_dir(map, len, pl);
	center = get_center(map, len);
	op = get_clopp(map, i, len, pl);
	if (map[center.val] == '.')
		return (diff_c(len, center, i));
	if (!closed_v(map, len, pl) && !closed_h(map, len, pl))
	{
		if (dir == -2 || dir == 2)
			return (h_val(map, i, dir));
		if (dir == -1 || dir == 1)
			return (v_val(map, i, len, dir));
	}
	op = get_clopp(map, i, len, pl);
	return (diff_c(len, op, i));
}

t_coor			*calc_pos(char *map, char pl)
{
	int		i;
	int		len;
	int		count;
	t_coor	*res;

	i = 0;
	count = 0;
	while (map[i] != '\n')
		i++;
	len = i;
	res = alloc_pos(map, pl, len);
	while (map[i] != '\0')
	{
		if (map[i] == pl && check_sq(map, i, len))
		{
			res[count] = get_c(i, len + 1);
			res[count].val = calc_val(map, i, len, pl);
			count++;
		}
		i++;
	}
	return (res);
}

void			order_pos(t_coor *pos)
{
	int		i;
	int		j;
	t_coor	aux;

	i = 0;
	j = 0;
	while (pos[i].val != -1)
	{
		j = 0;
		while (pos[j].val != -1)
		{
			if (j > i && pos[j].val < pos[i].val && pos[j].val != 0)
			{
				aux = pos[j];
				pos[j] = pos[i];
				pos[i] = aux;
				j = 0;
			}
			j++;
		}
		i++;
	}
}
