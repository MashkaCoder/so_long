/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:43:00 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 22:31:49 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization_grap(t_data *main)
{
	int	img_height;
	int	img_weight;

	main->graphics = malloc(sizeof(t_gr));
	main->graphics->collect = mlx_xpm_file_to_image(main->mlx, COLLECT,
			&img_height, &img_weight);
	main->graphics->wall = mlx_xpm_file_to_image(main->mlx, WALL,
			&img_weight, &img_height);
	main->graphics->space = mlx_xpm_file_to_image(main->mlx, SPACE,
			&img_weight, &img_height);
	main->graphics->exit_c = mlx_xpm_file_to_image(main->mlx, EXIT_C,
			&img_weight, &img_height);
	main->graphics->win = mlx_xpm_file_to_image(main->mlx, WIN,
			&img_weight, &img_height);
	main->graphics->player_a = mlx_xpm_file_to_image(main->mlx, PLAYER_A,
			&img_weight, &img_height);
}

void	initialization_main(t_data *main)
{
	main->height = 0;
	main->width = 0;
	main->count_c = 0;
	main->pos_x = 0;
	main->pos_y = 0;
	main->moves = 0;
	main->player_c = 0;
	main->escape_open = 0;
	initialization_grap(main);
}
