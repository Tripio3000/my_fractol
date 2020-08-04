#ifndef MY_FRACTOL_H
# define MY_FRACTOL_H
# define HEIGHT 1000
# define WIDTH 1000

# include <math.h>
# include "../MinilibX/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

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
	double 			c;
	double 			u;
	int 			move;
	int 			str;
	int 			cycle;
	int 			color;
}					t_struct;

#endif
