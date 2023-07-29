/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:33:27 by surkim            #+#    #+#             */
/*   Updated: 2023/07/28 16:14:28 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	ft_open(char *filename)
{
	int	fd;
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (ft_strncmp(&filename[i - 4], ".fdf", 5) != 0)
		exit(1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		exit(1);
}

void	free_tmptmp(char **tmptmp)
{
	int	i;

	i = 0;
	while (tmptmp[i])
	{
		free(tmptmp[i]);
		i++;
	}
	free(tmptmp);
}

t_arrdata	**malloc_arr(t_fdf *fdf)
{
	int			i;
	t_arrdata	**rt;

	rt = (t_arrdata **)malloc(sizeof (t_arrdata *) * fdf->size_y);
	if (rt == NULL)
		exit(1);
	i = 0;
	while (i < fdf->size_y)
	{
		rt[i] = (t_arrdata *)malloc(sizeof (t_arrdata) * fdf->size_x);
		if (rt[i] == NULL)
			exit(1);
		i++;
	}
	return (rt);
}
