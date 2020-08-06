/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:42:20 by cseabass          #+#    #+#             */
/*   Updated: 2020/08/06 22:42:23 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_put1(int b, int x, int y, t_struct *st)
{
	if (b == 5)
	{
		st->h /= 1.1;
		st->w /= 1.1;
		st->shift_x -= st->width / 2 - x;
		st->shift_y -= st->heigth / 2 - y;
		st->shift_x /= 1.1;
		st->shift_y /= 1.1;
		st->shift_x += st->width / 2 - x;
		st->shift_y += st->heigth / 2 - y;
	}
	get_black(st);
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	return (0);
}

int		mouse_put(int b, int x, int y, void *s)
{
	t_struct *st;

	st = (t_struct *)s;
	if (x < 0 || y < 0 || x > st->width || y > st->heigth)
		return (0);
	if (b == 4)
	{
		st->h *= 1.1;
		st->w *= 1.1;
		st->shift_x -= st->width / 2 - x;
		st->shift_y -= st->heigth / 2 - y;
		st->shift_x *= 1.1;
		st->shift_y *= 1.1;
		st->shift_x += st->width / 2 - x;
		st->shift_y += st->heigth / 2 - y;
	}
	return (mouse_put1(b, x, y, st));
}

int		mouse_move(int x, int y, void *s)
{
	t_struct *st;

	st = (t_struct *)s;
	if (!(st->move))
		return (0);
	st->c = ((float)x - st->width / 2) / (st->width / 2);
	st->u = ((float)y - st->heigth / 2) / (st->heigth / 2);
	get_black(st);
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	return (0);
}

void	error(void)
{
	ft_putstr("Error\n");
	exit(0);
}
