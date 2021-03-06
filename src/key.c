/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:42:39 by cseabass          #+#    #+#             */
/*   Updated: 2020/08/06 22:42:40 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press2(int key, t_struct *st)
{
	if (key == 69)
	{
		st->color++;
		if (st->color == 6)
			st->color = 0;
	}
	else if (key == 78)
	{
		st->color--;
		if (st->color == -1)
			st->color = 5;
	}
	get_black(st);
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	return (0);
}

int		key_press1(int key, t_struct *st)
{
	if (key == 89)
	{
		st->c += 0.01;
		st->u += 0.01;
	}
	else if (key == 86)
	{
		st->c -= 0.01;
		st->u -= 0.01;
	}
	else if (key == 91)
	{
		st->c += 0.0001;
		st->u += 0.0001;
	}
	else if (key == 87)
	{
		st->c -= 0.0001;
		st->u -= 0.0001;
	}
	return (key_press2(key, st));
}

int		key_press(int key, void *s)
{
	t_struct *st;

	st = (t_struct *)s;
	if (key == 53)
		exit(0);
	else if (key == 126)
		st->shift_y += 10;
	else if (key == 125)
		st->shift_y -= 10;
	else if (key == 123)
		st->shift_x += 10;
	else if (key == 124)
		st->shift_x -= 10;
	else if (key == 116)
		st->cycle += 5;
	else if (key == 121)
		st->cycle -= 5;
	if (key == 49 && st->move == 1)
		st->move = 0;
	else if (key == 49)
		st->move = 1;
	return (key_press1(key, st));
}
