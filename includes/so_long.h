/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:12:01 by hleung            #+#    #+#             */
/*   Updated: 2023/01/17 08:43:09 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define ARG_ERROR "Error\nWrong number of arguments, exiting program!\n"
# define PARSE_ERROR "Error\nError occurred when parsing map, exiting program!\n"
# define SUFF_ERROR "Error\nInvalid file type!\n"
# define FILE_ERROR "Error\nFile does not exist or no access right!\n"
# define MAP_ERROR "Error\nInvalid map!\n"
# define PATH_ERROR "Error\nNo possible path!\n"
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
	int		*c;
}				t_map;

typedef struct	s_slg
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	*map;
	t_point	*p;
	t_point	*e;
}				t_slg;


//gnl && gnl_utils
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, int c);
char	*get_next_line(int fd);
//map
t_map	*parse_map(char *file_path);
int		count_cols(char *s);
t_point	*get_point(char	**map, char c);
//map_error && map_error_utils
int		file_type_error(char *file_path);
int		file_exist(char *file_path);
int		check_map_error(t_map *map);
//backtrack && backtrack utils
int		**create_dir_array(void);
int		backtrack(t_map *map);
//render
void	launch_mlx(char *file_path);
int		event_listener(int keycode, t_slg *slg);
char	*get_texture_path(t_map *map, int x, int y, char c);
void	render_map(t_slg slg);
#endif
