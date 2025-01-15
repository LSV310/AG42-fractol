/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:29 by agruet            #+#    #+#             */
/*   Updated: 2025/01/15 14:57:51 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	syntax_error_msg()
{
	ft_fprintf(2, "Syntax Error, run the command with the set you want\n");
	ft_fprintf(2, "Available sets:\t--> Mandelbrot\n\t\t--> Julia\n");
}

void	search_set(char *set)
{
	if (ft_str_equals(set, "Mandelbrot"))
		return ;
	else if (ft_str_equals(set, "Julia"))
		return ;
	else
		syntax_error_msg();
}

int	main(int ac, char **av, char **ep)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	(void)ep;
	if (ac <= 1)
		return (syntax_error_msg(), 1);
	search_set(av[1]);

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (!mlx_win)
		return (1);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	mlx_loop(mlx);
}