/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariakorcagina <mariakorcagina@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:16:09 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 05:34:45 by mariakorcag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event_d(t_data *main)
{
	if (main->map[main->pos_y][main->pos_x + 1] != '1')
	{
		if (main->map[main->pos_y][main->pos_x + 1] == 'C')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y][main->pos_x + 1] = 'P';
			main->count_c--;
		}
		else if (main->map[main->pos_y][main->pos_x + 1] == '0')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y][main->pos_x + 1] = 'P';
		}
		else if (main->map[main->pos_y][main->pos_x + 1] == 'E'
			&& main->count_c == 0)
			main->escape_open = 1;
		main->pos_x++;
		main->moves++;
		printf("Moves: %d\n", main->moves);
	}
}	

void	event_a(t_data *main)
{
	if (main->map[main->pos_y][main->pos_x - 1] != '1')
	{
		if (main->map[main->pos_y][main->pos_x - 1] == 'C')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y][main->pos_x - 1] = 'P';
			main->count_c--;
		}
		else if (main->map[main->pos_y][main->pos_x - 1] == '0')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y][main->pos_x - 1] = 'P';
		}
		else if (main->map[main->pos_y][main->pos_x - 1] == 'E'
			&& main->count_c == 0)
			main->escape_open = 1;
		main->pos_x--;
		main->moves++;
		printf("Moves: %d\n", main->moves);
	}
	
}

void	event_w(t_data *main)
{
	if (main->map[main->pos_y - 1][main->pos_x] != '1')
	{
		if (main->map[main->pos_y - 1][main->pos_x] == 'C')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y - 1][main->pos_x] = 'P';
			main->count_c--;
		}
		else if (main->map[main->pos_y - 1][main->pos_x] == '0')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y - 1][main->pos_x] = 'P';
		}
		else if (main->map[main->pos_y - 1][main->pos_x] == 'E'
			 && main->count_c == 0)
			main->escape_open = 1;
		main->pos_y--;
		main->moves++;
		printf("Moves: %d\n", main->moves);
	}
	
}

void	event_s(t_data *main)
{
	if (main->map[main->pos_y + 1][main->pos_x] != '1')
	{
		if (main->map[main->pos_y + 1][main->pos_x] == 'C')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y + 1][main->pos_x] = 'P';
			main->count_c--;
		}
		else if (main->map[main->pos_y + 1][main->pos_x] == '0')
		{
			main->map[main->pos_y][main->pos_x] = '0';
			main->map[main->pos_y + 1][main->pos_x] = 'P';
		}
		else if (main->map[main->pos_y + 1][main->pos_x] == 'E'
			&& main->count_c == 0)
			main->escape_open = 1;
		main->pos_y++;
		main->moves++;
		printf("Moves: %d\n", main->moves);
	}
	
}

int	key_hook(int keycode, t_data *main)
{
	if (keycode == ESC)
		free_all(main);
	else if (keycode == D)
		event_d(main);
	else if (keycode == A)
		event_a(main);
	else if (keycode == S)
		event_s(main);
	else if (keycode == W)
		event_w(main);
}
