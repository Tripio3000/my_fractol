/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:42:47 by cseabass          #+#    #+#             */
/*   Updated: 2020/08/06 22:42:49 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color2(t_struct *st, int red, int green, int blue)
{
	if (st->color == 4)
	{
		red = (int)(9 * (1 - st->tmp) * pow(st->tmp, 3) * 255);
		green = (int)(15 * pow((1 - st->tmp), 2) * pow(st->tmp, 2) * 255);
		blue = (int)(8.5 * pow((1 - st->tmp), 3) * st->tmp * 255);
	}
	else if (st->color == 5)
	{
		red = (int)(12 * (1 - st->tmp) * 255);
		green = (int)(5 * pow((1 - st->tmp), 2) * 255);
		blue = (int)(20 * pow((1 - st->tmp), 3) * 255);
	}
	return (red << 16 | green << 8 | blue);
}

int		color1(t_struct *st, int red, int green, int blue)
{
	if (st->color == 2)
	{
		red = (int)(50 * (1 - st->tmp) * 255);
		green = (int)(100 * 1 / pow(2, st->tmp) * 255);
		blue = (int)(50 * 1 / (st->tmp + 200) * 255);
	}
	else if (st->color == 3)
	{
		red = (int)(50 * (1 - st->tmp) * 255);
		green = (int)(100 * 1 / (st->tmp + 200) * 255);
		blue = 0xFF - (int)(50 * 1 / (st->tmp + 200) * 55);
	}
	return (color2(st, red, green, blue));
}

int		color(t_struct *st, int i)
{
	int			red;
	int			green;
	int			blue;

	red = 0;
	green = 0;
	blue = 0;
	st->tmp = (long double)i / (long double)st->cycle;
	if (st->color == 0)
	{
		red = (int)(9 * (1 - st->tmp) * pow(st->tmp, 3) * 255);
		green = (int)(15 * pow((1 - st->tmp), 2) * pow(st->tmp, 2) * 255);
		blue = 0xFF - (int)(8.5 * pow((1 - st->tmp), 3) * st->tmp * 255);
	}
	else if (st->color == 1)
	{
		red = (int)(5 * (1 - st->tmp) * 255);
		green = (int)(5 * (1 - st->tmp) * 255);
		blue = (int)(5 * (1 - st->tmp) * 255);
	}
	return (color1(st, red, green, blue));
}
