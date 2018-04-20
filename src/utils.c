/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 03:32:51 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 17:57:28 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

int		get_h(char *st)
{
	while (!(ft_isdigit(*st)))
		st++;
	return (ft_atoi(st));
}

int		get_w(char *st)
{
	while (!(ft_isdigit(*st)))
		st++;
	while (ft_isdigit(*st))
		st++;
	while (!(ft_isdigit(*st)))
		st++;
	return (ft_atoi(st));
}

int		check_sq(char *map, int i, int len)
{
	if (map[i + 1] == '.' || map[i - 1] == '.')
		return (1);
	if (map[i - len - 1] == '.' || map[i - len - 2] == '.' ||
		map[i - len] == '.')
		return (1);
	if (map[i + len + 1] == '.' || map[i + len] == '.' ||
		map[i + len + 2] == '.')
		return (1);
	return (0);
}

char	get_op(char pl)
{
	if (pl == 'X')
		return ('O');
	return ('X');
}

t_coor	*alloc_pos(char *map, char pl, int len)
{
	t_coor	*res;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == pl && check_sq(map, i, len))
			count++;
		i++;
	}
	res = (t_coor *)malloc((count + 1) * sizeof(t_coor));
	res[count].x = -1;
	res[count].y = -1;
	res[count].val = -1;
	return (res);
}
