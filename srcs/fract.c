/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:01:53 by agruet            #+#    #+#             */
/*   Updated: 2025/01/23 16:13:40 by agruet           ###   ########.fr       */
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

	iterations = 0;
	fract->zx = -2 + (double)fract->x * 4 / img->width;
	fract->zy = -2 + (double)fract->y * 4 / img->height;
	fract->cx = data->data_cx;
	fract->cy = data->data_cy;
	while (fract->zx * fract->zx + fract->zy * fract->zy < 4
		&& iterations < MAX_ITERATIONS)
	{
		xtemp = fract->zx * fract->zx - fract->zy * fract->zy;
		fract->zy = 2 * fract->zx * fract->zy + fract->cy;
		fract->zx = xtemp + fract->cx;
		iterations += 1;
	}
	if (iterations == MAX_ITERATIONS)
		put_pixel_to_img(img, fract->x, fract->y, 0x000000);
	else
		put_pixel_to_img(img, fract->x, fract->y, fract->color * iterations);
}

void	mandelbrot(t_fract *fract, t_img *img, t_data *data)
{
	int		iterations;
	double	xtemp;
	double	x;
	double	y;

	x = 0.0;
	y = 0.0;
	iterations = 0;
	fract->zx = -2 + (double)fract->x * 4 / img->width;
	fract->zy = -2 + (double)fract->y * 4 / img->height;
	while (x * x + y * y < 4 && iterations < 1000)
	{
		xtemp = x * x + y * y + fract->zx;
		y = 2 * x * y + fract->zy;
		fract->zx = xtemp;
		iterations += 1;
	}
	if (iterations == 1000)
		put_pixel_to_img(img, fract->x, fract->y, 0x000000);
	else
		put_pixel_to_img(img, fract->x, fract->y, fract->color * iterations);
}

void	draw_fract(t_data *data)
{
	t_fract	fract;
	int		offset_x;
	int		offset_y;

	data->fract = &fract;
	fract.color = get_color(data->color_range);
	fract.y = (max(data->intitial_height, data->img->height)
			- data->intitial_height) / 2;
	offset_y = fract.y;
	while (fract.y < data->img->height - offset_y)
	{
		fract.x = (max(max(data->intitial_width, data->intitial_height),
					data->img->width)
				- max(data->intitial_width, data->intitial_height)) / 2;
		offset_x = fract.x;
		while (fract.x < data->img->width - offset_x)
		{
			data->set(&fract, data->img, data);
			fract.x += 1;
		}
		fract.y += 1;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img,
		(data->intitial_width - data->img->width) / 2,
		(data->intitial_height - data->img->height) / 2);
}
