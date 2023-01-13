/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:47:53 by hleung            #+#    #+#             */
/*   Updated: 2023/01/13 12:26:35 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft.h"

int	**allocate_2D_array(int rows, int cols)
{
	int	**array;
	int	i;
	
	array = malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		array[i] = malloc(cols * sizeof(int));
		ft_bzero(array[i], cols);
		i++;
	}
	return (array);
}	

int	**create_dir_array()
{
	int	**dir;

	dir = allocate_2D_array(4, 2);
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