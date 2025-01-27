/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:39 by agruet            #+#    #+#             */
/*   Updated: 2025/01/27 14:53:51 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 500
# endif

# ifndef ZOOM_FACTOR
#  define ZOOM_FACTOR 1.05
# endif

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1010
# endif

typedef struct s_fract
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
}	t_fract;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	t_fract	*fract;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	data_cx;
	double	data_cy;
	void	(*set)(t_fract *, t_img *, struct s_data *);
	int		color_range;
	int		win_width;
	int		win_height;
}	t_data;

// parsing
void	error_msg(int code);
int		search_set(char *set);
double	ft_atof(char *str);

// mlx
void	mlx(void (*set)(), int width, int height, double cx, double cy);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
void	kill_mlx(t_data *data, int exit_code);

// hooks
int		mouse_hook(int button, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
int		destroy_hook(t_data *data);

// fractals
void	draw_fract(t_data *data);
void	julia(t_fract *fract, t_img *img, t_data *data);
void	mandelbrot(t_fract *fract, t_img *img, t_data *data);
void	multibrot(t_fract *fract, t_img *img, t_data *data);

// events
void	zoom_in(t_data *data, int x, int y);
void	zoom_out(t_data *data, int x, int y);
void	switch_color(t_data *data, int next);

#endif
