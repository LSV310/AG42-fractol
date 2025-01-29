/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:55 by agruet            #+#    #+#             */
/*   Updated: 2025/01/28 14:15:02 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	go_up(t_data *data)
{
	double	shift;

	shift = (data->y_max - data->y_min) * MOVE_FACTOR;
	data->y_min -= shift;
	data->y_max -= shift;
	draw_fract(data);
}

void	go_down(t_data *data)
{
	double	shift;

	shift = (data->y_max - data->y_min) * MOVE_FACTOR;
	data->y_min += shift;
	data->y_max += shift;
	draw_fract(data);
}

void	go_left(t_data *data)
{
	double	shift;

	shift = (data->x_max - data->x_min) * MOVE_FACTOR;
	data->x_min -= shift;
	data->x_max -= shift;
	draw_fract(data);
}

void	go_right(t_data *data)
{
	double	shift;

	shift = (data->x_max - data->x_min) * MOVE_FACTOR;
	data->x_min += shift;
	data->x_max += shift;
	draw_fract(data);
}
