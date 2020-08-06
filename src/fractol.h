/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:42:31 by cseabass          #+#    #+#             */
/*   Updated: 2020/08/06 22:42:33 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FRACTOL_H
# define MY_FRACTOL_H
# define HEIGHT 1300
# define WIDTH 1300

# include <math.h>
# include "../MinilibX/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct		s_struct
{
	void			*mlx;
	void			*win;
	void			*img;
	int				n0;
	int				n1;
	int				n2;
	int				*data;
	int				heigth;
	int				width;
	long double		h;
	long double		w;
	long double		x0;
	long double		y0;
	long double		tmp;
	long double		shift_x;
	long double		shift_y;
	long double		t;
	double			c;
	double			u;
	int				move;
	int				str;
	int				cycle;
	int				color;
	int				pot;
	int				f;
}					t_struct;

void				threads(t_struct *data);
int					key_press(int key, void *s);
int					key_press1(int key, t_struct *st);
void				check(int ac, char **av, t_struct *st);
void				get_black(t_struct *st);
int					color2(t_struct *st, int red, int green, int blue);
int					color1(t_struct *st, int red, int green, int blue);
int					color(t_struct *st, int i);
int					mouse_put(int b, int x, int y, void *s);
int					mouse_move(int x, int y, void *s);
void				error(void);
void				st_init(t_struct *st);
void				instr(void);

#endif
