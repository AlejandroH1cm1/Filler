/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:08:25 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 20:50:05 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

static int		compare(char *map, int i, t_coor coor)
{
	t_coor	cmp;
	int		lenm;

	lenm = getlen(map);
	cmp = get_c(i, lenm);
	cmp.x = cmp.x + coor.x;
	cmp.y = cmp.y + coor.y;
	i = coortoi(lenm, cmp);
	if (i < 0)
		return (1);
	if (i > (int)ft_strlen(map))
		return (1);
	if (map[i] != '.')
		return (1);
	if (map[i] == '.')
		return (0);
	return (1);
}

static t_coor	try(char *map, char *piece, int i, int coor)
{
	int	j;

	j = 0;
	if (map[coor] == '.')
		return (get_c(-1, 0));
	while (piece[j])
	{
		if (piece[j] != '\n' && j != i)
			if (compare(map, coor, substr(piece, i, j)) && piece[j] == '*')
				return (get_c(-1, 0));
		j++;
	}
	return (transform(map, coor, piece, i));
}

static t_coor	try_p_end(char *map, char *piece, int coor)
{
	int		fst;
	int		lst;
	int		i;
	t_coor	res;

	fst = 0;
	while (piece[fst] != '*')
		fst++;
	lst = ft_strlen(piece);
	while (piece[lst] != '*')
		lst--;
	i = lst;
	while (i >= fst)
	{
		if (piece[i] == '*')
		{
			res = try(map, piece, i, coor);
			if (res.val == 1)
				return (res);
		}
		i--;
	}
	return (res);
}

static t_coor	try_p_beg(char *map, char *piece, int coor)
{
	int		fst;
	int		lst;
	int		i;
	t_coor	res;

	fst = 0;
	while (piece[fst] != '*')
		fst++;
	lst = ft_strlen(piece);
	while (piece[lst] != '*')
		lst--;
	i = fst;
	while (i <= lst)
	{
		if (piece[i] == '*')
		{
			res = try(map, piece, i, coor);
			if (res.val == 1)
				return (res);
		}
		i++;
	}
	return (res);
}

t_coor			try_piece(char *map, char *piece, t_coor coor, char pl)
{
	t_coor	res;
	int		len;
	int		dir;
	int		i;

	len = 0;
	while (map[len] != '\n')
		len++;
	dir = choose_dir(map, len, pl);
	i = coortoi(len + 1, coor);
	if (dir == 1 || dir == -1)
		res = try_p_end(map, piece, i);
	else
		res = try_p_beg(map, piece, i);
	return (res);
}
