/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:47:32 by surkim            #+#    #+#             */
/*   Updated: 2023/07/29 16:26:58 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->mlx = ft_mlx_init();
	fdf->mlx_win = ft_mlx_new_window(fdf->mlx, 1920, 1080, "fdf");
	fdf->img.img = ft_mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->img.addr = ft_mlx_get_data_addr(fdf->img.img, \
	&(fdf->img.bits_per_pixel), &(fdf->img.line_length), &(fdf->img.endian));
}

void	copy_arr(t_fdf *fdf, t_arrdata **a, t_arrdata **b)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->size_y)
	{
		j = 0;
		while (j < fdf->size_x)
		{
			a[i][j] = b[i][j];
			j++;
		}
		i++;
	}
}

void	save_data(t_fdf *fdf)
{
	fdf->xy = malloc_arr(fdf);
	fdf->yz = malloc_arr(fdf);
	fdf->zx = malloc_arr(fdf);
	copy_arr(fdf, fdf->xy, fdf->arr);
	rotate_x(fdf, 90);
	copy_arr(fdf, fdf->zx, fdf->arr);
	rotate_x(fdf, -90);
	rotate_y(fdf, 90);
	copy_arr(fdf, fdf->yz, fdf->arr);
	rotate_y(fdf, -90);
}

int	xbutton(int keycode, t_fdf *fdf)
{
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		exit(1);
	fdf_init(&fdf);
	parsing(&fdf, argv[1]);
	save_data(&fdf);
	rotate_x(&fdf, 90);
	rotate_y(&fdf, 45);
	rotate_x(&fdf, -35.264);
	draw(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
	mlx_hook(fdf.mlx_win, 17, 0, xbutton, &fdf);
	mlx_hook(fdf.mlx_win, 2, 1L << 0, press, &fdf);
	mlx_loop(fdf.mlx);
	exit(0);
}
