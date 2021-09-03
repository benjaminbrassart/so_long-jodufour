/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:38:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 22:56:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "type/t_map.h"
#include "enum/e_direction.h"

/*
**	singleton to get map
*/
t_map	*sl_map(void)
{
	static t_map	map = {NULL, {0, 0, 0}, 0, 0, 0, 0, DOWN};

	return (&map);
}