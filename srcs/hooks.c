/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:29:33 by agruet            #+#    #+#             */
/*   Updated: 2025/01/23 15:55:29 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (keycode == 65451)
		switch_color(data, 1);
	if (keycode == 65453)
		switch_color(data, -1);
	return (0);
}

int	destroy_hook(t_data *data)
{
	kill_mlx(data, 0);
	return (0);
}
