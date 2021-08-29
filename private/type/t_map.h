/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:22:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/28 05:02:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "type/t_int.h"

typedef struct s_map	t_map;

struct s_map
{
	char	*e;
	t_uint	w;
	t_uint	h;
	t_uint	cnt_p;
	t_uint	cnt_c;
	t_uint	cnt_e;
};

int		sl_map_check_borders(void);
int		sl_map_check_cep(void);
int		sl_map_check_width(char const *line);
int		sl_map_check(void);
int		sl_map_load(char const *ber);
int		sl_map_read(int const fd);

void	sl_map_clear(void);
void	sl_map_print(void);

t_map	*sl_map(void);

#endif
