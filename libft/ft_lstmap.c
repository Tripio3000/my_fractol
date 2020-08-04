/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:26:27 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/22 20:26:31 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (!lst || !f)
		return (NULL);
	a = lst;
	b = f(a);
	c = b;
	while (a->next)
	{
		b->next = f(a->next);
		a = a->next;
		b = b->next;
	}
	return (c);
}
