/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:37:54 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/20 15:37:59 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +
			1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		d[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		d[i + j] = s2[j];
		j++;
	}
	d[i + j] = '\0';
	return (d);
}
