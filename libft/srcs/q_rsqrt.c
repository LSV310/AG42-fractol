/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rsqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:51:14 by agruet            #+#    #+#             */
/*   Updated: 2025/01/29 11:55:23 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	q_rsqrt(double number)
{
	long	i;
	double	x2;
	double	y;
	double	threehalfs;

	threehalfs = number * 1.5;
	x2 = number * 0.5;
	y = number;
	i = *(long *) &y;
	i = 0x5f3759df - (i >> 1);
	y = *(double *) &i;
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}
