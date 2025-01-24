/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:26:37 by agruet            #+#    #+#             */
/*   Updated: 2025/01/24 13:00:33 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data, int x, int y)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = data->x_min + x * (data->x_max - data->x_min) / data->img->width;
	mouse_i = data->y_min + y * (data->y_max - data->y_min) / data->img->height;
	data->x_min = mouse_r + (data->x_min - mouse_r) / ZOOM_FACTOR;
	data->x_max = mouse_r + (data->x_max - mouse_r) / ZOOM_FACTOR;
	data->y_min = mouse_i + (data->y_min - mouse_i) / ZOOM_FACTOR;
	data->y_max = mouse_i + (data->y_max - mouse_i) / ZOOM_FACTOR;
	draw_fract(data);
}

void	zoom_out(t_data *data, int x, int y)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = data->x_min + x * (data->x_max - data->x_min) / data->img->width;
	mouse_i = data->y_min + y * (data->y_max - data->y_min) / data->img->height;
	data->x_min = mouse_r + (data->x_min - mouse_r) * ZOOM_FACTOR;
	data->x_max = mouse_r + (data->x_max - mouse_r) * ZOOM_FACTOR;
	data->y_min = mouse_i + (data->y_min - mouse_i) * ZOOM_FACTOR;
	data->y_max = mouse_i + (data->y_max - mouse_i) * ZOOM_FACTOR;
	draw_fract(data);
}

void	switch_color(t_data *data, int next)
{
	if ((next == 1 && data->color_range >= 5)
		|| (next == -1 && data->color_range <= 0))
		return ;
	data->color_range = data->color_range + next;
	draw_fract(data);
}
