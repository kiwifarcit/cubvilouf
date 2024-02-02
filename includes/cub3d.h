/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velbling <velbling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:32:51 by velbling          #+#    #+#             */
/*   Updated: 2024/01/16 16:50:28 by velbling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <../MLX42/include/MLX42/MLX42.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_map
{
	int		x;
	int		y;
	int		x_size;
	int		y_size;
	char	**map;
}	t_map;

typedef struct	s_player
{
	float	x_pos;
	float	y_pos;
	double	angle;	
}	t_player;

typedef struct	s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_player	*player;
	int		argc;
	char	**argv;
}	t_game;

char	*get_next_line(int fd);
void	map(t_game *game);
size_t	ft_strlen(char const *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

# define WIDTH 960
# define HEIGHT 720
# define FOV 60

#endif