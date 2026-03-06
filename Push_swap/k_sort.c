/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:03:28 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/06 23:08:28 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Busca el índice más alto en el stack para saber qué número debe volver a A primero */
static int  get_max_index(t_stack *stack)
{
	int max;

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

/* Encuentra la posición (0, 1, 2...) de un índice específico para decidir si rotar o r-rotar */
static int  get_pos(t_stack *stack, int target_idx)
{
	int pos;

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

/* Devuelve los elementos de B a A en orden descendente para que A quede ordenado */
void	push_back_to_a(t_stack **a, t_stack **b)
{
	int max_idx;
	int pos;
	int size;

	while (*b)
	{
		max_idx = get_max_index(*b);
		pos = get_pos(*b, max_idx);
		size = size_stack(*b);
/* Si el número está en la mitad superior de B, usamos rb */
		if (pos <= size / 2)
		{
			while ((*b)->index != max_idx)
				ra_rb_rr(NULL, b, 1);
		}
/* Si está en la mitad inferior de B, usamos rrb para subirlo más rápido */
		else
		{
			while ((*b)->index != max_idx)
				rra_rrb_rrr(NULL, b, 1);
		}
		pa_pb(a, b, 0); /* Una vez arriba, lo pasamos a A (pa) */
	}
}
/* Algoritmo de Chunks: pasa de A a B creando una estructura de 'reloj de arena' */
void	k_sort(t_stack **a, t_stack **b, int length)
{
	int i;
	int range;

	i = 0;
/* El rango determina cuántos números 'competirán' por entrar en B a la vez */
	if (length <= 100)
		range = 15;
	else
		range = 35;
	while (*a)
	{
/* Si el número es menor que el contador, va directo a B */
		if ((*a)->index <= i)
		{
			pa_pb(a, b, 1);
			i++;
		}
/* Si está dentro del rango, va a B y se manda al fondo con rb */
		else if ((*a)->index <= i + range)
		{
			pa_pb(a, b, 1);
			ra_rb_rr(NULL, b, 1);
			i++;
		}
/* Si es muy grande, rotamos A para buscar uno más pequeño */
		else
			ra_rb_rr(a, NULL, 0);
	}
/* Al terminar, vaciamos B devolviendo todo a A ordenado */
	push_back_to_a(a, b);
}