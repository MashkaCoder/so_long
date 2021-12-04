/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:54:10 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 22:53:32 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
// #include "../mandatory/so_long.h"

char	*ft_strchr(char const *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && string[i] != (char)symbol)
		i++;
	if (string[i] != (char)symbol)
		return (NULL);
	return (&((char *)string)[i]);
}

char	*ft_strjoin_gnl(char *s1, char *s2, char **s3)
{
	char	*s_res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	s_res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s_res)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		s_res[i] = s1[i];
		i++;
	}
	while (s2 && s2[k] != '\0')
		s_res[i++] = s2[k++];
	s_res[i] = '\0';
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
	return (s_res);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
