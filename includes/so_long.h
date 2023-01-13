/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:12:01 by hleung            #+#    #+#             */
/*   Updated: 2023/01/13 12:17:18 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define ARG_ERROR "Error\nWrong number of arguments, exiting program!"
# define SUFF_ERROR "Error\nInvalid file type!"
# define FILE_ERROR "Error\nFile does not exist or no access right!"
# define MAP_ERROR "Error\nInvalid map!"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_map
{
	char	**map;
	int		row;
	int		col;
	int		c_count;
}				t_map;

//gnl && gnl_utils
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, int c);
char	*get_next_line(int fd);
//map
t_map	*parse_map(char *file_path);
int		count_line(char *file_path);
int		count_cols(char *s);
int		count_char(t_map *map, char c, int *arr);
t_point	*get_point(char	**map, char c);
//map_error && map_error_utils

//backtrack && backtrack utils
int		**allocate_2D_array(int rows, int cols);
int		**create_dir_array();
int		backtrack(t_map *map, t_point *start, t_point *end, int **dir);
//render
void	launch_mlx(char *file_path);
#endif