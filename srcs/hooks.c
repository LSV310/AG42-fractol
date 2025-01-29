/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:29:33 by agruet            #+#    #+#             */
/*   Updated: 2025/01/28 11:37:05 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
		zoom_in(data, x, y);
	else if (button == 5)
		zoom_out(data, x, y);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		kill_mlx(data, EXIT_SUCCESS);
	else if (keycode == 65451)
		switch_color(data, 1);
	else if (keycode == 65453)
		switch_color(data, -1);
	else if (keycode == 65450)
		increase_precision(data);
	else if (keycode == 65455)
		reduce_precision(data);
	else if (keycode == 119)
		go_up(data);
	else if (keycode == 115)
		go_down(data);
	else if (keycode == 100)
		go_right(data);
	else if (keycode == 97)
		go_left(data);
	return (0);
}

int	destroy_hook(t_data *data)
{
	kill_mlx(data, EXIT_SUCCESS);
	return (0);
}
