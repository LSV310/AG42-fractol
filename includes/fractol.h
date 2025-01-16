/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:03:39 by agruet            #+#    #+#             */
/*   Updated: 2025/01/16 16:47:25 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define M_PI 3.14159265358979323846

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		height;
	int		width;
	int		endian;
}	t_data;

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

// mlx
void	mlx(void (*set)(t_fract *, t_data *));
void	put_pixel_to_img(t_data *data, int x, int y, int color);

// fractal
void	draw_fract(void *mlx, void *mlx_win, t_data *img, void (*set)(t_fract *, t_data *));

// set
void	julia(t_fract *fract, t_data *img);
void	mandelbrot(t_fract *fract, t_data *img);

#endif
