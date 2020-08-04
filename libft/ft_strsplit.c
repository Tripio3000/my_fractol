/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:48:18 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/20 17:48:20 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numwor(char const *s, int k, char c)
{
	int	i;

	i = 0;
	while (s[k] != c && s[k])
	{
		k++;
		i++;
	}
	return (i);
}

static int		numstr(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static void		*delete(char **dst, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_strdel(&dst[j]);
	}
	ft_memdel((void **)&dst);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		i;
	int		k;
	int		j;

	if (!s)
		return (NULL);
	if (!(dst = (char **)malloc(sizeof(char *) * numstr(s, c) + 1)))
		return (NULL);
	k = 0;
	i = 0;
	while (i < numstr(s, c))
	{
		j = 0;
		while (s[k] == c && s[k])
			k++;
		if (!(dst[i] = (char *)malloc(sizeof(char) * numwor(s, k, c) + 1)))
			return (delete(dst, i));
		while (s[k] != c && s[k])
			dst[i][j++] = s[k++];
		dst[i][j] = '\0';
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
