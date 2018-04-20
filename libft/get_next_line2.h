/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:08:55 by aherrera          #+#    #+#             */
/*   Updated: 2018/04/18 18:27:12 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE2_H
# define GET_NEXT_LINE2_H
# define BUFF_SIZE 1
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

int	get_next_line2(const int fd, char **line);

#endif
