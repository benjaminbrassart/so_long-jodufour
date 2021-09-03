/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_none.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:58:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 05:30:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "so_long.h"
#include "type/t_block.h"
#include "type/t_map.h"
#include "enum/e_ret.h"

/*
**	default behavior when no hooks are triggered
*/
int	sl_event_none(void *null)
{
	t_uint *const	sleep = sl_sleep();
	int				ret;

	(void)null;
	ret = SUCCESS;
	if (!(*sleep % SLEEP_TIME))
	{
		sl_map_update_enemy();
		ret = sl_block_redraw_enemy();
	}
	++*sleep;
	return (ret);
}