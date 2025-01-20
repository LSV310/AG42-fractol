/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:29 by agruet            #+#    #+#             */
/*   Updated: 2025/01/20 17:04:53 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int		set;
	double	cx;
	double	cy;

	if (ac < 2 || ac > 5)
		return (syntax_error_msg(), 1);
	set = search_set(av[1]);
	cx = ft_atoi(av[2]);
	cy = ft_atoi(av[3]);
	if (set == 1)
		mlx(&mandelbrot, 1920, 1080);
	else if (set == 2)
		mlx(&julia, 1000, 1000);
	return (EXIT_SUCCESS);
}
