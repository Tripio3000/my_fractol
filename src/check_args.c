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
	if (av[1][0] == 'm')
		st->f = 1;
	else if (av[1][0] == 'j')
		st->f = 2;
	else if (av[1][0] == 'z')
		st->f = 3;
	else if (av[1][0] == 'x')
		st->f = 4;
	else
		usage();
	return ;
}