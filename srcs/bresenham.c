/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:24:32 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/22 01:51:56 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bre		assigne_bre(t_point p)
{
	t_bre	bre;

	bre.xinc = (p.x0 < p.x1 ? 1 : -1);
	bre.yinc = (p.y0 < p.y1 ? 1 : -1);
	bre.dx = abs(p.x1 - p.x0);
	bre.dy = -abs(p.y1 - p.y0);
	bre.err = bre.dx + bre.dy;
	bre.x = p.x0;
	bre.y = p.y0;
	return (bre);
}

void		bresenham2(t_point p, int col, int *data)
{
	t_bre	bre;

	bre = assigne_bre(p);
	while (bre.x != p.x1 || bre.y != p.y1)
	{
		if ((bre.y > 0) && (bre.y < WIN_HEIGTH)
				&& (bre.x > 0) && (bre.x < WIN_WIDTH))
			data[(bre.y * WIN_WIDTH) + bre.x] = col;
		bre.e2 = 2 * bre.err;
		if (bre.e2 >= bre.dy)
		{
			bre.err += bre.dy;
			bre.x += bre.xinc;
		}
		if (bre.e2 <= bre.dx)
		{
			bre.err += bre.dx;
			bre.y += bre.yinc;
		}
	}
}

void		apply_bresenham(t_fdf **fdf, t_mlx mlx, int m, int n)
{
	int		i;
	int		j;
	t_point p;

	i = -1;
	p.x0 = 0;
	mlx.fdf = fdf;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			if (j + 1 < n)
				apply_bresenham_case1(mlx, i, j, p);
			if (i + 1 < m)
				apply_bresenham_case2(mlx, i, j, p);
		}
	}
}
