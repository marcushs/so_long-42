/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:22:50 by hleung            #+#    #+#             */
/*   Updated: 2023/01/16 17:23:08 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft.h"

static void	free_nodes(t_point *s, t_point *e, t_point *c, int **d)
{
	free(s);
	s = NULL;
	free(e);
	e = NULL;
	free(c);
	c = NULL;
	free(d);
	d = NULL;
}

static int	check_walkable(char c)
{
	if (c == 'C' || c == 'P' || c == '0')
		return (1);
	return (0);
}

static int	go_to_exit(t_map *map, t_point *cur, t_point *end, int **dir)
{
	int	i;

	if (cur->x <= 0 || cur->x >= map->col || cur->y <= 0 || cur->y >= map->row)
		return (0);
	if (map->map[cur->y][cur->x] == '1' || map->map[cur->y][cur->x] == 's')
		return (0);
	if (cur->x == end->x && cur->y == end->y)
		return (1);
	if (map->map[cur->y][cur->x] == '*' \
	|| map->map[cur->y][cur->x] == 'P' || map->map[cur->y][cur->x] == '0')
		map->map[cur->y][cur->x] = 's';
	i = 0;
	while (i < 4)
	{
		cur->x = cur->x + dir[i][1];
		cur->y = cur->y + *(dir[i]);
		if (go_to_exit(map, cur, end, dir))
			return (1);
		cur->x = cur->x - dir[i][1];
		cur->y = cur->y - *(dir[i]);
		i++;
	}
	return (0);
}

static int	collect(t_map *map, t_point *cur, int **dir, int *count)
{
	int	i;

	if (cur->x <= 0 || cur->x >= map->col || cur->y <= 0 || cur->y >= map->row)
		return (0);
	if (map->map[cur->y][cur->x] == '1' || map->map[cur->y][cur->x] == '*')
		return (0);
	if (*count == map->c[67])
		return (1);
	if (check_walkable(map->map[cur->y][cur->x]))
	{
		if (map->map[cur->y][cur->x] == 'C')
			*count = *count + 1;
		map->map[cur->y][cur->x] = '*';
	}
	i = -1;
	while (++i < 4)
	{
		cur->x = cur->x + dir[i][1];
		cur->y = cur->y + *(dir[i]);
		if (collect(map, cur, dir, count))
			return (1);
		cur->x = cur->x - dir[i][1];
		cur->y = cur->y - *(dir[i]);
	}
	return (0);
}

int	backtrack(t_map *map)
{
	t_point		*start;
	t_point		*end;
	t_point		*start_cpy;
	int			**dir;
	static int	count;

	start = get_point(map->map, 'P');
	end = get_point(map->map, 'E');
	start_cpy = get_point(map->map, 'P');
	dir = create_dir_array();
	count = 0;
	if (collect(map, start, dir, &count))
	{
		if(!go_to_exit(map, start_cpy, end, dir))
		{
			ft_putstr(PATH_ERROR);
			//free_nodes(map, start, end, start_cpy);
			return (free_nodes(start, end, start_cpy, dir), 0);
		}
		return (free_nodes(start, end, start_cpy, dir), 1);
	}
	ft_putstr(PATH_ERROR);
	return (free_nodes(start, end, start_cpy, dir), 0);
}
