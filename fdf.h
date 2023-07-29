/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:47:42 by surkim            #+#    #+#             */
/*   Updated: 2023/07/29 17:14:32 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}t_gnl;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_arrdata
{
	int		x;
	int		y;
	int		z;
	double	xx;
	double	yy;
	double	zz;
	double	screen_x;
	double	screen_y;
	int		color;
}t_arrdata;

typedef struct s_fdf
{
	int			size_x;
	int			size_y;
	void		*mlx;
	void		*mlx_win;
	double		scale;
	int			axis_x;
	int			axis_y;
	int			min_z;
	int			max_z;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	t_data		img;
	t_arrdata	**arr;
	t_arrdata	**xy;
	t_arrdata	**yz;
	t_arrdata	**zx;
}t_fdf;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
void		remove_list(t_gnl **head, int fd);
char		*ft_free(t_gnl **list, char **s1, char *s2, int fd);
char		*ft_strjoin(char *s1, char *s2, size_t s1_len, size_t s2_len);
char		*ft_strchr(char *s, int c);
char		*get_next_line(int fd);
int			ft_atoi(const char *str);
int			ft_axtoi(char *str);
char		**ft_split(char const *s, char c);
t_arrdata	**malloc_arr(t_fdf *fdf);
int			ft_open(char *filename);
void		ft_close(int fd);
void		free_tmptmp(char **tmptmp);
void		parsing(t_fdf *fdf, char *filename);
double		ft_sin(double angle);
double		ft_cos(double angle);
void		rotate_z(t_fdf *fdf, double angle);
void		rotate_y(t_fdf *fdf, double angle);
void		rotate_x(t_fdf *fdf, double angle);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		connect_dot(t_fdf *fdf);
void		draw(t_fdf *fdf);
int			press_key_w(t_fdf *fdf);
int			press_key_s(t_fdf *fdf);
int			press_key_a(t_fdf *fdf);
int			press_key_d(t_fdf *fdf);
int			press_key_q(t_fdf *fdf);
int			press_key_e(t_fdf *fdf);
int			press_key_up(t_fdf *fdf);
int			press_key_down(t_fdf *fdf);
int			press_key_left(t_fdf *fdf);
int			press_key_right(t_fdf *fdf);
int			press(int keycode, t_fdf *fdf);
void		*ft_mlx_init(void);
void		*ft_mlx_new_window(void *mlx_ptr, int size_x, \
int size_y, char *title);
void		*ft_mlx_new_image(void *mlx_ptr, int width, int height);
char		*ft_mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, \
int *size_line, int *endian);
void		copy_arr(t_fdf *fdf, t_arrdata **a, t_arrdata **b);
int			parallel(int keycode, t_fdf *fdf);

#endif