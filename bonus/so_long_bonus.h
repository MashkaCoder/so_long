/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:58:51 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 01:20:28 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define BUFFER_SIZE 2

# define WALL "./graphics/wall.xpm"
# define SPACE "./graphics/space.xpm"
# define PLAYER_A "./graphics/pl_a.xpm"
# define PLAYER_D "./graphics/pl_d.xpm"
# define PLAYER_S "./graphics/pl_s.xpm"
# define PLAYER_W "./graphics/pl_w.xpm"
# define EXIT_C "./graphics/close_door.xpm"
# define EXIT_O "./graphics/open_door.xpm"
# define COLLECT "./graphics/coin.xpm"
# define ENEMY_1 "./graphics/en1.xpm"
# define ENEMY_2 "./graphics/en2.xpm"
# define ENEMY_3 "./graphics/en3.xpm"
# define ENEMY_4 "./graphics/en4.xpm"
# define ENEMY_5 "./graphics/en5.xpm"
# define ENEMY_6 "./graphics/en6.xpm"
# define LOSE "./graphics/lose.xpm"
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
	void	*exit_o;
	void	*player_a;
	void	*player_d;
	void	*player_w;
	void	*player_s;
	void	*enemy_1;
	void	*enemy_2;
	void	*enemy_3;
	void	*enemy_4;
	void	*enemy_5;
	void	*enemy_6;
	void	*win;
	void	*lose;
}			t_gr;

typedef struct s_data
{
	int		escape_open;
	int		pos_x;
	int		pos_y;
	int		moves;
	int		enemy_frame;
	int		count_c;
	int		player_c;
	char	player_dir;
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
void	check_rectangular(t_data *map); //?
void	check_extension(char *argv_1, char *ber); //
void	mov_en(t_data *main);
void	check_char(t_data *main);//
void	check_min_set(t_data *main, int i, int j);//
void	check_wall(t_data *main);//
void	draw_map(t_data *main); //
int		key_hook(int keycode, t_data *main);
int		check_unit(char	*str);
void	win(t_data *main);
void	lose(t_data *main);
int		free_all(t_data *main);
void	print_str(t_data *main);

#endif
