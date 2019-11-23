/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:05:41 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/18 00:03:54 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	crazy_mod(t_hook *h)
{
	int	i;
	int	j;

	i = -1;
	while (++i < h->m)
	{
		j = -1;
		while (++j < h->n)
		{
			if (h->mlx.fdf_iso[i][j].z)
			{
				h->mlx.fdf_iso[i][j].colors =
					(h->mlx.fdf_iso[i][j].colors + 15138560) % 16777215;
				h->mlx.fdf[i][j].colors =
					(h->mlx.fdf[i][j].colors + 15138560) % 16777215;
			}
			else
			{
				h->mlx.fdf_iso[i][j].colors =
					(h->mlx.fdf_iso[i][j].colors - 5000) % 16777215;
				h->mlx.fdf[i][j].colors =
					(h->mlx.fdf[i][j].colors - 5000) % 16777215;
			}
		}
	}
}

void	no_name(int key, t_hook *h)
{
	if (key == 125)
	{
		move_down(h->mlx.fdf_iso, h->n, h->m);
		move_down(h->mlx.fdf, h->n, h->m);
	}
	else if (key == 126)
	{
		move_up(h->mlx.fdf_iso, h->n, h->m);
		move_up(h->mlx.fdf, h->n, h->m);
	}
}

int		*assigne_tab(void)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * 7);
	tab[0] = RED;
	tab[1] = ORANGE;
	tab[2] = YELLOW;
	tab[3] = GREEN;
	tab[4] = BLUE;
	tab[5] = INDIGO;
	tab[6] = VIOLET;
	return (tab);
}

void	lit_hooks1(int key, t_hook *h, t_fdf ***t, int *tab)
{
	if (h->proj == 1)
		*t = h->mlx.fdf_iso;
	else if (h->proj == 0)
		*t = h->mlx.fdf;
	if (key == 69 || key == 78 || key == 124 || key == 123)
		key_hooks1(key, h);
	else if (key == 53 || key == 84 || key == 83)
		key_hooks2(key, h, t);
	else if (key == 8)
		key_hooks5(key, h, tab);
	else if (key == 125 || key == 126)
		no_name(key, h);
	else if (key != 1 && key != 13)
		crazy_mod(h);
}

int		hooks1(int key, t_hook *h)
{
	static t_fdf	**t;
	int				*tab;

	tab = assigne_tab();
	mlx_clear_window(h->mlx.mlx_ptr, h->mlx.win);
	mlx_destroy_image(h->mlx.mlx_ptr, h->mlx.img.img_ptr);
	lit_hooks1(key, h, &t, tab);
	h->mlx.img.img_ptr = mlx_new_image(h->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	h->mlx.img.data = (int *)mlx_get_data_addr(h->mlx.img.img_ptr,
			&h->mlx.img.bpp, &h->mlx.img.size_l, &h->mlx.img.endian);
	put_to_screen(h->mlx);
	apply_bresenham(t, h->mlx, h->m, h->n);
	mlx_put_image_to_window(h->mlx.mlx_ptr, h->mlx.win,
			h->mlx.img.img_ptr, 0, 175);
	return (1);
}
