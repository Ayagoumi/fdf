/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:15:46 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/20 04:30:07 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_to_screen2(t_mlx mlx)
{
	int	i;

	mlx_string_put(mlx.mlx_ptr, mlx.win, 40, 100, 0xffff00,
			"Press 2        : Change the projection to parallel");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 600, 100, 0xffff00,
			"Press 1        : Change the projection to iso");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 40, 120, 0xffff00,
			"Press LEFT KEY : GO left");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 600, 120, 0xffff00,
			"Press RIGHT KEY: GO right");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 40, 140, 0xffff00,
			"Press DOWN KEY : GO Down");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 600, 140, 0xffff00,
			"Press UP KEY   : Go UP");
	i = -1;
	while (++i < 1200)
		mlx_string_put(mlx.mlx_ptr, mlx.win, i, 160, 0xffff00, "-");
}

void		put_to_screen(t_mlx mlx)
{
	mlx_string_put(mlx.mlx_ptr, mlx.win, 10, 5, 0xffff00, "Menu :");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 40, 40, 0xffff00,
			"Press W        : Elevate up");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 600, 40, 0xffff00,
			"Press S        : Elevate down");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 40, 60, 0xffff00,
			"Press C        : MOFO colors");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 600, 60, 0xffff00,
			"Press ESC      : Terminate the window");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 40, 80, 0xffff00,
			"Press +        : Zoom in");
	mlx_string_put(mlx.mlx_ptr, mlx.win, 600, 80, 0xffff00,
			"Press -        : Zoom out");
	put_to_screen2(mlx);
}
