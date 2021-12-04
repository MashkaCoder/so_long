/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:43:06 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 21:09:50 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_unit(char	*str)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (str[i])
	{
		if (str[i] != '1')
			error++;
		i++;
	}
	return (error);
}
