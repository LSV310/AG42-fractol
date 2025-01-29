/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:01:53 by agruet            #+#    #+#             */
/*   Updated: 2025/01/29 17:18:23 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int index)
{
	if (index == 0)
		return (0x01024a);
	else if (index == 1)
		return (0x05024a);
	else if (index == 2)
		return (0x00829b);
	else if (index == 3)
		return (0x0f0084);
	else if (index == 4)
		return (0x402647);
	else if (index == 5)
		return (0x551500);
	return (0);
}

void	julia(t_fract *fract, t_img *img, t_data *data)
{
	int		iterations;
	double	xtemp;
	double	zx;
	double	zy;

	iterations = 0;
	fract->zx = data->x_min + fract->x * (data->x_max - data->x_min) * img->w1;
	fract->zy = data->y_min + fract->y * (data->y_max - data->y_min) * img->h1;
	fract->cx = data->data_cx;
	fract->cy = data->data_cy;
	zx = fract->zx * fract->zx;
	zy = fract->zy * fract->zy;
	while (zx + zy < 4 && iterations < data->max_iterations)
	{
		xtemp = zx - zy;
		fract->zy = 2 * fract->zx * fract->zy + fract->cy;
		fract->zx = xtemp + fract->cx;
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

	iterations = 0;
	x = 0.0;
	y = 0.0;
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
	double	xtemp;
	double	x;
	double	y;
	int		n;

	iterations = 0;
	n = data->data_cx;
	x = data->x_min + fract->x * (data->x_max - data->x_min) * img->w1;
	y = data->y_min + fract->y * (data->y_max - data->y_min) * img->h1;
	while (x * x + y * y < 4 && iterations < data->max_iterations)
	{
		xtemp = pow(x*x + y*y, n * 0.5) * cos(n * atan2(y, x)) + fract->zx;
		y = pow(x*x + y*y, n * 0.5) * sin(n * atan2(y, x)) + fract->zy;
		x = xtemp;
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
