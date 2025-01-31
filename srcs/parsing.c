/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:04:46 by agruet            #+#    #+#             */
/*   Updated: 2025/01/31 12:24:52 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_msg(int nb)
{
	if (nb == 0)
	{
		ft_fprintf(2, "Syntax Error, run the command with the set you want\n");
		ft_fprintf(2, "Available sets:\t--> Mandelbrot\n\t\t--> Julia\n");
	}
	else
	{
		ft_printf("Keybinds :\n\tShow this: NUMPAD0\n\tMove right: D\n\t");
		ft_printf("Move left: A\n\tMove up: W\n\tMove down: S\n\t");
		ft_printf("Zoom in: MOUSEWHEEL UP\n\tZoom out: MOUSEWHEEL DOWN\n\t");
		ft_printf("Increase precision: MULTIPLY\n\tReduce precision: DIVIDE");
		ft_printf("Switch colors: ADD/SUBTRACT\n\tMove right: Dn\n\t");
		ft_printf("Keybinds :\n\tShow this: NUMPAD0\n\tMove right: Dn\n\t");
	}
}

int	search_set(char *set)
{
	if (ft_str_equals(set, "Julia"))
		return (1);
	else if (ft_str_equals(set, "Mandelbrot"))
		return (2);
	else if (ft_str_equals(set, "Multibrot"))
		return (3);
	print_msg(0);
	exit(EXIT_FAILURE);
}

double	set_decimal(char *str, int *i)
{
	double	result;
	double	j;

	if (str[*i] == '.')
		(*i)++;
	else
		return (0.0);
	result = 0.0;
	j = 0.1;
	while (ft_isdigit(str[*i]))
	{
		result = result + (str[*i] - '0') * j;
		j /= 10;
		(*i)++;
		if (j < 0.0000000000000001)
			return (2.1);
	}
	return (result);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	result = 0.0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (3.0);
	while (ft_isdigit(str[i]) && result < 2.0)
		result = result * 10 + (str[i++] - '0');
	result += set_decimal(str, &i);
	if (result > 2.0)
		return (2.1);
	if (str[i] != '\0' && str[i] != '\n')
		return (3.0);
	return (result * sign);
}

int	ft_atoi_parsed(char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0' && nptr[i] != '\n')
		return (-1);
	return (result);
}
