#include "fractol.h"

void 	error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

int 	color(t_struct *st, int i)
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
		red = (int)(12 * (1 - st->tmp) * 255);
		green = (int)(5 * pow((1 - st->tmp), 2) * 255);
		blue = (int)(20 * pow((1 - st->tmp), 3) * 255);
	}
	return (red << 16 | green << 8 | blue);
}

void 	formulas(t_struct *st, long double *x, long double *y)
{
	long double	tmp;

	tmp = *x * *x - *y * *y + st->x0 + st->c;
	*y = 2 * *x * *y + st->y0 + st->u;
	*x = tmp;
}

int 	calc_pixel(t_struct *st, long double x, long double y)
{
	int			i;
	long double	r;

	i = 0;
	r = 2;
	x = x / (st->w / 2 / r);
	y = y / (st->h / 2 / r);
	st->x0 = x;
	st->y0 = y;
	while (i < st->cycle && x *x + y * y < r * r)
	{
		formulas(st, &x, &y);
		i++;
	}
	if (i == st->cycle)
		return (0);
	return (color(st, i));
}

void 	fractal(t_struct *st)
{
	int i;
	int j;

	j = (-st->heigth) / 2;
//	printf("j: %d he: %d\n", j, st->heigth);
	while (j < st->heigth / 2)
	{
//		write(1, "1", 1);
//		printf("j: %d\n", j);
		i = -st->width / 2;
		while (i < st->width / 2)
		{
//			printf("k: %d\n", (j + st->heigth / 2) * st->width + (i + st->width / 2));
			st->data[(j + st->heigth / 2) * st->width + (i + st->width / 2)] = calc_pixel(st, (long double)i, (long double)j);
			i++;
		}
		j++;
	}
	write(1, "Z", 1);
}

void 	st_init(t_struct *st)
{
	st->heigth = HEIGHT;
	st->width = WIDTH;
	st->h = HEIGHT;
	st->w = WIDTH;
	st->cycle = 50;
	st->color = 0;
	st->c = 0;
	st->u = 0;
	st->move = 0;
}

void	get_black(t_struct *st)
{
	int i;

	i = -1;
	while (++i < st->width * st->heigth)
		st->data[i] = 0;
}

//			ДВИЖЕНИЕ МЫШКИ
//int 	mouse_move(int x, int y, void *s)
//{
//	t_struct *st;
//
//	st = (t_struct *)s;
//	if (!(st->move))
//		return (0);
//	st->c = ((float)x - st->width / 2) / (st->width / 2);
//	st->u = ((float)y - st->heigth / 2) / (st->heigth / 2);
//	get_black(st);
//	fractal(st);
//	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
//	return (0);
//}

int 	key_press(int key, void *s)
{
	t_struct *st;

	st = (t_struct *)s;
	if (key == 53)
		exit(0);
	if (key == 116)
	{
		st->c += 0.01;
		st->u += 0.01;
	}
	else if (key == 121)
	{
		st->c -= 0.01;
		st->u -= 0.01;
	}
	get_black(st);
	fractal(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
//	printf("%d\n", key);
	return (0);
}

int 	main()
{
	t_struct *st;

	if (!(st = malloc(sizeof(t_struct))))
		error();
	st->mlx = mlx_init();
	st_init(st);
	st->win = mlx_new_window(st->mlx, WIDTH, HEIGHT, "FDF");
	st->img = mlx_new_image(st->mlx, WIDTH, HEIGHT);
	mlx_hook(st->win, 2, 0, key_press, (void *)st);
	st->data = (int *)mlx_get_data_addr(st->img,
			&(st->n0), &(st->n1), &(st->n2));
	fractal(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	mlx_loop(st->mlx);
	return (0);
}