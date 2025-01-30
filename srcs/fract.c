/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:01:53 by agruet            #+#    #+#             */
/*   Updated: 2025/01/30 16:45:06 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fract *fract, t_img *img, t_data *data)
{
	int		iterations;
	double	xtemp;
	double	zx;
	double	zy;

	data->set_index = 0;
	iterations = 0;
	fract->zx = data->x_min + fract->x * (data->x_max - data->x_min) * img->w1;
	fract->zy = data->y_min + fract->y * (data->y_max - data->y_min) * img->h1;
	zx = fract->zx * fract->zx;
	zy = fract->zy * fract->zy;
	while (zx + zy < 4 && iterations < data->max_iterations)
	{
		xtemp = zx - zy;
		fract->zy = 2 * fract->zx * fract->zy + data->cy;
		fract->zx = xtemp + data->cx;
		iterations++;
		zx = fract->zx * fract->zx;
		zy = fract->zy * fract->zy;
	}
	if (iterations == data->max_iterations)
		put_pixel_to_img(img, fract->x, fract->y, 0x000000);
	else
		put_pixel_to_img(img, fract->x, fract->y, fract->color * iterations);
}

void	mandelbrot(t_fract *fract, t_img *img, t_data *data)
{
	int		iterations;
	double	x;
	double	y;
	double	x2;
	double	y2;

	data->set_index = 1;
	iterations = 0;
	x = ((y = 0.0));
	x2 = 0.0;
	y2 = 0.0;
	fract->zx = data->x_min + fract->x * (data->x_max - data->x_min) * img->w1;
	fract->zy = data->y_min + fract->y * (data->y_max - data->y_min) * img->h1;
	while (x2 + y2 < 4 && iterations < data->max_iterations)
	{
		y = 2 * x * y + fract->zy;
		x = x2 - y2 + fract->zx;
		x2 = x * x;
		y2 = y * y;
		iterations += 1;
	}
	if (iterations == data->max_iterations)
		put_pixel_to_img(img, fract->x, fract->y, 0x000000);
	else
		put_pixel_to_img(img, fract->x, fract->y, fract->color * iterations);
}

void	multibrot(t_fract *fract, t_img *img, t_data *data)
{
	int		iterations;
	double	x;
	double	y;
	double	xy;
	double	atan_val;

	data->set_index = 2;
	iterations = 0;
	x = ((y = (xy = 0.0)));
	fract->zx = data->x_min + fract->x * (data->x_max - data->x_min) * img->w1;
	fract->zy = data->y_min + fract->y * (data->y_max - data->y_min) * img->h1;
	while (xy < 4 && iterations < data->max_iterations)
	{
		atan_val = data->cx * atan2(y, x);
		x = pow(xy, data->cx * 0.5) * cos(atan_val) + fract->zx;
		y = pow(xy, data->cx * 0.5) * sin(atan_val) + fract->zy;
		xy = x * x + y * y;
		iterations += 1;
	}
	if (iterations == data->max_iterations)
		put_pixel_to_img(img, fract->x, fract->y, 0x000000);
	else
		put_pixel_to_img(img, fract->x, fract->y, fract->color * iterations);
}

void	draw_fract(t_data *data)
{
	t_fract	fract;

	fract.color = get_color(data->color_range);
	fract.y = 0;
	while (fract.y < data->img->height)
	{
		fract.x = 0;
		while (fract.x < data->img->width)
		{
			data->set(&fract, data->img, data);
			fract.x++;
		}
		fract.y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
}
