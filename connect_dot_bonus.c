/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_dot_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:23:22 by surkim            #+#    #+#             */
/*   Updated: 2023/07/29 16:26:34 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_color_diff(int a_color, int b_color, int diff)
{
	int	r_diff;
	int	g_diff;
	int	b_diff;
	int	total;

	if (diff == 0)
		diff = 1;
	r_diff = ((b_color / (16 * 16 * 16 * 16)) - \
	(a_color / (16 * 16 * 16 * 16))) / diff;
	g_diff = ((b_color % (16 * 16 * 16 * 16)) / (16 * 16)) - \
	((a_color % (16 * 16 * 16 * 16)) / (16 * 16));
	g_diff /= diff;
	b_diff = ((b_color % (16 * 16)) - (a_color % (16 * 16))) / diff;
	total = r_diff * (16 * 16 * 16 * 16) + g_diff * (16 * 16) + b_diff;
	return (total);
}

void	put_line_x(t_fdf *fdf, t_arrdata a, t_arrdata b)
{
	double	i;
	double	diff;
	int		color_diff;

	diff = (b.screen_y - a.screen_y) / (b.screen_x - a.screen_x);
	color_diff = get_color_diff(a.color, b.color, b.screen_x - a.screen_x);
	i = 0;
	while (i + a.screen_x < b.screen_x)
	{
		if (a.screen_x + i > 0 && a.screen_x + i < 1920 && \
		a.screen_y + diff * i > 0 && a.screen_y + diff * i < 1080)
			my_mlx_pixel_put(&(fdf->img), a.screen_x + i, \
			a.screen_y + diff * i, a.color + color_diff * i);
		i++;
	}
}

void	put_line_y(t_fdf *fdf, t_arrdata a, t_arrdata b)
{
	double	i;
	double	diff;
	int		color_diff;

	diff = (b.screen_x - a.screen_x) / (b.screen_y - a.screen_y);
	color_diff = get_color_diff(a.color, b.color, b.screen_y - a.screen_y);
	i = 0;
	while (i + a.screen_y < b.screen_y)
	{
		if (a.screen_x + diff * i > 0 && a.screen_x + diff * i < 1920 && \
		a.screen_y + i > 0 && a.screen_y + i < 1080)
			my_mlx_pixel_put(&(fdf->img), a.screen_x + diff * i, \
			a.screen_y + i, a.color + color_diff * i);
		i++;
	}
}

void	dda(t_fdf *fdf, t_arrdata a, t_arrdata b)
{
	if (fabs(a.screen_x - b.screen_x) > fabs(a.screen_y - b.screen_y))
	{
		if (a.screen_x < b.screen_x)
			put_line_x(fdf, a, b);
		else
			put_line_x(fdf, b, a);
	}
	else
	{
		if (a.screen_y < b.screen_y)
			put_line_y(fdf, a, b);
		else
			put_line_y(fdf, b, a);
	}
}

void	connect_dot(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->size_y)
	{
		j = 0;
		while (j < fdf->size_x)
		{
			if (j != fdf->size_x - 1)
				dda(fdf, fdf->arr[i][j], fdf->arr[i][j + 1]);
			if (i != fdf->size_y - 1)
				dda(fdf, fdf->arr[i][j], fdf->arr[i + 1][j]);
			j++;
		}
		i++;
	}
}
