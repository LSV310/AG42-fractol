/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:49:56 by agruet            #+#    #+#             */
/*   Updated: 2025/01/23 16:44:37 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	kill_mlx(t_data *data, int exit_code)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->img)
		free(data->img);
	exit(exit_code);
}

t_img	*create_img(t_data *data, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		data->img = NULL;
		kill_mlx(data, 1);
	}
	img->width = width;
	img->height = height;
	img->img = mlx_new_image(data->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	data->img = img;
	return (img);
}

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx(void (*set)(), int width, int height, double cx, double cy)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx, width, height, "Fractol");
	if (!data.mlx_win)
		(free(data.mlx), exit(EXIT_FAILURE));
	data.intitial_width = width;
	data.intitial_height = height;
	data.max_zoomin = MAX_ZOOM;
	data.max_zoomout = min(width, height);
	data.set = (*set);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_mouse_hook(data.mlx_win, &mouse_hook, &data);
	mlx_hook(data.mlx_win, 17, 1L << 3, &destroy_hook, &data);
	create_img(&data, data.max_zoomout, data.max_zoomout);
	data.data_cx = cx;
	data.data_cy = cy;
	data.color_range = 0;
	draw_fract(&data);
	mlx_loop(data.mlx);
}
