/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:20:27 by hleung            #+#    #+#             */
/*   Updated: 2022/12/22 12:28:44 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen_line(char *str);
char	*ft_get_line(char *str);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
#endif
