/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:46:16 by hleung            #+#    #+#             */
/*   Updated: 2023/01/16 16:25:39 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/so_long.h"
#include <stdio.h>
#include <stdlib.h>

static char	*get_texture_path(t_map *map, int x, int y, char c)
{
	if (c == '1' && ((y == 0 || y == map->row - 1) || (x == 0 || x == map->col - 1)))
		return ("assets/imgs/rock.xpm");
	else if (c == '1')
		return ("assets/imgs/tree.xpm");
	else if (c == 'P')
		return ("assets/imgs/samurai.xpm");
	else if (c == 'E')
		return ("assets/imgs/temple.xpm");
	else if (c == 'C')
		return ("assets/imgs/sushi.xpm");
	else 
		return ("assets/imgs/background.xpm");
}

static void	render_map(t_slg *slg)
{
	int		img_width;
	int		img_height;
	char	*relative_path = "assets/imgs/rock.xpm";
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (slg->map->map[y])
	{
		while (slg->map->map[y][x])
		{
			relative_path = get_texture_path(slg->map, x, y, slg->map->map[y][x]);
			slg->img = mlx_xpm_file_to_image(slg->mlx, relative_path, &img_width, &img_height);
			mlx_put_image_to_window(slg->mlx, slg->win, slg->img, x * 64, y * 64);
			x++;
		}
	x = 0;
	y++;
	}
}

void	launch_mlx(char *file_path)
{
	t_slg	*slg;

	slg = (t_slg *)malloc(sizeof(t_slg));
	if (!slg) 
		return ;
	slg->map = parse_map(file_path);
	slg->mlx = mlx_init();
	slg->win = mlx_new_window(slg->mlx, slg->map->col * 64, slg->map->row *64, "so_long");
	slg->img = NULL;
	render_map(slg);
	mlx_loop(slg->mlx);
}

// int	main(void)
// {
// 	t_map	*map = parse_map("assets/maps/map1.ber");
// 	int	x = 0;
// 	int	y = 0;

// 	for (int i = 0; map->map[i]; i++)
// 		printf("%s", map->map[i]);
// 	printf("\n");
// 	printf("no of rows = %d\n", map->row);
// 	printf("no of cols = %d\n", map->col);
// 	while (map->map[y])
// 	{
// 		while (map->map[y][x])
// 		{
// 			printf("y = %d\n", y);
// 			printf("x = %d\n", x);
// 			printf("%s\n", get_texture_path(map, x, y, map->map[y][x]));
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }