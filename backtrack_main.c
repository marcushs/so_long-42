/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:16:45 by hleung            #+#    #+#             */
/*   Updated: 2023/01/14 17:01:37 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(void)
{
	printf("test\n");
	t_map	*map = parse_map("assets/maps/map1.ber");
	t_point	*start;
	t_point	*end;
	int		**dir = create_dir_array();
	int	res;

	for (int i = 0; map->map[i]; i++)
		printf("%s", map->map[i]);

	printf("\n");
	start = get_point(map->map, 'P');
	end = get_point(map->map, 'E');
	printf("\n");
	printf("P's x = %d\n", start->x);
	printf("P's y = %d\n", start->y);
	printf("E's x = %d\n", end->x);
	printf("E's y =	%d\n", end->y);
	printf("no of rows = %d\n", map->row);
	printf("no of cols = %d\n", map->col);
	printf("no of collectibles = %d\n", map->count[67]);
	res = backtrack(map, start, end, dir);
	printf("\n");
	for (int i = 0; map->map[i]; i++)
		printf("%s", map->map[i]);
	printf("\n");
	printf("\n");
	printf("%d\n", res);
	free(map);
	free(start);
	free(end);
	free(dir);
}
// printf("x: %d y: %d -> ", cur->x, cur->y);
// printf("%d\n", *count);
