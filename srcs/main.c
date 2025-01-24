/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:29 by agruet            #+#    #+#             */
/*   Updated: 2025/01/24 17:27:31 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int		set;
	double	cx;
	double	cy;

	if (ac < 2 || ac > 5)
		return (syntax_error_msg(0), 1);
	set = search_set(av[1]);
	if (set == 1)
	{
		if (ac < 4)
			(syntax_error_msg(1), exit(EXIT_FAILURE));
		cx = ft_atof(av[2]);
		cy = ft_atof(av[3]);
		if (cx == 3.0 || cy == 3.0)
			(ft_fprintf(2, "Syntax error\n"), exit(EXIT_FAILURE));
		if (cx == 2.1 || cy == 2.1)
			(ft_fprintf(2, "Number too big.\n"), exit(EXIT_FAILURE));
		mlx(&julia, 960, 540, cx, cy);
	}
	else if (set == 2)
		mlx(&mandelbrot, 960, 540, 0, 0);
	else if (set == 3)
		mlx(&multibrot, 1920, 1010, ft_atoi(av[2]), 0);
	return (EXIT_SUCCESS);
}
