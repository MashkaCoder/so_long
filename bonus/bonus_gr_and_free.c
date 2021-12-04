/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_gr_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:28:24 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 01:19:54 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_str(t_data *main)
{
	char	*mov;
	char	*moves;

	moves = ft_itoa(main->moves);
	mov = ft_strjoin("Moves: ", moves);
	mlx_string_put(main->mlx, main->win, 0,
		main->height * 39 + 10, 0xFFFFFF, mov);
	free(mov);
	free(moves);
}

void	lose(t_data *main)
{
	mlx_clear_window(main->mlx, main->win);
	mlx_put_image_to_window(main->mlx, main->win, main->graphics->lose,
		main->width * 39 / 2.4, main->height * 39 / 4);
}

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
