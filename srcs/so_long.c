/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcus <marcus@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:05:14 by hleung            #+#    #+#             */
/*   Updated: 2023/01/19 19:43:55 by marcus           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long.h"
#include "../includes/libft.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_slg	slg;

	if (argc == 2)
	{
		if (file_type_error(argv[1]) || !file_exist(argv[1]))
			return (1);
		map = make_map(argv[1]);
		if (!map)
		if (!check_map_error(map) || !backtrack(map))
		{
			free_map(&map);
			return (1);
		}
		free_map(&map);
		slg = launch_mlx(argv[1]);
		return (free_everyting(&slg), 0);
	}
	else
		ft_putstr(ARG_ERROR);
	return (0);
}
