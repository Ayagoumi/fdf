/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:26:01 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/18 02:34:17 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(double *x, double *y, int z)
{
	double	p_x;
	double	p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - p_y) * cos(0.523599);
	*y = -z + (p_x + p_y) * sin(0.523599);
}

void		iso_projection(t_fdf **fdf, int m, int n, int scale)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			fdf[i][j].x *= scale;
			fdf[i][j].y *= scale;
			fdf[i][j].z *= 1;
			iso(&fdf[i][j].x, &fdf[i][j].y, fdf[i][j].z);
		}
	}
}

t_fdf		**parallel_projection(t_fdf **fdf, int n, int m, int scale)
{
	int i;
	int j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			fdf[i][j].x *= scale;
			fdf[i][j].y *= scale;
			fdf[i][j].z *= 1;
		}
	}
	return (fdf);
}
