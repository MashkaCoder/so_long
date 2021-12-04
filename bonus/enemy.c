/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:46:54 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 00:57:02 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_to_r(t_data *main, char c, int *i, int *j)
{
	if (main->map[*j][(*i) + 1] != '1' && main->map[*j][(*i) + 1] != 'E'
		&& main->map[*j][(*i) + 1] != 'C' && main->map[*j][(*i) + 1] != 'X')
	{
		if (main->map[*j][(*i) + 1] == 'P')
		{
			main->player_c = 0;
			return ;
		}
		main->map[*j][*i] = '0';
		main->map[*j][(*i) + 1] = 'X';
		++(*i);
	}
}

void	enemy_to_l(t_data *main, char c, int *i, int *j)
{
	if (main->map[*j][(*i) - 1] != '1' && main->map[*j][(*i) - 1] != 'E'
		&& main->map[*j][(*i) - 1] != 'C' && main->map[*j][(*i) - 1] != 'X')
	{
		if (main->map[*j][(*i) - 1] == 'P')
		{
			main->player_c = 0;
			return ;
		}
		main->map[*j][*i] = '0';
		main->map[*j][(*i) - 1] = 'X';
		--(*i);
	}
}

void	search_enemy_for_mov(t_data *main, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (main->map[j])
	{
		while (main->map[j][i])
		{
			if (main->map[j][i] == 'X' && c == 'r')
				enemy_to_r(main, c, &i, &j);
			if (main->map[j][i] == 'X' && c == 'l')
				enemy_to_l(main, c, &i, &j);
			i++;
		}
		i = 0, j++;
	}
}

void	mov_en(t_data *main)
{
	static int	t;

	if (t == 20)
	{
		search_enemy_for_mov(main, 'r');
		main->enemy_frame = 2;
	}
	if (t == 40)
	{
		search_enemy_for_mov(main, 'l');
		main->enemy_frame = 3;
	}
	if (t == 100)
		main->enemy_frame = 5;
	if (t == 120)
		main->enemy_frame = 6;
	t++;
	if (t > 120)
		t = 0;
}
