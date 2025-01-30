/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tune_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:39:47 by agruet            #+#    #+#             */
/*   Updated: 2025/01/30 16:54:42 by agruet           ###   ########.fr       */
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

void	add_head(t_data *data)
{
	if (data->set_index == 2)
		data->cx++;
	draw_fract(data);
}

void	del_head(t_data *data)
{
	if (data->set_index == 2 && data->cx > 0)
		data->cx--;
	draw_fract(data);
}

void	increase_complex(t_data *data)
{
	if (data->set_index != 0)
		return;
	if (data->cx + 0.1 <= 2)
		data->cx += 0.1;
	else
		data->cx = data->cx + 0.1 - 4.0;
	if (data->cy + 0.1 <= 2)
		data->cy += 0.1;
	else
		data->cy = data->cy + 0.1 - 4.0;
	draw_fract(data);
}

void	decrease_complex(t_data *data)
{
	if (data->set_index != 0)
		return;
	if (data->cx - 0.1 >= -2)
		data->cx -= 0.1;
	else
		data->cx = data->cx - 0.1 + 4.0;
	if (data->cy - 0.1 >= -2)
		data->cy -= 0.1;
	else
		data->cy = data->cy - 0.1 + 4.0;
	draw_fract(data);
}
