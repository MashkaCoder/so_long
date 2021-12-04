/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:13:25 by chasimir          #+#    #+#             */
/*   Updated: 2021/12/03 23:00:08 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../bonus/so_long_bonus.h"
#include "../so_long.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*convert(char *res, int n, int len_n, int minus)
{
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	res[len_n] = '\0';
	while (n != 0)
	{
		res[len_n - 1] = n % 10 * minus + 48;
		n = n / 10;
		len_n--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		minus;
	char	*res;
	int		len_n;

	minus = 1;
	len_n = int_len(n);
	if (n < 0)
	{
		minus = -minus;
		len_n++;
	}
	res = (char *)malloc(sizeof(char) * (len_n + 1));
	if (!res)
		return (NULL);
	res = convert(res, n, len_n, minus);
	return (res);
}
