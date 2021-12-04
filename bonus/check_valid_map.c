/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:42:34 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/04 00:58:14 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_extension(char *argv_1, char *ber)
{
	char	*extension;
	char	*copy;
	int		len_copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = ft_strdup(argv_1);
	len_copy = ft_strlen(copy);
	while (copy[i] != '.')
		i++;
	i++;
	extension = malloc(sizeof(char) * (len_copy - i + 1));
	while (copy[i])
		extension[j++] = copy[i++];
	extension[j] = '\0';
	if ((ft_strlen(ber) != ft_strlen(extension))
		|| ft_strncmp(ber, extension, 3))
	{
		printf("Error\nWrong extension\n");
		exit(EXIT_FAILURE);
	}
	free(copy);
	free(extension);
}

void	check_rectangular(t_data *main)
{
	int	j;
	int	len;

	j = 0;
	len = (int)ft_strlen(main->map[0]);
	while (main->map[j])
	{
		if (len != (int)ft_strlen(main->map[j]))
		{
			printf("Error\nThe map isn't rectangular\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	main->width = len;
}

void	check_char(t_data *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (main->map[j])
	{
		while (main->map[j][i])
		{
			if (main->map[j][i] == 'P' || main->map[j][i] == 'E'
				|| main->map[j][i] == '1' || main->map[j][i] == 'C'
				|| main->map[j][i] == '0' || main->map[j][i] == 'X')
				i++;
			else
			{
				printf("Error\nExtra char\n");
				exit(EXIT_FAILURE);
			}
		}
		i = 0;
		j++;
	}
}

void	check_min_set(t_data *main, int i, int j)
{
	int	E;

	E = 0;
	while (main->map[j])
	{
		while (main->map[j][i])
		{
			if (main->map[j][i] == 'P')
				main->player_c++;
			if (main->map[j][i] == 'E')
				E++;
			if (main->map[j][i] == 'C')
				main->count_c++;
			i++;
		}
		i = 0, j++;
	}
	if (main->count_c == 0 || main->player_c == 0
		|| E == 0 || main->player_c > 1)
		printf("Error\nWrong set of char\n"), exit(EXIT_FAILURE);
}

void	check_wall(t_data *main)
{
	int	i;
	int	j;
	int	len;
	int	error;

	i = 0;
	j = 1;
	error = 0;
	len = ft_strlen(main->map[0]);
	error += check_unit(main->map[0]);
	while (j < main->height - 1)
	{
		if (main->map[j][0] != '1' || main->map[j][len - 1] != '1')
			error++;
		j++;
	}
	error += check_unit(main->map[main->height - 1]);
	if (error > 0)
	{
		printf("Error\nThe map isn't surrounded by walls\n");
		exit(EXIT_FAILURE);
	}
}
