/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:38:52 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 20:01:10 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

int			main(void)
{
	char	*st;
	char	*map;
	char	*piece;
	char	pl;

	while (get_next_line2(0, &st))
	{
		if (!ft_strncmp(st, "$$$", 3))
			pl = 'O' + ('X' - 'O') * (st[10] - 1 - 48);
		if (!ft_strncmp(st, "Plateau", ft_strlen("Plateau")))
			map = getmap(get_w(st) + 4, get_h(st) + 1);
		if (!ft_strncmp(st, "Piece", ft_strlen("Piece")))
		{
			piece = getmap(get_w(st), get_h(st));
			p_piece(map, piece, pl);
			piece = NULL;
		}
	}
	return (0);
}
