/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:34:08 by surkim            #+#    #+#             */
/*   Updated: 2023/07/29 16:27:33 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	press_key_w(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	rotate_x(fdf, 1);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_s(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	rotate_x(fdf, -1);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_a(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	rotate_y(fdf, -1);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_d(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	rotate_y(fdf, 1);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_q(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	rotate_z(fdf, -1);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}
