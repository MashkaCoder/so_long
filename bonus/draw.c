/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:14:43 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 23:05:31 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_en(t_data *main, int *i, int *j)
{
	if (main->map[*j][*i] == 'X')
	{
		if (main->enemy_frame == 1)
			mlx_put_image_to_window(main->mlx, main->win,
				main->graphics->enemy_1, (*i) * 39, (*j) * 39);
		if (main->enemy_frame == 2)
			mlx_put_image_to_window(main->mlx, main->win,
				main->graphics->enemy_2, (*i) * 39, (*j) * 39);
		if (main->enemy_frame == 3)
			mlx_put_image_to_window(main->mlx, main->win,
				main->graphics->enemy_3, (*i) * 39, (*j) * 39);
		if (main->enemy_frame == 4)
			mlx_put_image_to_window(main->mlx, main->win,
				main->graphics->enemy_4, (*i) * 39, (*j) * 39);
		if (main->enemy_frame == 5)
			mlx_put_image_to_window(main->mlx, main->win,
				main->graphics->enemy_5, (*i) * 39, (*j) * 39);
		if (main->enemy_frame == 6)
			mlx_put_image_to_window(main->mlx, main->win,
				main->graphics->enemy_6, (*i) * 39, (*j) * 39);
	}
}

void	draw_player(t_data *main, int *i, int *j)
{
	if (main->player_dir == 'a')
		mlx_put_image_to_window(main->mlx, main->win, main->graphics->player_a,
			(*i) * 39, (*j) * 39);
	else if (main->player_dir == 'd')
		mlx_put_image_to_window(main->mlx, main->win, main->graphics->player_d,
			(*i) * 39, (*j) * 39);
	if (main->player_dir == 's')
		mlx_put_image_to_window(main->mlx, main->win, main->graphics->player_s,
			(*i) * 39, (*j) * 39);
	if (main->player_dir == 'w')
		mlx_put_image_to_window(main->mlx, main->win, main->graphics->player_w,
			(*i) * 39, (*j) * 39);
	main->pos_x = *i;
	main->pos_y = *j;
}

void	draw_exit(t_data *main, int *i, int *j)
{
	if (main->count_c > 0)
		mlx_put_image_to_window(main->mlx, main->win, main->graphics->exit_c,
			(*i) * 39, (*j) * 39);
	else
		mlx_put_image_to_window(main->mlx, main->win, main->graphics->exit_o,
			(*i) * 39, (*j) * 39);
}

void	draw_wall(t_data *main, int *i, int *j)
{
	if (main->map[*j][*i] == '1')
		mlx_put_image_to_window(main->mlx, main->win, main->graphics->wall,
			(*i) * 39, (*j) * 39);
}

void	draw_map(t_data *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (main->map[j])
	{
		while (main->map[j][i])
		{
			draw_wall(main, &i, &j);
			draw_en(main, &i, &j);
			if (main->map[j][i] == '0')
				mlx_put_image_to_window(main->mlx, main->win,
					main->graphics->space, i * 39, j * 39);
			if (main->map[j][i] == 'E')
				draw_exit(main, &i, &j);
			if (main->map[j][i] == 'C')
				mlx_put_image_to_window(main->mlx, main->win,
					main->graphics->collect, i * 39, j * 39);
			if (main->map[j][i] == 'P')
				draw_player(main, &i, &j);
			i++;
		}
		i = 0, j++;
	}
}
