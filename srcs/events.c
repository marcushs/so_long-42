/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:05:02 by hleung            #+#    #+#             */
/*   Updated: 2023/01/19 19:43:40 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long.h"
#include "../includes/libft.h"

int	event_listener(int keycode, t_slg *slg)
{
	if (slg->count != slg->map->c[67])
		move_player_close(keycode, slg);
	else
		move_player_open(keycode, slg);
	if (keycode == 53 || ((slg->p->y == slg->e->y && slg->p->x == slg->e->x) \
	&& slg->count == slg->map->c[67]))
	{
		mlx_destroy_window(slg->mlx, slg->win);
		exit(0);//(int)slg->mlx);
	}
	return (0);
}

void	move_player_close(int keycode, t_slg *slg)
{
	if (keycode == 13 && slg->map->map[slg->p->y - 1][slg->p->x] != '1' && \
		slg->map->map[slg->p->y - 1][slg->p->x] != 'E')
		move_up(slg);
	else if (keycode == 2 && slg->map->map[slg->p->y][slg->p->x + 1] != '1' && \
			slg->map->map[slg->p->y][slg->p->x + 1] != 'E')
		move_right(slg);
	else if (keycode == 1 && slg->map->map[slg->p->y + 1][slg->p->x] != '1' && \
			slg->map->map[slg->p->y + 1][slg->p->x] != 'E')
		move_down(slg);
	else if (keycode == 0 && slg->map->map[slg->p->y][slg->p->x - 1] != '1' && \
			slg->map->map[slg->p->y][slg->p->x - 1] != 'E')
		move_left(slg);
}

void	move_player_open(int keycode, t_slg *slg)
{
	if (keycode == 13 && slg->map->map[slg->p->y - 1][slg->p->x] != '1')
		move_up(slg);
	else if (keycode == 2 && slg->map->map[slg->p->y][slg->p->x + 1] != '1')
		move_right(slg);
	else if (keycode == 1 && slg->map->map[slg->p->y + 1][slg->p->x] != '1')
		move_down(slg);
	else if (keycode == 0 && slg->map->map[slg->p->y][slg->p->x - 1] != '1')
		move_left(slg);
}
