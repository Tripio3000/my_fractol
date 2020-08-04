/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:04:31 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/19 22:04:34 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
