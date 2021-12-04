/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:13:34 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 22:59:35 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	s_res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s_res)
		return (NULL);
	while (s1[i] != '\0')
	{
		s_res[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		s_res[i] = s2[k];
		i++;
		k++;
	}
	s_res[i] = '\0';
	return (s_res);
}
