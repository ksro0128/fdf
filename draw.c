/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:18:22 by surkim            #+#    #+#             */
/*   Updated: 2023/07/28 14:04:47 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	dot(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->size_y)
	{
		j = 0;
		while (j < fdf->size_x)
		{
			fdf->arr[i][j].screen_x = fdf->arr[i][j].xx \
			* fdf->scale + fdf->axis_x;
			fdf->arr[i][j].screen_y = fdf->arr[i][j].yy \
			* fdf->scale + fdf->axis_y;
			if (fdf->arr[i][j].screen_x > 0 && fdf->arr[i][j].screen_y > 0 && \
			fdf->arr[i][j].screen_x < 1920 && fdf->arr[i][j].screen_y > 1080)
				my_mlx_pixel_put(&fdf->img, fdf->arr[i][j].screen_x, \
				fdf->arr[i][j].screen_y, fdf->arr[i][j].color);
			j++;
		}
		i++;
	}
}

void	draw(t_fdf *fdf)
{
	dot(fdf);
	connect_dot(fdf);
}
