/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:04:15 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/20 04:12:42 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hooks1(int key, t_hook *h)
{
	if (key == 69)
	{
		zoom_plus(h->mlx.fdf_iso, h->n, h->m);
		zoom_plus(h->mlx.fdf, h->n, h->m);
		apply_min_max(h->mlx.fdf_iso, h->n, h->m);
		apply_min_max(h->mlx.fdf, h->n, h->m);
	}
	else if (key == 78)
	{
		zoom_minus(h->mlx.fdf_iso, h->n, h->m);
		zoom_minus(h->mlx.fdf, h->n, h->m);
		apply_min_max(h->mlx.fdf_iso, h->n, h->m);
		apply_min_max(h->mlx.fdf, h->n, h->m);
	}
	else if (key == 124)
	{
		move_to_right(h->mlx.fdf_iso, h->n, h->m);
		move_to_right(h->mlx.fdf, h->n, h->m);
	}
	else if (key == 123)
	{
		move_to_left(h->mlx.fdf_iso, h->n, h->m);
		move_to_left(h->mlx.fdf, h->n, h->m);
	}
}

void	key_hooks2(int key, t_hook *h, t_fdf ***t)
{
	int	i;

	if (key == 83)
	{
		h->proj = 1;
		*t = h->mlx.fdf_iso;
	}
	else if (key == 84)
	{
		h->proj = 0;
		*t = h->mlx.fdf;
	}
	else if (key == 53)
	{
		i = 0;
		while (i--)
			free(*(h->mlx.fdf_iso));
		free(h->mlx.fdf_iso);
		exit(EXIT_SUCCESS);
	}
	apply_min_max(h->mlx.fdf_iso, h->n, h->m);
	apply_min_max(h->mlx.fdf, h->n, h->m);
}

void	key_hooks3(int key, t_hook *h, t_fdf **t)
{
	int i;
	int	j;

	if (key == 1)
	{
		if (h->proj == 1)
		{
			i = -1;
			while (++i < h->m)
			{
				j = -1;
				while (++j < h->n)
					if (t[i][j].z != 0)
						t[i][j].y = t[i][j].y + t[i][j].z;
			}
		}
	}
}

void	key_hooks4(int key, t_hook *h, t_fdf **t)
{
	int i;
	int	j;

	if (key == 13)
	{
		if (h->proj == 1)
		{
			i = -1;
			while (++i < h->m)
			{
				j = -1;
				while (++j < h->n)
					if (t[i][j].z != 0 || t[i][j + 1].z != 0)
						t[i][j].y = t[i][j].y - t[i][j].z;
			}
		}
	}
}

void	key_hooks5(int key, t_hook *h, int *tab)
{
	int i;
	int	j;

	if (key == 8)
	{
		i = -1;
		while (++i < h->m)
		{
			j = -1;
			while (++j < h->n)
			{
				if (h->mlx.fdf[i][j].z != 0)
				{
					h->mlx.fdf_iso[i][j].colors = tab[i % 7];
					h->mlx.fdf[i][j].colors = tab[i % 7];
				}
			}
		}
	}
}
