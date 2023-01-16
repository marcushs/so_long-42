/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:05:02 by hleung            #+#    #+#             */
/*   Updated: 2023/01/16 16:19:45 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/so_long.h"
#include "includes/libft.h"

int	key_hook(int keycode, t_slg *slg)
{
	if (keycode == 13 && slg->map->map[slg->p->y - 1][slg->p->x] != '1')
	{
		printf("UP\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->y--;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		for (int i = 0; slg->map->map[i]; i++)
			printf("%s", slg->map->map[i]);
		printf("\n");
	}
	else if (keycode == 2 && slg->map->map[slg->p->y][slg->p->x + 1] != '1')
	{
		printf("RIGHT\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->x++;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		for (int i = 0; slg->map->map[i]; i++)
			printf("%s", slg->map->map[i]);
		printf("\n");
	}
	else if (keycode == 1 && slg->map->map[slg->p->y + 1][slg->p->x] != '1')
	{
		printf("DOWN\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->x++;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		for (int i = 0; slg->map->map[i]; i++)
			printf("%s", slg->map->map[i]);
		printf("\n");
	}
	else if (keycode == 0 && slg->map->map[slg->p->y][slg->p->x - 1] != '1')
	{
		printf("LEFT\n");
		slg->map->map[slg->p->y][slg->p->x] = '0';
		slg->p->x--;
		slg->map->map[slg->p->y][slg->p->x] = 'P';
		for (int i = 0; slg->map->map[i]; i++)
			printf("%s", slg->map->map[i]);
		printf("\n");
	}
	else 
	{
		for (int i = 0; slg->map->map[i]; i++)
			printf("%s", slg->map->map[i]);
		printf("\n");
	}
	return (0);
}

int	main(void)
{
	t_slg	*slg;

	slg = (t_slg *)malloc(sizeof(t_slg));
	slg->map = parse_map("assets/maps/map0.ber");
	slg->p = get_point(slg->map->map, 'P');
	slg->e = get_point(slg->map->map, 'E');
	slg->mlx = mlx_init();
	slg->win = mlx_new_window(slg->mlx, 640, 480, "Hello world!");
	for (int i = 0; slg->map->map[i]; i++)
		printf("%s", slg->map->map[i]);
	printf("\n");
	mlx_key_hook(slg->win, key_hook, &slg);
	mlx_loop(slg->mlx);
}