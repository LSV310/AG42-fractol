/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agruet <agruet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:20:38 by agruet            #+#    #+#             */
/*   Updated: 2025/01/21 16:25:23 by agruet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_putnbr_long_fd(long n, int fd)
{
	static int	result;
	long		nb;

	result = 0;
	if (n < 0)
	{
		nb = -n;
		write(fd, "-", 1);
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr_long_fd(nb / 10, fd);
	nb = nb % 10 + '0';
	write(fd, &nb, 1);
	result++;
	if (n < 0)
		result++;
	return (result);
}

int	ft_putnbr_double_fd(double n, int fd)
{
	int	count;

	count = ft_putnbr_long_fd((long)n, fd);
	n -= (long)n;
	write(1, "\n.", 2);
	count++;
	printf("%f\n", n);
	n *= 10;
	while (n > 10)
	{
		// printf("%f\n", n);
		usleep(1000000);
		count += ft_putnbr_long_fd((unsigned long)n % 10, fd);
		n -= (unsigned long)n;
		n *= 10;
	}
	write(1, "--------------\n", 15);
	return (count);
}
