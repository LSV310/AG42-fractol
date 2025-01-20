/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:04:46 by agruet            #+#    #+#             */
/*   Updated: 2025/01/20 17:31:16 by agruet           ###   ########.fr       */
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

double	set_decimal(char *str, int *i)
{
	double	result;

	if (str[*i] == '.')
		(*i)++;
	else
		return (0.0);
}

double	ft_atoi_double(char *str)
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
	if (str[i] == '\0')
		return ((long)INT_MAX + 1);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return ((long)INT_MAX + 1);
	}
	result += set_decimal(str, &i);
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		return ((long)INT_MAX + 1);
	return (result * sign);
}
