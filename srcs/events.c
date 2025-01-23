/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:37 by agruet            #+#    #+#             */
/*   Updated: 2025/01/23 16:12:10 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data)
{
	t_img	*img;

	img = data->img;
	if (img->width == data->max_zoomin
		&& img->height == data->max_zoomin)
		return ;
	img->width = img->width * 1.05;
	img->height = img->height * 1.05;
	if (img->width > data->max_zoomin || img->height > data->max_zoomin)
	{
		img->width = data->max_zoomin;
		img->height = data->max_zoomin;
	}
	mlx_destroy_image(data->mlx, img->img);
	create_img(data, img->width, img->height);
	free(img);
	mlx_clear_window(data->mlx, data->mlx_win);
	draw_fract(data);
}

void	zoom_out(t_data *data)
{
	t_img	*img;

	img = data->img;
	if (img->width == data->max_zoomout
		&& img->height == data->max_zoomout)
		return ;
	img->width = img->width * 0.95;
	img->height = img->height * 0.95;
	if (img->width < data->max_zoomout
		|| img->height < data->max_zoomout)
	{
		img->width = data->max_zoomout;
		img->height = data->max_zoomout;
	}
	mlx_destroy_image(data->mlx, img->img);
	create_img(data, img->width, img->height);
	free(img);
	mlx_clear_window(data->mlx, data->mlx_win);
	draw_fract(data);
}

void	switch_color(t_data *data, int next)
{
	if (next == 1 && data->color_range >= 5
		|| next == -1 && data->color_range <= 0)
		return ;
	data->color_range = data->color_range + next;
	draw_fract(data);
}
