/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:58:51 by hleung            #+#    #+#             */
/*   Updated: 2023/01/18 14:12:34 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long.h"
#include "../includes/libft.h"

void	print_message_exit(void)
{
	ft_putstr(MALLOC_ERROR);
	exit(0);
}

void	free()

void	free_2d_array(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_map(t_map *map)
{
	free_2d_array(map->map);
	free(map->c);
	map->c = NULL;
	free(map);
	map = NULL;
}

void	free_everyting(t_slg slg)
{
	free_map(slg.map);
	free(slg.p);
	slg.p = NULL;
	free(slg.e);
	slg.e = NULL;
}
