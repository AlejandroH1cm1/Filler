/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 10:10:01 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 20:21:32 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

static int	count_bot(char *map, int len, int pl, int sum)
{
	int i;
	int j;

	i = ft_strlen(map);
	while (map[i] != '.' && map[i] != 'X' && map[i] != 'O')
		i--;
	while (map[i] == '.' || map[i] == 'X' || map[i] == 'O')
	{
		j = i;
		while (map[j] == '.' || map[j] == 'X' || map[j] == 'O')
		{
			if (map[j] == pl)
				break ;
			j--;
		}
		if (map[j] != ' ')
			break ;
		i -= (len + 1);
		sum++;
	}
	return (sum);
}

static int	count_top(char *map, int len, int pl, int sum)
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
		if (map[j] != '\n' && map[j] != '\0')
			break ;
		i += (len + 1);
		sum++;
	}
	return (sum);
}

static int	count_rgt(char *map, int len, int pl, int sum)
{
	int i;
	int j;

	i = 0;
	while (map[i] != '.' && map[i] != 'X' && map[i] != 'O')
		i++;
	while (map[i] != '\n')
		i++;
	i--;
	while (map[i] == '.' || map[i] == 'X' || map[i] == 'O')
	{
		j = i;
		while (map[j] == '.' || map[j] == 'X' || map[j] == 'O')
		{
			if (map[j] == pl)
				break ;
			j += (len + 1);
		}
		if (j < (int)ft_strlen(map))
			break ;
		sum++;
		i--;
	}
	return (sum);
}

static int	count_lft(char *map, int len, int pl, int sum)
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
		if (j < (int)ft_strlen(map))
			break ;
		sum++;
		i++;
	}
	return (sum);
}

int			choose_dir(char *map, int len, int pl)
{
	int lft;
	int rgt;
	int top;
	int bot;

	lft = count_lft(map, len, pl, 0);
	rgt = count_rgt(map, len, pl, 0);
	top = count_top(map, len, pl, 0);
	bot = count_bot(map, len, pl, 0);
	if (lft == 0)
		return (2);
	if (rgt == 0)
		return (-2);
	if (top == 0)
		return (1);
	if (bot == 0)
		return (-1);
	if (rgt <= lft && rgt <= top && rgt <= bot)
		return (2);
	if (lft <= rgt && lft <= top && lft <= bot)
		return (-2);
	if (top <= lft && top <= rgt && top <= bot)
		return (-1);
	return (1);
}
