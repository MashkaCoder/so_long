/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:14:43 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 22:43:22 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_data *main, int *i, int *j)
{
	mlx_put_image_to_window(main->mlx, main->win, main->graphics->player_a,
		(*i) * 39, (*j) * 39);
	main->pos_x = *i;
	main->pos_y = *j;
}

void	draw_exit(t_data *main, int *i, int *j)
{
	mlx_put_image_to_window(main->mlx, main->win, main->graphics->exit_c,
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
