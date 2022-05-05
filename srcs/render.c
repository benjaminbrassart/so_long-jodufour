/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:07:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 00:28:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "e_axis.h"
#include "e_ret.h"

/**
	@brief	Display the current game image on the window.

	@param	a The all structure containing the game and display data.

	@return	The updated program status.
*/
int	render(t_all *const a)
{
	render_background(a);
	render_player(a);
	render_enemy(a);
	if (render_score(a))
		return (a->ret);
	return (a->ret = SUCCESS);
}
