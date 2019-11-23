/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_bresenham.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:24:40 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/17 06:22:39 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ass_points(int x0, int y0, int x1, int y1)
{
	t_point		p;

	p.x0 = x0;
	p.x1 = x1;
	p.y0 = y0;
	p.y1 = y1;
	return (p);
}

void		apply_bresenham_case1(t_mlx mlx, int i, int j, t_point p)
{
	p = ass_points(mlx.fdf[i][j].x, mlx.fdf[i][j].y, mlx.fdf[i][j + 1].x,
		mlx.fdf[i][j + 1].y);
	bresenham2(p, mlx.fdf[i][j].colors, mlx.img.data);
	if (mlx.fdf[i][j].z && j >= 1)
	{
		p = ass_points(mlx.fdf[i][j - 1].x, mlx.fdf[i][j - 1].y,
			mlx.fdf[i][j].x, mlx.fdf[i][j].y);
		bresenham2(p, mlx.fdf[i][j].colors, mlx.img.data);
	}
}

void		apply_bresenham_case2(t_mlx mlx, int i, int j, t_point p)
{
	p = ass_points(mlx.fdf[i][j].x, mlx.fdf[i][j].y,
		mlx.fdf[i + 1][j].x, mlx.fdf[i + 1][j].y);
	bresenham2(p, mlx.fdf[i][j].colors, mlx.img.data);
	if (mlx.fdf[i][j].z && i >= 1)
	{
		p = ass_points(mlx.fdf[i - 1][j].x, mlx.fdf[i - 1][j].y,
			mlx.fdf[i][j].x, mlx.fdf[i][j].y);
		bresenham2(p, mlx.fdf[i][j].colors, mlx.img.data);
	}
}
