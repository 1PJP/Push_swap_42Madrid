/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:11:36 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08                               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Busca la posición del índice mínimo en el stack.
   Recorre toda la lista y devuelve la posición (0, 1, 2...) del menor índice */
static int	get_min_pos(t_stack *a)
{
	int		pos;
	int		min_pos;
	int		min_idx;

	pos = 0;
	min_pos = 0;
	min_idx = a->index;
	while (a)
	{
		if (a->index < min_idx)
		{
			min_idx = a->index;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}

/* Insertion sort adaptado a push_swap. O(n^2)
   En cada pasada sube el mínimo al tope usando ra o rra segun posicion
   lo manda a B con pb, al final devuelve todo a A en orden con pa */
void	insertion_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	half;

	while (size_stack(*a) > 0)
	{
		pos = get_min_pos(*a);
		half = size_stack(*a) / 2;
		if (pos <= half) // el minimo esta en la mitad superior, usamos ra
		{
			while (get_min_pos(*a) != 0)
				ra_rb_rr(a, NULL, 0, bench);
		}
		else // el minimo esta en la mitad inferior, usamos rra
		{
			while (get_min_pos(*a) != 0)
				rra_rrb_rrr(a, NULL, 0, bench);
		}
		pa_pb(a, b, 1, bench); // mandamos el minimo a B
	}
	while (*b)
		pa_pb(a, b, 0, bench); // devolvemos todo a A en orden
}