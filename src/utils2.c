/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:14:55 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/20 13:01:25 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

t_coor	get_c(int i, int len)
{
	t_coor res;

	if (i == -1)
	{
		res.x = 0;
		res.y = 0;
		res.val = 0;
		return (res);
	}
	res.x = i % (len) - 4;
	res.y = i / (len) - 1;
	res.val = 0;
	return (res);
}

int		v_val(char *map, int i, int len, int dir)
{
	int		j;
	int		res;

	j = i + dir * (len + 1);
	res = 0;
	while (map[j] == '.' || map[j] == 'X' || map[j] == 'O')
	{
		j += dir * (len + 1);
		res++;
	}
	return (res);
}

int		h_val(char *map, int i, int dir)
{
	int		j;
	int		res;

	j = i + dir / 2;
	res = 0;
	while (map[j] != ' ' && map[i] != '\n' && map[i])
	{
		j += dir / 2;
		res++;
	}
	return (res);
}

int		closed_v(char *map, int len, char pl)
{
	int i;
	int j;

	i = 0;
	while (map[i] != '.' && map[i] != 'X' && map[i] != 'O')
		i++;
	while (map[i] == '.' || map[i] == 'X' || map[i] == 'O')
	{
		j = i;
		while (map[j] == '.' || map[j] == 'X' || map[j] == 'O')
		{
			if (map[j] == pl)
				break ;
			j += (len + 1);
		}
		if (j > (int)ft_strlen(map))
			return (0);
		i++;
	}
	return (1);
}

int		closed_h(char *map, int len, char pl)
{
	int i;
	int j;

	i = 0;
	while (map[i] != '.' && map[i] != 'X' && map[i] != 'O')
		i++;
	while (map[i] == '.' || map[i] == 'X' || map[i] == 'O')
	{
		j = i;
		while (map[j] == '.' || map[j] == 'X' || map[j] == 'O')
		{
			if (map[j] == pl)
				break ;
			j++;
		}
		if (map[j] == '\n' || map[j] == '\0')
			return (0);
		i += (len + 1);
	}
	return (1);
}
