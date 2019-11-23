/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:01:24 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/18 00:31:15 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	**allocate(int n, int m)
{
	int		i;
	t_fdf	**fdf;

	if (!(fdf = (t_fdf**)malloc(sizeof(t_fdf*) * m)))
		return (NULL);
	i = -1;
	while (++i < m)
		if (!(fdf[i] = (t_fdf*)malloc(sizeof(t_fdf) * n)))
			return (NULL);
	return (fdf);
}

t_fdf	**duplicate(t_fdf **fdf, t_hook *h)
{
	int		i;
	int		j;

	h->mlx.fdf_iso = allocate(h->n, h->m);
	h->mlx.fdf_iso[0][0].x = 0;
	i = -1;
	while (++i < h->m)
	{
		j = -1;
		while (++j < h->n)
		{
			h->mlx.fdf_iso[i][j].x = fdf[i][j].x;
			h->mlx.fdf_iso[i][j].y = fdf[i][j].y;
			h->mlx.fdf_iso[i][j].z = fdf[i][j].z;
			h->mlx.fdf_iso[i][j].colors = fdf[i][j].colors;
		}
	}
	return (h->mlx.fdf_iso);
}
