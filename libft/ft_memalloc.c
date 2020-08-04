/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:17:00 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/18 22:17:02 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tmp;

	tmp = (void *)malloc(size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
