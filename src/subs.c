/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:08:24 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 18:08:29 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

t_coor	substr(char *piece, int i, int j)
{
	t_coor	coor_i;
	t_coor	coor_j;
	t_coor	res;
	int		len;

	len = getlen(piece);
	coor_i.y = i / len;
	coor_i.x = i - coor_i.y * len;
	coor_j.y = j / len;
	coor_j.x = j - coor_j.y * len;
	res.x = coor_j.x - coor_i.x;
	res.y = coor_j.y - coor_i.y;
	return (res);
}
