/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 03:54:09 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/23 04:50:56 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		show_error(char *str, int n)
{
	if (n == 0)
		ft_putstr("No Data found.\n");
	if (n == 1)
	{
		ft_putstr("No file ");
		ft_putstr(str);
		ft_putchar('\n');
	}
	exit(1);
}

void		put_to_window(t_fdf **fdf, int n, int m, char *str)
{
	t_mlx	mlx;
	t_hook	h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH, str);
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr,
			&mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	put_to_screen(mlx);
	h = assigning(n, m, mlx, fdf);
	h.mlx.fdf_iso = duplicate(fdf, &h);
	h.scale = scaling(n, m);
	parallel_projection(h.mlx.fdf, n, m, h.scale);
	iso_projection(h.mlx.fdf_iso, m, n, h.scale);
	apply_min_max(h.mlx.fdf_iso, n, m);
	apply_min_max(h.mlx.fdf, n, m);
	apply_bresenham(h.mlx.fdf_iso, mlx, m, n);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 175);
	mlx_key_hook(mlx.win, hooks2, &h);
	mlx_hook(mlx.win, 2, 0, hooks1, &h);
	mlx_loop(mlx.mlx_ptr);
}

void		free_shit(char **tab, char *line)
{
	int		j;

	j = 0;
	while (tab[j])
		free(tab[j]);
	free(tab);
	free(line);
}

int			get_data(t_fdf **fdf, char **argv, int fd)
{
	char			*line;
	static int		i;
	int				n;
	int				m;
	char			**tab;

	((m = line_numb(argv[1])) < 1) ? show_error(argv[1], 0) : 1;
	if (!(fdf = (t_fdf**)malloc(sizeof(t_fdf*) * (m + 1))))
		return (0);
	while (get_next_line(fd, &line) && (tab = ft_split_whitespaces(line)))
	{
		n = ft_strlen_2_dim(tab);
		if ((n = check(n, i)) == 0)
		{
			ft_putendl("Found wrong line length. Exiting.");
			return (0);
		}
		else
			fdf[i] = values(tab, n, i);
		i++;
		free_shit(tab, line);
	}
	free(line);
	put_to_window(fdf, n, m, argv[1]);
	return (i);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_fdf	**fdf;
	int		i;

	fdf = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 2)
		{
			i = get_data(fdf, argv, fd);
			while (i--)
				free(*fdf);
			free(fdf);
		}
		else
			show_error(argv[1], 1);
	}
	else
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	return (0);
}
