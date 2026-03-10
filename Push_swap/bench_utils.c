/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/03/10 21:10:34 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	print_float(float f, int fd)
{
	int	integer;
	int	decimal;

	integer = (int)f;
	decimal = (int)((f - integer) * 100);
	ft_putnbr_fd(integer, fd);
	write(fd, ".", 1);
	if (decimal < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal, fd);
}

char	*get_strategy_name(int flag, float disorder)
{
	if (flag == 1)
		return ("Simple / O(n^2)");
	if (flag == 2)
		return ("Medium / O(n*sqrt(n))");
	if (flag == 3)
		return ("Complex / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n)");
	if (disorder < 0.5)
		return ("Adaptive / O(n*sqrt(n))");
	return ("Adaptive / O(n log n)");
}
