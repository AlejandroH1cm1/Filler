/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:10:49 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 18:55:35 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

t_coor	get_center(char *map, int len)
{
	int		i;
	t_coor	center;

	i = ft_strlen(map) / 2 + (len + 1);
	center = get_c(i, len + 1);
	center.val = i;
	return (center);
}

void	p_piece(char *map, char *piece, char pl)
{
	t_coor	*pos;
	int		i;
	t_coor	res;

	i = 1;
	pos = calc_pos(map, pl);
	order_pos(pos);
	res = try_piece(map, piece, pos[0], pl);
	if (pos[0].val == -1)
	{
		ft_putstr("0 0\n");
		return ;
	}
	while ((res.val == 0 || pos[i].val == 0) && pos[i].val != -1)
	{
		res = try_piece(map, piece, pos[i], pl);
		i++;
	}
	ft_putstr(ft_itoa(res.y));
	ft_putchar(' ');
	ft_putendl(ft_itoa(res.x));
}

char	*getmap(int w, int h)
{
	char	*map;
	int		i;
	char	*tmp;

	map = (char *)malloc(((w + 1) * h + 1) * sizeof(char));
	tmp = NULL;
	i = 0;
	while (i < h)
	{
		get_next_line2(0, &tmp);
		ft_strcat(map, tmp);
		free(tmp);
		map[ft_strlen(map) + 1] = '\0';
		map[ft_strlen(map)] = '\n';
		i++;
	}
	map[ft_strlen(map) - 1] = '\0';
	return (map);
}
