/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:01:53 by agruet            #+#    #+#             */
/*   Updated: 2025/01/19 17:07:19 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fract *fract, t_img *img)
{
	int		iterations;
	double	xtemp;

	iterations = 0;
	fract->zx = -2 + (double)fract->x * 4 / img->width;
	fract->zy = -2 + (double)fract->y * 4 / img->height;
	fract->cx = 0.3;
	fract->cy = 0.0;
	while (fract->zx * fract->zx + fract->zy * fract->zy < 4 && iterations < 1000)
	{
		xtemp = fract->zx * fract->zx - fract->zy * fract->zy;
		fract->zy = 2 * fract->zx * fract->zy + fract->cy;
		fract->zx = xtemp + fract->cx;
		iterations += 1;
	}
	if (iterations == 1000)
		put_pixel_to_img(img, fract->x, fract->y, 0x000000);
	else
		put_pixel_to_img(img, fract->x, fract->y, fract->color * iterations);
}

void	mandelbrot(t_fract *fract, t_img *img)
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

	data->fract = &fract;
	fract.color = 0xFCBE11;
	fract.y = 0;
	while (fract.y < data->img->height)
	{
		fract.x = 0;
		while (fract.x < data->img->width)
		{
			data->set(&fract, data->img);
			fract.x += 1;
		}
		fract.y += 1;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
}
