/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 08:54:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/22 08:59:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_map.h"
#include "mlx.h"
#include "so_long.h"

int	sl_run_game(t_map map)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (MLX_ERRNO);
}
