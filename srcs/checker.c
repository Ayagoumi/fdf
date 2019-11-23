/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 05:18:26 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/11/17 05:34:37 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			line_numb(char *argv)
{
	int		n;
	char	*line;
	int		fd;
	int		ret;

	n = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		n++;
		free(line);
	}
	close(fd);
	return (n);
}

int			ft_strlen_2_dim(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

size_t		check(int n, int i)
{
	static int	nb;

	if (i == 0)
	{
		nb = n;
		return (n);
	}
	else if (n >= nb)
		return (nb);
	else
		return (0);
}

int			to_hexa(char *str)
{
	int i;

	i = 0;
	while (str[i] == ',' || str[i] == '0' || str[i] == 'x')
		str++;
	return (ft_atoi_base(upper_case(str), "0123456789ABCDEF"));
}

t_fdf		*values(char **tab, size_t n, int l)
{
	size_t	i;
	t_fdf	*f;
	char	*str;

	i = -1;
	if (!(f = (t_fdf*)malloc(sizeof(t_fdf) * (n + 1))))
		return (0);
	while (++i < n)
	{
		f[i].x = i;
		f[i].y = l;
		f[i].z = ft_atoi(tab[i]);
		if ((str = ft_strchr(tab[i], ',')) != NULL)
			f[i].colors = to_hexa(str);
		else
			f[i].colors = 16777215;
	}
	return (f);
}
