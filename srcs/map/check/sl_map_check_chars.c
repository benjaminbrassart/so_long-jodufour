/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:46:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 03:53:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "ft_string.h"
#include "type/t_map.h"
#include "enum/e_map_char.h"
#include "enum/e_ret.h"

/*
**	check map chars
**	return an error if at least one of the following is true:
**		collect count == 0
**		player count != 1
**		exit count != 1
**		there is a unrecognized char in map
*/
int	sl_map_check_chars(void)
{
	t_map *const	map = sl_map();
	char const		*ptr = map->ptr;

	while (*ptr)
	{
		if (!ft_strchr(MAP_CHAR, *ptr))
			return (MAP_ERR);
		else if (*ptr == MAP_CHAR[COLLECT])
			++map->count.collect;
		else if (*ptr == MAP_CHAR[EXIT])
		{
			map->idx_exit = ptr - map->ptr;
			++map->count.exit;
		}
		else if (*ptr == MAP_CHAR[PLAYER])
		{
			map->idx_player = ptr - map->ptr;
			++map->count.player;
		}
		++ptr;
	}
	if (!map->count.collect || map->count.exit != 1 || map->count.player != 1)
		return (MAP_ERR);
	return (SUCCESS);
}