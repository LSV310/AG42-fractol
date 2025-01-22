/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:29 by agruet            #+#    #+#             */
/*   Updated: 2025/01/22 18:13:07 by agruet           ###   ########.fr       */
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
		mlx(&mandelbrot, 1920, 1080, 0, 0);
	else if (set == 2)
	{
		if (ac < 4)
			(syntax_error_msg(1), exit(EXIT_FAILURE));
		cx = ft_atof(av[2]);
		cy = ft_atof(av[3]);
		if (cx == 3.0 || cy == 3.0)
			(ft_fprintf(2, "Syntax error\n"), exit(EXIT_FAILURE));
		if (cx == 2.1 || cy == 2.1)
			(ft_fprintf(2, "Number too big.\n"), exit(EXIT_FAILURE));
		ft_printf("%f + %fi\n", cx, cy);
		mlx(&julia, 1920, 1080, cx, cy);
	}
	return (EXIT_SUCCESS);
}
