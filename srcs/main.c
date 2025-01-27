/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:29 by agruet            #+#    #+#             */
/*   Updated: 2025/01/27 16:02:32 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_julia(int ac, char **av)
{
	double	cx;
	double	cy;

	if (ac != 4)
	{
		if (ac < 4)
			ft_fprintf(2, "Syntax Error, missing arguments\n");
		else
			ft_fprintf(2, "Syntax Error, too many arguments\n");
		ft_fprintf(2, "Prototype: ./fractol julia ");
		ft_fprintf(2, "<decimal part> <imaginary part>\n");
		exit(EXIT_FAILURE);
	}
	cx = ft_atof(av[2]);
	cy = ft_atof(av[3]);
	if (cx == 3.0)
		(ft_fprintf(2, "Syntax Error, wrong real part\n"), exit(1));
	if (cx == 2.1)
		(ft_fprintf(2, "Syntax Error, real part too big\n"), exit(1));
	if (cy == 3.0)
		(ft_fprintf(2, "Syntax Error, wrong imaginary part\n"), exit(1));
	if (cy == 2.1)
		(ft_fprintf(2, "Syntax Error, imaginary part too big\n"), exit(1));
	mlx(&julia, WIDTH, HEIGHT, cx, cy);
}

void	start_mandelbrot(int ac)
{
	if (ac > 2)
	{
		ft_fprintf(2, "Syntax Error, too many arguments\n");
		exit(EXIT_FAILURE);
	}
	mlx(&mandelbrot, WIDTH, HEIGHT, 0, 0);
}

void	start_multibrot(int ac, char **av)
{
	if (ac < 3)
		(ft_fprintf(2, "Syntax Error, missing argument\n"), exit(1));
	if (ac > 3)
		(ft_fprintf(2, "Syntax Error, too many arguments\n"), exit(1));
	mlx(&multibrot, WIDTH, HEIGHT, ft_atoi(av[2]), 0);
}

int	main(int ac, char **av)
{
	int		set;

	if (ac < 2)
		return (syntax_error_msg(), 1);
	set = search_set(av[1]);
	if (set == 1)
		start_julia(ac, av);
	else if (set == 2)
		start_mandelbrot(ac);
	else if (set == 3)
		start_multibrot(ac, av);
	return (EXIT_SUCCESS);
}
