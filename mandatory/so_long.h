/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:58:51 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 01:22:03 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 2

# define WALL "./graphics/wall.xpm"
# define SPACE "./graphics/space.xpm"
# define PLAYER_A "./graphics/pl_a.xpm"
# define EXIT_C "./graphics/close_door.xpm"
# define COLLECT "./graphics/coin.xpm"
# define WIN "./graphics/win.xpm"
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_gr
{
	void	*wall;
	void	*space;
	void	*collect;
	void	*exit_c;
	void	*player_a;
	void	*win;
}			t_gr;

typedef struct s_data
{
	int		pos_x;
	int		pos_y;
	int		moves;
	int		escape_open;
	int		count_c;
	int		player_c;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	char	**map;
	t_gr	*graphics;
}			t_data;

//gnl
int		get_next_line(int fd, char **line);
char	*ft_strchr(char const *string, int symbol);
char	*ft_strjoin_gnl(char *s1, char *s2, char **s3);
size_t	ft_strlen(const char *s);

// liba
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

//so_long
void	initialization_main(t_data *main);
void	check_rectangular(t_data *map);
void	check_extension(char *argv_1, char *ber);
void	check_char(t_data *main);
void	check_min_set(t_data *main, int i, int j);
void	check_wall(t_data *main);
void	draw_map(t_data *main);
int		key_hook(int keycode, t_data *main);
int		check_unit(char	*str);
void	win(t_data *main);
int		free_all(t_data *main);

#endif
