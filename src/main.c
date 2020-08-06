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
	if (st->color == 1)
	{
		red = (int)(9 * (1 - st->tmp) * pow(st->tmp, 3) * 255);
		green = (int)(15 * pow((1 - st->tmp), 2) * pow(st->tmp, 2) * 255);
		blue = 0xFF - (int)(8.5 * pow((1 - st->tmp), 3) * st->tmp * 255);
	}
	else if (st->color == 1)
	{
		red = (int)(5 * (pow(st->tmp, 2) - 300) * 255);
		green = (int)(10 * 1 / st->tmp * 255);
		blue = (int)(5 * 1 / (st->tmp + 200) * 255);
	}
	else if (st->color == 1)
	{
		red = (int)(50 * (1 - st->tmp) * 255);
		green = (int)(100 * 1 / pow(2, st->tmp) * 255); //яракий: красный желтый оранжевый, теплые цвета
		blue = (int)(50 * 1 / (st->tmp + 200) * 255);
	}
	else if (st->color == 0)
	{
		red = (int)(50 * (1 - st->tmp) * 255);
		green = (int)(100 * 1 / (st->tmp + 200) * 255); //зеленый и оранжевый
		blue = 0xFF - (int)(50 * 1 / (st->tmp + 200) * 55);
	}
	else if (st->color == 1)
	{
		red = (int)(0.5 * (1 - st->tmp) * 255);
		green = (int)(62 * (st->tmp + 200) * 255);   //+- нормально
		blue = (int)(13 * (st->tmp + 200) * 255);
	}
	else if (st->color == 1)
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

	if (st->f == 1)
	{
		tmp = *x * *x - *y * *y + st->x0 + st->c;
		*y = 2 * *x * *y + st->y0 + st->u;
		*x = tmp;
	}
	else if (st->f == 2)
	{
		tmp = *x * *x - *y * *y + + st->c;
		*y = 2 * *x * *y + + st->u;
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
	while (i < st->cycle && x * x + y * y < r * r)
	{
		formulas(st, &x, &y);
		i++;
	}
	if (i == st->cycle)
		return (0);
	return (color(st, i));
}

void 	*fractal(void *s)
{
	int i;
	int j;
	t_struct *st;

	st = (t_struct*)s;
	j = -st->heigth / 2 + st->str * st->heigth / st->pot;
	while (j < -st->heigth / 2 + (st->str + 1) * st->heigth / st->pot)
	{
		i = -st->width / 2;
		while (i < st->width / 2)
		{
			st->data[(j + st->heigth / 2) * st->width + (i + st->width / 2)] = calc_pixel(st, (long double)i + st->shift_x, (long double)j + st->shift_y);
			i++;
		}
		j++;
	}
	return (0);
}

void 	st_init(t_struct *st)
{
	st->heigth = HEIGHT;
	st->width = WIDTH;
	st->h = HEIGHT;
	st->w = WIDTH;
	st->cycle = 51;
	st->color = 0;
	st->c = 0;
	st->u = 0;
	st->move = 0;
	st->pot = 10;
	st->shift_x = 0;
	st->shift_y = 0;
	st->f = 3;
}

void	get_black(t_struct *st)
{
	int i;

	i = -1;
	while (++i < st->width * st->heigth)
		st->data[i] = 0;
}

//			ДВИЖЕНИЕ МЫШКИ
int 	mouse_move(int x, int y, void *s)
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
//	printf("x: %d  y: %d\n", x, y);
	return (0);
}

int 	mouse_put(int b, int x, int y, void *s)
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
	else if (b == 5)
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
//	printf("b: %d  x: %d  y: %d\n", b, x, y);
	return (0);
}

void	threads(t_struct *data)
{
	t_struct 			lst[data->pot];
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

int 	main(int ac, char **av)
{
	t_struct *st;

	if (!(st = malloc(sizeof(t_struct))))
		error();
	st->mlx = mlx_init();
	st_init(st);
	check(ac, av, st);
	st->win = mlx_new_window(st->mlx, WIDTH, HEIGHT, "FDF");
	st->img = mlx_new_image(st->mlx, WIDTH, HEIGHT);
	mlx_hook(st->win, 2, 0, key_press, (void *)st);
	mlx_hook(st->win, 6, 0, mouse_move, (void *)st);
	mlx_hook(st->win, 4, 0, mouse_put, (void *)st);
	st->data = (int *)mlx_get_data_addr(st->img,
			&(st->n0), &(st->n1), &(st->n2));
	threads(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	mlx_loop(st->mlx);
	return (0);
}