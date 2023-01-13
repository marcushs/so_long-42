/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:08:50 by hleung            #+#    #+#             */
/*   Updated: 2023/01/13 12:18:51 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft.h"

static int	file_path_error(char *file_path)
{
	char	*substr;

	substr = ft_substr(ft_strrchr(file_path, '.'), 0, 4);
	if (!substr)
	{
		ft_putstr(SUFF_ERROR);
		return (1);
	}
	if (ft_strncmp(substr, ".ber", 4))
	{
		ft_putstr(SUFF_ERROR);
		return (1);
	}
	return (0);
}

static int	file_exist(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(FILE_ERROR);
		return (0);
	}
	close(fd);
	return (1);
}

static int	check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y])
	{
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if (map->map[y][x] != '1' && \
			(y == 0 || y == map->row -1 || x == 0 || x == map->col - 1))
			{
				ft_putstr(MAP_ERROR);
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

static int	check_shape(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = count_cols(map[i]);
	i = 1;
	while (map[i])
	{
		if (len != count_cols(map[i]))
		{
			ft_putstr(MAP_ERROR);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_error(char *file_path)
{
	t_map	*map;
	int		*arr;

	arr = malloc(sizeof(int) * 256);
	if (file_path_error(file_path))
		return (0);
	if (!file_exist(file_path))
		return (0);
	map = parse_map(file_path);
	if (!check_shape(map->map))
		return (0);
	if (!check_wall(map))
		return (0);
	// if (!check_char(map->map, "01CEP"))
	// 	return (0);
	// if (map->c_count < 1 || count_char(map, 'P') != 1 || \
	// 	count_char(map, 'E') != 1)
	// {
	// 	ft_putstr(MAP_ERROR);
	// 	return (0);
	// }
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argc;

	check_map_error(argv[1]);
	printf("\n");
	return (0);
}
	// map = parse_map(file_path);
	// if (!map)
	// {
	// 	ft_putstr(PARSE_ERROR);
	// 	return (0);
	// }