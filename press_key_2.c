/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:36:14 by surkim            #+#    #+#             */
/*   Updated: 2023/07/28 15:37:57 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press_key_e(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	rotate_z(fdf, 1);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_up(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	fdf->axis_y -= 3;
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_down(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	fdf->axis_y += 3;
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_left(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	fdf->axis_x -= 3;
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_right(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	fdf->axis_x += 3;
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}
