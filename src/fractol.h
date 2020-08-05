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

typedef struct 		s_struct
{
	void 			*mlx;
	void 			*win;
	void 			*img;
	int				n0;
	int				n1;
	int				n2;
	int				*data;
	int 			heigth;
	int 			width;
	long double		h;
	long double		w;
	long double		x0;
	long double		y0;
	long double		tmp;
	long double		shift_x;
	long double		shift_y;
	double 			c;
	double 			u;
	int 			move;
	int 			str;
	int 			cycle;
	int 			color;
	int 			pot;
	int 			f;
}					t_struct;

void	threads(t_struct *data);
int 	key_press(int key, void *s);
int 	key_press1(int key, t_struct *st);

#endif
