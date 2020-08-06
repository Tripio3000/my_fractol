#include "fractol.h"

void 	usage()
{
	ft_putstr("usage: ./fractal <fractalname> [m, j, z, x]\n");
	exit(0);
}

void 	check(int ac, char **av, t_struct *st)
{
	if (ac != 2)
		usage();
	if (ft_strcmp(&av[1][0], "m") == 0)
		st->f = 1;
	else if (ft_strcmp(&av[1][0], "j") == 0)
		st->f = 2;
	else if (ft_strcmp(&av[1][0], "z") == 0)
		st->f = 3;
	else if (ft_strcmp(&av[1][0], "x") == 0)
		st->f = 4;
	else
		usage();
	return ;
}