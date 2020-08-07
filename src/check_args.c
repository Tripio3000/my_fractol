/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:42:57 by cseabass          #+#    #+#             */
/*   Updated: 2020/08/06 22:42:59 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr("usage: ./fractal <fractalname> [m, j, z, x]\n");
	exit(0);
}

void	check(int ac, char **av, t_struct *st)
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

void	st_init(t_struct *st)
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

void	instr(void)
{
	ft_putstr("\n\n******************** INSTRUCTION ********************\n");
	ft_putstr("Mouse move           -      change coefficient\n");
	ft_putstr("Space                -      changing coefficient [ON/OFF]\n");
	ft_putstr("4, 7 right side      -      coefficient -+ 0.01\n");
	ft_putstr("5, 8 right side      -      coefficient -+ 0.0001\n");
	ft_putstr("+, - right side      -      change color theme\n");
	ft_putstr("Arrows (up)          -      -+ 5 iterations of the loop\n");
	ft_putstr("Arrows (down)        -      shift\n");
	ft_putstr("ESC                  -      exit\n");
}
