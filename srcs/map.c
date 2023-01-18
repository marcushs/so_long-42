/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:16:24 by hleung            #+#    #+#             */
/*   Updated: 2023/01/18 14:11:41 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static int	count_lines(char *file_path)
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

static int	*count_char(t_map *map)
{
	int	x;
	int	y;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 256);
	if (!arr)
	{
		free_2d_array(map->map);
		free(map);
		map = NULL;
		print_message_exit();
	}
	ft_bzero(arr, sizeof(int) * 256);
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			arr[(int)map->map[y][x]]++;
			x++;
		}
		y++;
	}
	return (arr);
}

t_map	*make_map(char *file_path)
{
	t_map	*map;
	int		fd;
	int		i;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->row = count_lines(file_path);
	map->map = malloc(sizeof(char *) * (map->row + 1));
	if (!(map->map))
		return (free(map), map = NULL, NULL);
	fd = open(file_path, O_RDONLY);
	map->map[0] = get_next_line(fd);
	i = 0;
	while (++i < map->row)
		map->map[i] = get_next_line(fd);
	map->map[i] = 0;
	map->col = count_cols(map->map[i - 1]);
	map->c = count_char(map);
	if (!map->c)
		return (free_2d_array(map->map), free(map), map = NULL, NULL);
	close(fd);
	return (map);
}

char	**parse_map(char *file_path, int row)
{
	char	**map;
	int		fd;
	int		i;
	
	map = malloc(sizeof(char *) * (row + 1));
	if (!map)
		print_message_exit();
	fd = open(file_path, O_RDONLY);
	map[0] = get_next_line(fd);
	if (!map[0])
		print_message_exit();
	i = 0;
	while (++i < row)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			while (--i >= 0)
			{
				free(map[i]);
				map[i] = NULL;
				print_message_exit();
			}
		}	
	}
	map[i] = 0;
	close(fd);
	return (map);
}