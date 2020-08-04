/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:01:24 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/20 21:01:26 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		length(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*a;
	int		len;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = length(n);
	tmp = n;
	if (!(a = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		n = n * (-1);
	}
	a[len] = '\0';
	while (n > 0)
	{
		len--;
		a[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}
