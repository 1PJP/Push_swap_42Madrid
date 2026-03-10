/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:43:53 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 20:53:38 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;
	int	max_index;

	max_bits = 0;
	max_index = size - 1;
	while (max_index > 0)
	{
		max_index >>= 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	size = size_stack(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra_rb_rr(a, NULL, 0, bench);
			else
				pa_pb(a, b, 1, bench);
			i++;
		}
		while (*b)
			pa_pb(a, b, 0, bench);
		bit++;
	}
}
