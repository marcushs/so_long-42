/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:05:02 by hleung            #+#    #+#             */
/*   Updated: 2023/01/17 08:58:15 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/so_long.h"
#include "includes/libft.h"

void	move_player(int keycode, t_slg *slg)
{
	if (keycode == 13 && slg->map->map[slg->p->y - 1][slg->p->x] != '1')
	{
		printf("UP\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->y--;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		render_map(*slg);
	}
	else if (keycode == 2 && slg->map->map[slg->p->y][slg->p->x + 1] != '1')
	{
		printf("RIGHT\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->x++;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		render_map(*slg);
	}
	else if (keycode == 1 && slg->map->map[slg->p->y + 1][slg->p->x] != '1')
	{
		printf("DOWN\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->y++;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		render_map(*slg);
	}
	else if (keycode == 0 && slg->map->map[slg->p->y][slg->p->x - 1] != '1')
	{
		printf("LEFT\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->x--;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		render_map(*slg);
	}
	else
		render_map(*slg);
}

int	event_listener(int keycode, t_slg *slg)
{
	move_player(keycode, slg);
	if (keycode == 53 || (slg->p->y == slg->e->y && slg->p->x == slg->e->x))
	{
		mlx_destroy_window(slg->mlx, slg->win);
		exit((int)slg->mlx);
	}
	return (0);
}
