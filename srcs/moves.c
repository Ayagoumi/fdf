/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:02:15 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/18 00:30:03 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_to_left(t_fdf **t, int n, int m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
			t[i][j].x -= 10;
	}
}

void	move_to_right(t_fdf **t, int n, int m)
{
	int i;
	int j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
			t[i][j].x += 10;
	}
}

void	move_down(t_fdf **t, int n, int m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
			t[i][j].y += 10;
	}
}

void	move_up(t_fdf **t, int n, int m)
{
	int i;
	int j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
			t[i][j].y -= 10;
	}
}
