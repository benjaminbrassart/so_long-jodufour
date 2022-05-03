/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_player_action.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:50:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/04 00:16:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_PLAYER_ACTION_H
# define LOOKUP_PLAYER_ACTION_H

# include <stdint.h>
# include "t_game.h"
# include "e_action.h"

typedef struct s_action	t_action;
typedef void			(*t_fct)(t_game *const g, t_config const *const c);

struct s_action
{
	uint8_t const	mask;
	t_fct const		fct;
};

static t_action const	g_action[] = {
{1 << MOVE_EAST, game_player_move_east},
{1 << MOVE_NORTH, game_player_move_north},
{1 << MOVE_WEST, game_player_move_west},
{1 << MOVE_SOUTH, game_player_move_south},
{1 << MOVE_EAST | 1 << MOVE_NORTH, game_player_move_east_north},
{1 << MOVE_NORTH | 1 << MOVE_WEST, game_player_move_north_west},
{1 << MOVE_WEST | 1 << MOVE_SOUTH, game_player_move_west_south},
{1 << MOVE_SOUTH | 1 << MOVE_EAST, game_player_move_south_east},
{0}
};

#endif
