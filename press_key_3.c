/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:37:07 by surkim            #+#    #+#             */
/*   Updated: 2023/07/29 15:38:15 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press_key_r(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	fdf->scale += 1;
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	press_key_f(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
	fdf->scale -= 1;
	if (fdf->scale < 0.1)
		fdf->scale += 1;
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	return (0);
}

int	joom(int keycode, t_fdf *fdf)
{
	if (keycode == 15)
		return (press_key_r(fdf));
	else if (keycode == 3)
		return (press_key_f(fdf));
	else
		return (0);
}

int	translate(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
		return (press_key_left(fdf));
	else if (keycode == 124)
		return (press_key_right(fdf));
	else if (keycode == 125)
		return (press_key_down(fdf));
	else if (keycode == 126)
		return (press_key_up(fdf));
	else
		return (0);
}

int	press(int keycode, t_fdf *fdf)
{
	if (keycode == 13)
		return (press_key_w(fdf));
	else if (keycode == 1)
		return (press_key_s(fdf));
	else if (keycode == 0)
		return (press_key_a(fdf));
	else if (keycode == 2)
		return (press_key_d(fdf));
	else if (keycode == 12)
		return (press_key_q(fdf));
	else if (keycode == 14)
		return (press_key_e(fdf));
	else if (keycode >= 123 && keycode <= 126)
		return (translate(keycode, fdf));
	else if (keycode == 53)
		exit(0);
	else if (keycode >= 18 && keycode <= 20)
		return (parallel(keycode, fdf));
	else
		return (joom(keycode, fdf));
}
