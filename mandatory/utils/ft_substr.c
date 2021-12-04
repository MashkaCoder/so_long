/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:13:41 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 23:00:43 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((const char *)s) < start)
		return (ft_strdup(""));
	if (ft_strlen((const char *)s) - start < len)
		len = ft_strlen((const char *)s) - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s[i] != '\0' && i != start)
		i++;
	while (k < len)
	{
		s2[k] = s[i];
		k++;
		i++;
	}
	s2[k] = '\0';
	return (s2);
}
