/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:16:24 by hleung            #+#    #+#             */
/*   Updated: 2023/01/15 07:25:40 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft.h"

int	count_lines(char *file_path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	if (line && line[0] != '\n')
		i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && line[0] != '\n')
			i++;
	}
	free(line);
	close(fd);
	return (i);
}

int	count_cols(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	*count_char(char **map)
{
	int	x;
	int	y;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 256);
	if (!arr)
		return (NULL);
	ft_bzero(arr, 256);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			arr[(int)map[y][x]]++;
			x++;
		}
		y++;
	}
	return (arr);
}

t_map	*parse_map(char *file_path)
{
	t_map	*map;
	int		fd;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->row = count_lines(file_path);
	map->map = malloc(sizeof(char *) * map->row + 1);
	if (!(map->map))
		return (free(map), map = NULL, NULL);
	fd = open(file_path, O_RDONLY);
	map->map[0] = get_next_line(fd);
	i = 0;
	while (++i < map->row)
		map->map[i] = get_next_line(fd);
	map->map[i] = 0;
	map->col = count_cols(map->map[i - 1]);
	map->c = count_char(map->map);
	if (!map->c)
		return (free(map->map), free(map), map->map = NULL, map = NULL, NULL);
	close(fd);
	return (map);
}

t_point	*get_point(char	**map, char c)
{
	t_point	*point;
	int		x;
	int		y;

	x = 0;
	y = 0;
	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	while (map[y])
	{
		while (map[y][x] != 0 && map[y][x] != '\n')
		{
			if (map[y][x] == c)
			{
				point->x = x;
				point->y = y;
				return (point);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}
