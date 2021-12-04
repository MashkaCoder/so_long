/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:43:21 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 01:20:52 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_height(char *map, t_data *main)
{
	int		fd;
	int		n;
	char	*line;

	n = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Wrong file\n");
		exit(EXIT_FAILURE);
	}
	while (n > 0)
	{
		n = get_next_line(fd, &line);
		if (n != 0)
			main->height++;
		free(line);
	}
	close(fd);
}

void	map_create(char *map_ber, t_data *main)
{
	char	*line;
	int		fd;
	int		n;
	int		i;

	i = 0;
	n = 1;
	line = NULL;
	map_height(map_ber, main);
	fd = open(map_ber, O_RDONLY);
	main->map = malloc((main->height + 1) * sizeof(*(main->map)));
	if (!main->map)
		exit(EXIT_FAILURE);
	while (n > 0)
	{
		line = NULL;
		n = get_next_line(fd, &line);
		if (n != 0)
			main->map[i++] = line;
	}
	main->map[i] = NULL;
	close(fd);
	free(line);
}

void	check_map(char *argv_1, t_data *main)
{
	check_extension(argv_1, "ber");
	check_rectangular(main);
	check_char(main);
	check_min_set(main, 0, 0);
	check_wall(main);
}

int	render_frame(t_data *main)
{
	mlx_clear_window(main->mlx, main->win);
	if (main->player_c == 1)
	{
		print_str(main);
		mov_en(main);
		draw_map(main);
	}
	if (main->player_c == 0)
		lose(main);
	if (main->count_c == 0 && main->player_c == 1 && main->escape_open == 1)
		win(main);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*main;

	if (argc == 2)
	{
		main = malloc(sizeof(t_data));
		main->mlx = mlx_init();
		initialization_main(main);
		map_create(argv[1], main);
		check_map(argv[1], main);
		main->win = mlx_new_window(main->mlx, main->width * 39,
				main->height * 39 + 15, "so_long");
		mlx_hook(main->win, 17, 0, free_all, main);
		mlx_hook(main->win, 02, 0, key_hook, main);
		mlx_loop_hook(main->mlx, render_frame, main);
		mlx_loop(main->mlx);
	}
}
