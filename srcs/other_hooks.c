/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:00:50 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/18 00:29:29 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lit_hooks2(int key, t_hook *h, t_fdf ***t)
{
	if (h->proj == 1)
		*t = h->mlx.fdf_iso;
	else if (h->proj == 0)
		*t = h->mlx.fdf;
	if (key == 1)
		key_hooks3(key, h, *t);
	else if (key == 13)
		key_hooks4(key, h, *t);
}

int		hooks2(int key, t_hook *h)
{
	static t_fdf	**t;
	int				*tab;

	tab = assigne_tab();
	mlx_clear_window(h->mlx.mlx_ptr, h->mlx.win);
	mlx_destroy_image(h->mlx.mlx_ptr, h->mlx.img.img_ptr);
	lit_hooks2(key, h, &t);
	h->mlx.img.img_ptr = mlx_new_image(h->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	h->mlx.img.data = (int *)mlx_get_data_addr(h->mlx.img.img_ptr,
			&h->mlx.img.bpp, &h->mlx.img.size_l, &h->mlx.img.endian);
	put_to_screen(h->mlx);
	apply_bresenham(t, h->mlx, h->m, h->n);
	mlx_put_image_to_window(h->mlx.mlx_ptr, h->mlx.win,
			h->mlx.img.img_ptr, 0, 175);
	return (1);
}
