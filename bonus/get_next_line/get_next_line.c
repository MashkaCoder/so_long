/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:54:05 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 22:53:44 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
// #include "../mandatory/so_long.h"

int	remains_n(char **remains, char **line)
{
	int	i;
	int	len;

	i = 0;
	if (!*remains)
		return (0);
	len = ft_strlen(*remains);
	while ((*remains)[i] != '\0' && (*remains)[i] != '\n')
		i++;
	if (i < len)
	{
		(*remains)[i] = '\0';
		*line = ft_strjoin_gnl(NULL, *remains, NULL);
		*remains = ft_strjoin_gnl(NULL, (*remains) + i + 1, remains);
		return (1);
	}
	return (0);
}

int	buf_check(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	return (i);
}

int	read_file(int fd, char *buf, char **line, ssize_t len)
{
	static char	*remains;
	int			k;
	int			i;

	k = remains_n(&remains, line);
	while (!k && len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
			return (-1);
		buf[len] = '\0';
		i = buf_check(buf);
		if (i < len)
		{
			*line = ft_strjoin_gnl(remains, buf, NULL);
			remains = ft_strjoin_gnl(NULL, buf + i + 1, &remains);
			k = 1;
		}
		else if (len == 0)
			*line = ft_strjoin_gnl(NULL, remains, &remains);
		else
			remains = ft_strjoin_gnl(remains, buf, &remains);
	}
	free (buf);
	return (k);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		k;
	ssize_t	len;

	k = 0;
	len = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	k = read_file(fd, buf, line, len);
	if (k < 0)
		free(buf);
	return (k);
}
