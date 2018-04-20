/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:37:42 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 21:00:00 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

t_coor	transform(char *map, int i, char *piece, int j)
{
	t_coor	aux;
	t_coor	res;

	aux.y = (-j) / getlen(piece);
	aux.x = (j % getlen(piece)) * -1;
	res = get_c(i, getlen(map));
	res.x = res.x + aux.x;
	res.y = res.y + aux.y;
	res.val = 1;
	return (res);
}

int		clopp_back(char *map, int i, int len, char pl)
{
	int	dif;
	int	aux;
	int	j;
	int	res;

	j = i;
	dif = 100;
	res = ft_strlen(map) * 3;
	while (j > len + 5)
	{
		if (map[j] == get_op(pl))
			aux = diff_c(len, get_c(j, len + 1), i);
		if (aux <= dif)
		{
			dif = aux;
			res = j;
		}
		else
			return (res);
		j--;
	}
	return (res);
}

int		clopp_forw(char *map, int i, int len, char pl)
{
	int dif;
	int aux;
	int j;
	int res;

	j = i;
	dif = 100;
	res = ft_strlen(map) * 3;
	while (map[j])
	{
		if (map[j] == get_op(pl))
			aux = diff_c(len, get_c(j, len + 1), i);
		if (aux <= dif)
		{
			dif = aux;
			res = j;
		}
		else
			return (res);
		j++;
	}
	return (res);
}

int		coortoi(int len, t_coor coor)
{
	int y;
	int x;

	y = (coor.y + 1) * len;
	x = coor.x + 4;
	return (x + y);
}

int		getlen(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	return (i + 1);
}
