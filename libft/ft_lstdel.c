/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:19:54 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/22 19:19:56 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;
	t_list	*j;

	if (!alst || !del)
		return ;
	i = *alst;
	while (i)
	{
		j = i->next;
		ft_lstdelone(&i, del);
		i = j;
	}
	(*alst) = NULL;
}
