/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:38:38 by surkim            #+#    #+#             */
/*   Updated: 2023/07/27 19:54:03 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_xy(t_fdf *fdf)
{
	copy_arr(fdf, fdf->arr, fdf->xy);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	print_yz(t_fdf *fdf)
{
	copy_arr(fdf, fdf->arr, fdf->yz);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	print_zx(t_fdf *fdf)
{
	copy_arr(fdf, fdf->arr, fdf->zx);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	parallel(int keycode, t_fdf *fdf)
{
	if (keycode == 18)
		return (print_xy(fdf));
	else if (keycode == 19)
		return (print_zx(fdf));
	else if (keycode == 20)
		return (print_yz(fdf));
	return (0);
}
