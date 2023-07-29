/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:45:10 by surkim            #+#    #+#             */
/*   Updated: 2023/07/28 20:08:40 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_mlx_init(void)
{
	void	*rt;

	rt = mlx_init();
	if (rt == NULL)
		exit(1);
	return (rt);
}

void	*ft_mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*rt;

	rt = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (rt == NULL)
		exit(1);
	return (rt);
}

void	*ft_mlx_new_image(void *mlx_ptr, int width, int height)
{
	void	*rt;

	rt = mlx_new_image(mlx_ptr, width, height);
	if (rt == NULL)
		exit(1);
	return (rt);
}

char	*ft_mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, \
int *size_line, int *endian)
{
	char	*rt;

	rt = mlx_get_data_addr(img_ptr, bits_per_pixel, size_line, endian);
	if (rt == NULL)
		exit(1);
	return (rt);
}
