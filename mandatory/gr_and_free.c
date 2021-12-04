/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_and_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:28:24 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 01:21:51 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_data *main)
{
	mlx_clear_window(main->mlx, main->win);
	mlx_put_image_to_window(main->mlx, main->win, main->graphics->win,
		main->width * 39 / 2.4, main->height * 39 / 4);
}

int	free_all(t_data *main)
{
	exit(EXIT_SUCCESS);
}
