/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:05:14 by hleung            #+#    #+#             */
/*   Updated: 2023/01/13 11:20:07 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/so_long.h"
#include "includes/libft.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_map_error()
		launch_mlx("assets/maps/map1.ber");
	}
	ft_putstr(ARG_ERROR);
	printf("\n");
	// void	*mlx = mlx_init();
	// int	fd = open("assets/maps/map1.ber", O_RDONLY);
	// void	*mlx_window = mlx_new_window(mlx, 1920, 1080, "So_long");
	// void	*img;
	// //void	*img2;
	// char	relative_path[] = "assets/imgs/sushi.xpm";
	// int		img_width;
	// int		img_height;
	// // int		img_width2;
	// // int		img_height2;
	// char	*line = get_next_line(fd);
	// int		i;


	// //printf("%s", line);
	// i = 0;
	// while (*line == '1')
	// {
	// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// 	mlx_put_image_to_window(mlx, mlx_window, img, i, 0);
	// 	i += 100;
	// 	line++;
	// }
	// //img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width2, &img_height2);
	// //mlx_put_image_to_window(mlx, mlx_window, img2, 100, 0);
	// mlx_loop(mlx);	
}