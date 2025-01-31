/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tune_fractal2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:44:43 by agruet            #+#    #+#             */
/*   Updated: 2025/01/31 11:21:51 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_precision(t_data *data)
{
	char	*gnl;
	int		iterations;

	ft_fprintf(0, "iterations > ");
	gnl = get_next_line(0);
	iterations = ft_atoi_parsed(gnl);
	free(gnl);
	if (iterations <= 0)
	{
		ft_fprintf(2, "Syntax Error\n");
		return ;
	}
	data->max_iterations = iterations;
	draw_fract(data);
}

int	parse_complex(double *cx, double *cy, char **split)
{
	int	len;

	len = tab_len(split);
	if (len < 2 || len > 2)
	{
		if (len < 2)
			ft_fprintf(2, "Syntax Error, missing arguments\n");
		else if (len > 2)
			ft_fprintf(2, "Syntax Error, too many arguments\n");
		ft_fprintf(2, "Prototype: ./fractol julia ");
		ft_fprintf(2, "<decimal part> <imaginary part>\n");
		return (0);
	}
	*cx = ft_atof(split[0]);
	*cy = ft_atof(split[1]);
	if (*cx == 3.0)
		return (ft_fprintf(2, "Syntax Error, wrong real part\n"), 0);
	if (*cx == 2.1)
		return (ft_fprintf(2, "Syntax Error, real part too big\n"), 0);
	if (*cy == 3.0)
		return (ft_fprintf(2, "Syntax Error, wrong imaginary part\n"), 0);
	if (*cy == 2.1)
		return (ft_fprintf(2, "Syntax Error, imaginary part too big\n"), 0);
	return (1);
}

void	set_complex(t_data *data)
{
	char	*gnl;
	char	**split;
	double	cx;
	double	cy;

	if (data->set_index != 0)
		return ;
	ft_fprintf(0, "complex > ");
	gnl = get_next_line(0);
	split = ft_split(gnl, ' ');
	if (!split)
		kill_mlx(data, 1);
	free(gnl);
	if (parse_complex(&cx, &cy, split))
	{
		free_tab(split, 0);
		data->cx = cx;
		data->cy = cy;
		draw_fract(data);
		return ;
	}
	free_tab(split, 0);
}
