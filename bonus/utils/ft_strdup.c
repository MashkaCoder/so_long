/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:13:30 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 22:59:28 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
// #include "../mandatory/so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*s2_start;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (s1_len + 1));
	s2_start = s2;
	if (!s2)
		return (NULL);
	while (*s1 != '\0')
	{
		*s2 = *s1;
		s1++;
		s2++;
	}
	*s2 = '\0';
	return (s2_start);
}
