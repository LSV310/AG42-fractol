/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:29:33 by agruet            #+#    #+#             */
/*   Updated: 2025/01/17 16:07:44 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *data, int direction)
{
	t_img	*img;

	img = data->img;
	if (direction == 1)
	{
		if (img->width < 2000 && img->height < 2000)
		{
			mlx_destroy_image(data->mlx, img->img);
			create_img(data, img->width * 1.05, img->height * 1.05);
			free(img);
			mlx_clear_window(data->mlx, data->mlx_win);
			draw_fract(data);
		}
	}
	else
	{
		if (img->width > 100 && img->height > 100)
		{
			mlx_destroy_image(data->mlx, img->img);
			create_img(data, img->width * 0.95, img->height * 0.95);
			free(img);
			mlx_clear_window(data->mlx, data->mlx_win);
			draw_fract(data);
		}
	}
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 4)
		zoom(data, 1);
	else if (button == 5)
		zoom(data, 0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		kill_mlx(data, 0);
	return (0);
}
