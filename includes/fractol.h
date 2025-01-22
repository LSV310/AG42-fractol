/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:39 by agruet            #+#    #+#             */
/*   Updated: 2025/01/22 18:07:52 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define MAX_ITERATIONS 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		initial_width;
	int		initial_height;
	int		endian;
}	t_img;

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

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	t_fract	*fract;
	int		intitial_width;
	int		intitial_height;
	double	data_cx;
	double	data_cy;
	void	(*set)(t_fract *, t_img *, struct s_data *);
}	t_data;

// parsing
void	syntax_error_msg(int code);
int		search_set(char *set);
double	ft_atof(char *str);

// mlx
void	mlx(void (*set)(), int width, int height, double cx, double cy);
t_img	*create_img(t_data *data, int width, int height);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
void	kill_mlx(t_data *data, int exit_code);

// hooks
int		mouse_hook(int button, int x, int y, t_data *data);
int		key_hook(int keycode, t_data *data);
int		destroy_hook(t_data *data);

// fractal
void	draw_fract(t_data *data);

// set
void	julia(t_fract *fract, t_img *img, t_data *data);
void	mandelbrot(t_fract *fract, t_img *img, t_data *data);

// maths
int		max(int a, int b);
int		min(int a, int b);

#endif
