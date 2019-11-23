/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:39:13 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/23 04:56:11 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"

# define WIN_WIDTH 1200
# define WIN_HEIGTH 1200

# define RED 16711680
# define ORANGE 16744192
# define YELLOW 16776960
# define GREEN 65280
# define BLUE 255
# define INDIGO 3025759
# define VIOLET	9109759

typedef struct			s_fdf
{
	double	x;
	double	y;
	double	z;
	int		colors;
}						t_fdf;

typedef struct			s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}						t_img;

typedef struct			s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
	t_fdf	**fdf;
	t_fdf	**fdf_iso;
}						t_mlx;

typedef	struct			s_min_max
{
	int		xmax;
	int		xmin;
	int		ymax;
	int		ymin;
	double	v1;
	double	v2;
}						t_min_max;

typedef struct			s_hook
{
	int		n;
	int		m;
	t_mlx	mlx;
	int		proj;
	int		scale;
}						t_hook;

typedef struct			s_bre
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		xinc;
	int		yinc;
	int		err;
	int		e2;
}						t_bre;

typedef struct			s_point
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		i;
	int		j;
}						t_point;
t_bre					assigne_bre(t_point p);
void					bresenham2(t_point p, int col, int *data);
void					apply_bresenham(t_fdf **fdf, t_mlx mlx, int m, int n);
t_point					ass_points(int x0, int y0, int x1, int y1);
void					apply_bresenham_case1(t_mlx mlx, int i,\
		int j, t_point p);
void					apply_bresenham_case2(t_mlx mlx, int i,\
		int j, t_point p);
void					put_to_screen2(t_mlx mlx);
void					put_to_screen(t_mlx mlx);
int						line_numb(char *argv);
int						ft_strlen_2_dim(char **tab);
size_t					check(int n, int i);
int						to_hexa(char *str);
t_fdf					*values(char **tab, size_t n, int l);
void					iso(double *x, double *y, int z);
void					iso_projection(t_fdf **fdf, int m, int n,\
		int scale);
t_fdf					**parallel_projection(t_fdf **fdf, int n, int m,\
		int scale);
void					set_zero(t_min_max *mm, t_fdf **fdf);
t_min_max				min_max(t_fdf **fdf, int n, int m);
void					apply_min_max(t_fdf **fdf, int n, int m);
t_hook					assigning(int n, int m, t_mlx mlx, t_fdf **fdf);
int						scaling(int n, int m);
int						ft_even(int k);
t_fdf					**allocate(int n, int m);
t_fdf					**duplicate(t_fdf **fdf, t_hook *h);
void					move_to_left(t_fdf **t, int n, int m);
void					move_to_right(t_fdf **t, int n, int m);
void					move_down(t_fdf **t, int n, int m);
void					move_up(t_fdf **t, int n, int m);
void					zoom_plus(t_fdf **t, int n, int m);
void					zoom_minus(t_fdf **t, int n, int m);
void					key_hooks1(int key, t_hook *h);
void					key_hooks2(int key, t_hook *h, t_fdf ***t);
void					key_hooks3(int key, t_hook *h, t_fdf **t);
void					key_hooks4(int key, t_hook *h, t_fdf **t);
void					key_hooks5(int key, t_hook *h, int *tab);
void					crazy_mod(t_hook *h);
void					no_name(int key, t_hook *h);
int						*assigne_tab(void);
void					lit_hooks1(int key, t_hook *h, t_fdf ***t,\
		int *tab);
int						hooks1(int key, t_hook *h);
void					lit_hooks2(int key, t_hook *h, t_fdf ***t);
int						hooks2(int key, t_hook *h);
void					free_shit(char **tab, char *line);
void					show_error(char *str, int n);
void					put_to_window(t_fdf **fdf, int n, int m, char *str);
int						get_data(t_fdf **fdf, char **argv, int fd);

#endif
