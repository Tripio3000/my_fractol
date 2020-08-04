/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:13:28 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/16 23:54:52 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len_dst;
	size_t len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		return (len_src + size);
	while (dst[i] && i < (size - 1))
		i++;
	while (*src && i < (size - 1))
		dst[i++] = *src++;
	dst[i] = '\0';
	return (len_dst + len_src);
}
