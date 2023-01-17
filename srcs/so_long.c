/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:05:14 by hleung            #+#    #+#             */
/*   Updated: 2023/01/17 17:19:11 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/so_long.h"
#include "../includes/libft.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		if (file_type_error(argv[1]) || !file_exist(argv[1]))
			return (1);
		map = parse_map(argv[1]);
		if (!map)
		{
			ft_putstr(PARSE_ERROR);
			return (1);
		}
		if (!check_map_error(map))
			return (1);
		if (!backtrack(map))
			return (1);
		free(map);
		launch_mlx(argv[1]);
	}
	else
		ft_putstr(ARG_ERROR);
	return (0);
}
