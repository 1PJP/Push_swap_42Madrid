/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:03:28 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08                               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Busca el índice más alto en el stack para saber qué número debe volver a A primero */
static int	get_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

/* Encuentra la posición (0, 1, 2...) de un índice específico
   para decidir si rotar o reverse rotar */
static int	get_pos(t_stack *stack, int target_idx)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_idx)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

/* Devuelve los elementos de B a A en orden descendente para que A quede ordenado.
   Usa rb o rrb segun si el maximo esta en la mitad superior o inferior */
void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_idx;
	int	pos;
	int	size;

	while (*b)
	{
		max_idx = get_max_index(*b);
		pos = get_pos(*b, max_idx);
		size = size_stack(*b);
		if (pos <= size / 2) /* mitad superior → rb */
		{
			while ((*b)->index != max_idx)
				ra_rb_rr(NULL, b, 1, bench);
		}
		else /* mitad inferior → rrb mas rapido */
		{
			while ((*b)->index != max_idx)
				rra_rrb_rrr(NULL, b, 1, bench);
		}
		pa_pb(a, b, 0, bench); /* una vez arriba lo pasamos a A */
	}
}

/* Algoritmo de Chunks O(n*sqrt(n)): divide los indices en rangos y pasa
   los elementos a B en orden, luego los devuelve a A ordenados */
void	k_sort(t_stack **a, t_stack **b, int length, t_bench *bench)
{
	int	i;
	int	range;

	i = 0;
	if (length <= 100) /* rango optimo para 100 elementos */
		range = 15;
	else /* rango optimo para 500 elementos */
		range = 35;
	while (*a)
	{
		if ((*a)->index <= i) /* indice menor que contador → va directo a B */
		{
			pa_pb(a, b, 1, bench);
			i++;
		}
		else if ((*a)->index <= i + range) /* dentro del rango → va a B al fondo */
		{
			pa_pb(a, b, 1, bench);
			ra_rb_rr(NULL, b, 1, bench);
			i++;
		}
		else /* muy grande → rotamos A buscando uno mas pequeño */
			ra_rb_rr(a, NULL, 0, bench);
	}
	push_back_to_a(a, b, bench); /* vaciamos B devolviendo todo a A ordenado */
}