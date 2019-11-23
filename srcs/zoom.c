/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:03:10 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/18 00:29:49 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_minus(t_fdf **t, int n, int m)
{
	int i;
	int j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			t[i][j].y /= 1.1;
			t[i][j].x /= 1.1;
			t[i][j].z /= 1.1;
		}
	}
}

void	zoom_plus(t_fdf **t, int n, int m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			t[i][j].y *= 1.1;
			t[i][j].x *= 1.1;
			t[i][j].z *= 1.1;
		}
	}
}
