/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:41:02 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/19 22:52:08 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_zero(t_min_max *mm, t_fdf **fdf)
{
	mm->xmin = fdf[0][0].x;
	mm->xmax = fdf[0][0].x;
	mm->ymin = fdf[0][0].y;
	mm->ymax = fdf[0][0].y;
}

t_min_max	min_max(t_fdf **fdf, int n, int m)
{
	t_min_max	mm;
	int			i;
	int			j;

	set_zero(&mm, fdf);
	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			if (mm.xmin >= fdf[i][j].x)
				mm.xmin = fdf[i][j].x;
			if (mm.xmax <= fdf[i][j].x)
				mm.xmax = fdf[i][j].x;
			if (mm.ymin >= fdf[i][j].y)
				mm.ymin = fdf[i][j].y;
			if (mm.ymax <= fdf[i][j].y)
				mm.ymax = fdf[i][j].y;
		}
	}
	mm.v1 = (WIN_WIDTH / 2) - ((mm.xmin + mm.xmax) / 2);
	mm.v2 = ((WIN_HEIGTH - 175) / 2) - ((mm.ymin + mm.ymax) / 2);
	return (mm);
}

void		apply_min_max(t_fdf **fdf, int n, int m)
{
	t_min_max	l;
	int			i;
	int			j;

	l = min_max(fdf, n, m);
	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			fdf[i][j].x += l.v1;
			fdf[i][j].y += l.v2;
		}
	}
}

t_hook		assigning(int n, int m, t_mlx mlx, t_fdf **fdf)
{
	t_hook	l;

	l.n = n;
	l.m = m;
	l.mlx.fdf = fdf;
	l.mlx.mlx_ptr = mlx.mlx_ptr;
	l.mlx.win = mlx.win;
	l.mlx.img.img_ptr = mlx.img.img_ptr;
	l.proj = 1;
	return (l);
}

int			scaling(int n, int m)
{
	int scale;
	int i;
	int j;

	i = 1;
	while (1)
	{
		if ((m * i) < (0.5 * WIN_HEIGTH))
			i++;
		else
			break ;
	}
	j = 1;
	while (1)
	{
		if ((n * j) < (0.5 * WIN_WIDTH))
			j++;
		else
			break ;
	}
	if (j > i)
		scale = i;
	else
		scale = j;
	return (scale);
}
