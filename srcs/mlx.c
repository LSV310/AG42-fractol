/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:49:56 by agruet            #+#    #+#             */
/*   Updated: 2025/01/16 16:14:05 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mlx(void (*set)(t_fract *, t_data *))
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (!mlx_win)
		(free(mlx), exit(EXIT_FAILURE));
	img.width = 1920;
	img.height = 1080;
	img.img = mlx_new_image(mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	draw_fract(mlx, mlx_win, &img, (*set));
	mlx_loop(mlx);
}
