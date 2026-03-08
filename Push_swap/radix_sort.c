/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:43:53 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08 21:40:29 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calcula cuántos bits necesitamos para representar el índice más grande.
   Si tenemos 8 elementos, el índice máximo es 7 (111 en binario) → 3 bits.
   Esto nos da la cantidad de pasadas que hay que hacer. */
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

/* Algoritmo Radix Sort LSD adaptado a push_swap. O(n log n)
   Por cada bit: si es 0 → pb, si es 1 → ra
   Al acabar cada pasada devuelve todo B a A con pa */
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
			if (((*a)->index >> bit) & 1) // bit es 1 → se queda en A
				ra_rb_rr(a, NULL, 0, bench);
			else                          // bit es 0 → va a B
				pa_pb(a, b, 1, bench);
			i++;
		}
		while (*b)
			pa_pb(a, b, 0, bench);
		bit++;
	}
}