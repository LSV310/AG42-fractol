/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:29:33 by agruet            #+#    #+#             */
/*   Updated: 2025/01/23 11:07:38 by agruet           ###   ########.fr       */
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

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
		zoom_in(data);
	else if (button == 5)
		zoom_out(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		kill_mlx(data, 0);
	return (0);
}

int	destroy_hook(t_data *data)
{
	kill_mlx(data, 0);
	return (0);
}
