/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:53 by hleung            #+#    #+#             */
/*   Updated: 2023/01/18 14:07:36 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static int	**allocate_2d_array(int rows, int cols)
{
	int	**array;
	int	i;

	array = malloc(rows * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(cols * sizeof(int));
		if (!array[i])
		{
			i--;
			while (i >= 0)
			{
				free(array[i]);
				array[i] = NULL;
				i--;
			}
		}
		ft_bzero(array[i], cols);
		i++;
	}
	return (array);
}	

int	**create_dir_array(void)
{
	int	**dir;
	int	i;

	i = 0;
	dir = allocate_2d_array(4, 2);
	if (!dir)
	{
		ft_putstr(MALLOC_ERROR);
		exit(0);
	}
	dir[0][0] = -1;
	dir[0][1] = 0;
	dir[1][0] = 0;
	dir[1][1] = 1;
	dir[2][0] = 1;
	dir[2][1] = 0;
	dir[3][0] = 0;
	dir[3][1] = -1;
	return (dir);
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
		print_message_exit();
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
