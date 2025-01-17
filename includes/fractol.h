/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:39 by agruet            #+#    #+#             */
/*   Updated: 2025/01/17 15:37:03 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define M_PI 3.14159265358979323846

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		height;
	int		width;
	int		endian;
}	t_img;

typedef struct	s_fract
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
}	t_fract;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	t_fract	*fract;
	void	(*set)(t_fract *, t_img *);
}	t_data;

// mlx
void	mlx(void (*set)(t_fract *, t_img *));
t_img	*create_img(t_data *data, int width, int height);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
void	kill_mlx(t_data *data, int exit_code);

// hooks
int		mouse_hook(int button, int x, int y, void *param);
int		key_hook(int keycode, void *param);

// fractal
void	draw_fract(t_data *data);

// set
void	julia(t_fract *fract, t_img *img);
void	mandelbrot(t_fract *fract, t_img *img);

#endif
