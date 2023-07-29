/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:24:29 by surkim            #+#    #+#             */
/*   Updated: 2023/07/29 14:44:50 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_arrsize(t_fdf *fdf, char *filename)
{
	char	*tmp;
	char	**tmptmp;
	int		fd;

	fd = ft_open(filename);
	fdf->size_x = 0;
	fdf->size_y = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (fdf->size_y == 0)
			tmptmp = ft_split(tmp, ' ');
		(fdf->size_y)++;
		free(tmp);
	}
	while (tmptmp[fdf->size_x])
		(fdf->size_x)++;
	free_tmptmp(tmptmp);
	ft_close(fd);
}

void	put_info_into_arr(t_fdf *fdf, char **tmptmp, int y)
{
	int		i;
	char	**tmp;

	i = 0;
	while (i < fdf->size_x)
	{
		fdf->arr[y][i].x = i - fdf->size_x / 2;
		fdf->arr[y][i].y = y - fdf->size_y / 2;
		fdf->arr[y][i].z = ft_atoi(tmptmp[i]);
		fdf->arr[y][i].xx = (double) fdf->arr[y][i].x;
		fdf->arr[y][i].yy = (double) fdf->arr[y][i].y;
		fdf->arr[y][i].zz = (double) fdf->arr[y][i].z;
		tmp = ft_split(tmptmp[i], ',');
		fdf->arr[y][i].color = ft_axtoi(tmp[1]);
		free_tmptmp(tmp);
		i++;
	}
}

void	set_scale_axis(t_fdf *fdf)
{
	if (fdf->size_x > fdf->size_y)
		fdf->scale = (double) 1920 / (double)fdf->size_x / (double) 3;
	else
		fdf->scale = (double) 1080 / (double) fdf->size_y / (double) 3;
	fdf->axis_x = (double) 1920 / (double) 2;
	fdf->axis_y = (double) 1080 / (double) 2;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
}

void	parsing(t_fdf *fdf, char *filename)
{
	int		i;
	int		fd;
	char	*tmp;
	char	**tmptmp;

	get_arrsize(fdf, filename);
	set_scale_axis(fdf);
	fdf->arr = malloc_arr(fdf);
	fd = ft_open(filename);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		tmptmp = ft_split(tmp, ' ');
		free(tmp);
		put_info_into_arr(fdf, tmptmp, i);
		free_tmptmp(tmptmp);
		i++;
	}
	ft_close(fd);
}
