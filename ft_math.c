/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:39:31 by surkim            #+#    #+#             */
/*   Updated: 2023/07/28 13:59:15 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_sin(double angle)
{
	return (sin(M_PI * angle / 180));
}

double	ft_cos(double angle)
{
	return (cos(M_PI * angle / 180));
}

void	rotate_z(t_fdf *fdf, double angle)
{
	int		i;
	int		j;
	double	x;
	double	y;

	fdf->angle_z += angle;
	i = 0;
	while (i < fdf->size_y)
	{
		j = 0;
		while (j < fdf->size_x)
		{
			x = fdf->arr[i][j].xx;
			y = fdf->arr[i][j].yy;
			fdf->arr[i][j].xx = x * ft_cos(angle) - y * ft_sin(angle);
			fdf->arr[i][j].yy = x * ft_sin(angle) + y * ft_cos(angle);
			j++;
		}
		i++;
	}
}

void	rotate_y(t_fdf *fdf, double angle)
{
	int		i;
	int		j;
	double	x;
	double	z;

	fdf->angle_y += angle;
	i = 0;
	while (i < fdf->size_y)
	{
		j = 0;
		while (j < fdf->size_x)
		{
			x = fdf->arr[i][j].xx;
			z = fdf->arr[i][j].zz;
			fdf->arr[i][j].xx = z * ft_sin(angle) + x * ft_cos(angle);
			fdf->arr[i][j].zz = z * ft_cos(angle) - x * ft_sin(angle);
			j++;
		}
		i++;
	}
}

void	rotate_x(t_fdf *fdf, double angle)
{
	int		i;
	int		j;
	double	y;
	double	z;

	fdf->angle_x += angle;
	i = 0;
	while (i < fdf->size_y)
	{
		j = 0;
		while (j < fdf->size_x)
		{
			y = fdf->arr[i][j].yy;
			z = fdf->arr[i][j].zz;
			fdf->arr[i][j].yy = y * ft_cos(angle) - z * ft_sin(angle);
			fdf->arr[i][j].zz = y * ft_sin(angle) + z * ft_cos(angle);
			j++;
		}
		i++;
	}
}
