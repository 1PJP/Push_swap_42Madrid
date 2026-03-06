/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:55:20 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/07 00:17:01 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int size;

	size = size_stack(*a);
	add_index(*a); //importante llamar a esto primero
	if (is_sorted(*a) || size <= 1)
		return ;
	if (size == 2)
		sa_sb(a, b, 0);
	else if (size == 3)
		tiny_sort(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (size <= 100)
		k_sort(a, b, size); // El intermedio
	else
		k_sort(a, b, size); // El complejo, se puede usar tambien
}

void	tiny_sort(t_stack **a)
{
	int first;
	int second;
	int third;

// Guardamos los valores para que el código sea más fácil de leer
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
// CASO: 2 1 3 (El primero es mayor que el segundo, pero menor que el tercero)
// Solución: Solo un swap (sa) -> 1 2 3
	if (first > second && second < third && first < third)
		sa_sb(a, NULL, 0);
// CASO: 3 2 1 (Orden totalmente inverso)
// Solución: swap (sa) para dejarlo 2 3 1, luego reverse rotate (rra) -> 1 2 3
	else if (first > second && second > third)
	{
		sa_sb(a, NULL, 0);
		rra_rrb_rrr(a, NULL, 0);
	}
	// CASO: 3 1 2 (El primero es el más grande y el segundo el más pequeño)
	// Solución: rotate (ra) para mandar el 3 al fondo -> 1 2 3
	else if (first > second && second < third && first > third)
		ra_rb_rr(a, NULL, 0);
	// CASO: 1 3 2 (El segundo es el más grande)
	// Solución: swap (sa) para dejarlo 3 1 2, luego rotate (ra) -> 1 2 3
	else if (first < second && second > third && first < third)
	{
		sa_sb(a, NULL, 0);
		ra_rb_rr(a, NULL, 0);
	}
// CASO: 2 3 1 (El tercero es el más pequeño)
// Solución: reverse rotate (rra) para subir el 1 al principio -> 1 2 3
	else if (first < second && second > third && first > third)
		rra_rrb_rrr(a, NULL, 0);
//Si no entra en ningún if, es que ya está ordenado (1 2 3)
}
/* Algoritmo para 5 números, pasamos los 2 más pequeños a B y ordenamos los 3 de A */
void	sort_five(t_stack **a, t_stack **b)
{
	while (size_stack(*a) > 3)
	{
/* Buscamos los índices 0 y 1 que son los valores más bajos */
		if ((*a)->index == 0 || (*a)->index == 1)
			pa_pb(a, b, 1);
		else
			ra_rb_rr(a, NULL, 0);
	}
	tiny_sort(a); /* Ordenamos los 3 que quedan */
	while (*b)
		pa_pb(a, b, 0); /* Devolvemos los 2 pequeños a A */
/* Si el primero es mayor que el segundo (ej: index 1 y luego 0), hacemos swap */
	if ((*a)->index > (*a)->next->index)
		sa_sb(a, NULL, 0);
}