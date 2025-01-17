/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:55:29 by agruet            #+#    #+#             */
/*   Updated: 2025/01/17 13:54:57 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	syntax_error_msg(void)
{
	ft_fprintf(2, "Syntax Error, run the command with the set you want\n");
	ft_fprintf(2, "Available sets:\t--> Mandelbrot\n\t\t--> Julia\n");
}

int	search_set(char *set)
{
	if (ft_str_equals(set, "Mandelbrot"))
		return (1);
	else if (ft_str_equals(set, "Julia"))
		return (2);
	else
		syntax_error_msg();
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int	set;

	if (ac < 2 || ac > 2)
		return (syntax_error_msg(), 1);
	set = search_set(av[1]);
	if (set == 1)
		mlx(&mandelbrot);
	else if (set == 2)
		mlx(&julia);
	return (EXIT_SUCCESS);
}
