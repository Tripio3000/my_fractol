/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:42:12 by cseabass          #+#    #+#             */
/*   Updated: 2020/08/06 22:42:14 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	formulas(t_struct *st, long double *x, long double *y, long double tmp)
{
	if (st->f == 1)
	{
		tmp = *x * *x - *y * *y + st->x0 + st->c;
		*y = 2 * *x * *y + st->y0 + st->u;
		*x = tmp;
	}
	else if (st->f == 2)
	{
		tmp = *x * *x - *y * *y + st->c;
		*y = 2 * *x * *y + st->u;
		*x = tmp;
	}
	else if (st->f == 3)
	{
		tmp = *x * (*x * *x - 3 * (*y * *y)) + st->c;
		*y = *y * (3 * (*x * *x) - *y * *y) + st->u;
		*x = tmp;
	}
	else if (st->f == 4)
	{
		tmp = *x * (*x * *x - 3 * (*y * *y)) + st->x0 + st->c;
		*y = *y * (3 * (*x * *x) - *y * *y) + st->y0 + st->u;
		*x = tmp;
	}
}

int		calc_pixel(t_struct *st, long double x, long double y)
{
	int			i;
	long double	r;

	i = 0;
	r = 2;
	x = x / (st->w / 2 / r);
	y = y / (st->h / 2 / r);
	st->x0 = x;
	st->y0 = y;
	while (i < st->cycle && x * x + y * y < r * r)
	{
		formulas(st, &x, &y, st->t);
		i++;
	}
	if (i == st->cycle)
		return (0);
	return (color(st, i));
}

void	*fractal(void *s)
{
	int			i;
	int			j;
	t_struct	*st;

	st = (t_struct*)s;
	j = -st->heigth / 2 + st->str * st->heigth / st->pot;
	while (j < -st->heigth / 2 + (st->str + 1) * st->heigth / st->pot)
	{
		i = -st->width / 2;
		while (i < st->width / 2)
		{
			st->data[(j + st->heigth / 2) * st->width + (i + st->width / 2)] =
					calc_pixel(st, (long double)i + st->shift_x,
							(long double)j + st->shift_y);
			i++;
		}
		j++;
	}
	return (0);
}

void	threads(t_struct *data)
{
	t_struct		lst[data->pot];
	pthread_t		threads[data->pot];
	pthread_attr_t	attr;
	void			*status;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	data->str = -1;
	while (++(data->str) < data->pot)
	{
		ft_memcpy((void*)&lst[data->str], (void *)data, sizeof(t_struct));
		pthread_create(&threads[data->str],
							NULL, fractal, (void *)(&lst[data->str]));
	}
	pthread_attr_destroy(&attr);
	data->str = -1;
	while (++(data->str) < data->pot)
		pthread_join(threads[data->str], &status);
}

int		main(int ac, char **av)
{
	t_struct *st;

	if (!(st = malloc(sizeof(t_struct))))
		error();
	st->mlx = mlx_init();
	st_init(st);
	check(ac, av, st);
	st->win = mlx_new_window(st->mlx, WIDTH, HEIGHT, "Fract'ol");
	st->img = mlx_new_image(st->mlx, WIDTH, HEIGHT);
	mlx_hook(st->win, 2, 0, key_press, (void *)st);
	mlx_hook(st->win, 6, 0, mouse_move, (void *)st);
	mlx_hook(st->win, 4, 0, mouse_put, (void *)st);
	st->data = (int *)mlx_get_data_addr(st->img,
			&(st->n0), &(st->n1), &(st->n2));
	threads(st);
	instr();
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	mlx_loop(st->mlx);
	return (0);
}
