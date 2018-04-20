/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfi.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:14:51 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/19 21:00:15 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFI_H
# define LIBFI_H
# include "libft.h"

typedef struct	s_coor
{
	int			x;
	int			y;
	int			val;
}				t_coor;

int				get_w(char *st);
int				get_h(char *st);
int				check_sq(char *map, int i, int len);
char			get_op(char pl);
char			*getmap(int w, int h);
void			p_piece(char *map, char *piece, char pl);
t_coor			get_c(int i, int len);
t_coor			get_center(char *map, int len);
t_coor			*alloc_pos(char *map, char pl, int len);
t_coor			*calc_pos(char *map, char pl);
int				diff_c(int len, t_coor coor, int i);
int				clopp_forw(char *map, int i, int len, char pl);
int				clopp_back(char *map, int i, int len, char pl);
int				closed_v(char *map, int len, char pl);
int				closed_h(char *map, int len, char pl);
int				v_val(char *map, int i, int len, int dir);
int				h_val(char *map, int i, int dir);
void			order_pos(t_coor *pos);
int				choose_dir(char *map, int len, int pl);
t_coor			try_piece(char *map, char *piece, t_coor coor, char pl);
int				coortoi(int len, t_coor coor);
t_coor			transform(char *map, int i, char *piece, int j);
int				getlen(char *map);
t_coor			substr(char *piece, int i, int j);

#endif
