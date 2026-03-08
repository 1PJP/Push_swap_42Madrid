/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotative_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:54:18 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08                               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* movemos el primer nodo al final de la lista
   ejemplo: 1 2 3 4 -> 2 3 4 1 */
void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next) // recorre hasta el final de la lista
		last = last->next;
	*stack = first->next; // la cabecera pasa a ser el 2do nodo
	(*stack)->prev = NULL; // actualizamos el nodo anterior del nuevo primero
	last->next = first; // el antiguo 1ro va a ser el ultimo
	first->prev = last; // actualizamos el nodo anterior del antiguo 1ro
	first->next = NULL; // actualizamos el next del antiguo primero
}

/* movimientos ra, rb, rr
   move == 0 → ra (rotate a)
   move == 1 → rb (rotate b)
   move == 2 → rr (ra y rb a la vez)
   bench → si no es NULL, contamos la operacion para el modo benchmark */
void	ra_rb_rr(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench)
{
	if (move == 0 || move == 2) // ra o rr
	{
		rotate_stack(stack_a);
		if (move == 0) // es ra
		{
			write(1, "ra\n", 3);
			if (bench) // si estamos en modo benchmark contamos
			{
				bench->ra++;
				bench->total++;
			}
		}
	}
	if (move == 1 || move == 2) // rb o rr
	{
		rotate_stack(stack_b);
		if (move == 1) // es rb
		{
			write(1, "rb\n", 3);
			if (bench)
			{
				bench->rb++;
				bench->total++;
			}
		}
	}
	if (move == 2) // es rr
	{
		write(1, "rr\n", 3);
		if (bench)
		{
			bench->rr++;
			bench->total++;
		}
	}
}

/* movemos el ultimo nodo al principio de la lista
   ejemplo: 1 2 3 4 -> 4 1 2 3 */
void	revers_stack(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next) // encontramos el ultimo nodo
		last = last->next;
	last->prev->next = NULL; // desvinculamos el ultimo nodo de su posicion
	last->prev = NULL; // el nodo anterior va a ser null porque sera el 1ro
	last->next = *stack; // apuntamos el next al antiguo primer nodo
	(*stack)->prev = last; // actualizamos el nodo anterior del primero
	*stack = last; // actualizamos la lista con el nuevo primer nodo
}

/* movimientos rra, rrb, rrr
   move == 0 → rra (reverse rotate a)
   move == 1 → rrb (reverse rotate b)
   move == 2 → rrr (rra y rrb a la vez)
   bench → si no es NULL, contamos la operacion para el modo benchmark */
void	rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench)
{
	if (move == 0 || move == 2) // rra o rrr
	{
		revers_stack(stack_a);
		if (move == 0) // es rra
		{
			write(1, "rra\n", 4);
			if (bench) // si estamos en modo benchmark contamos
			{
				bench->rra++;
				bench->total++;
			}
		}
	}
	if (move == 1 || move == 2) // rrb o rrr
	{
		revers_stack(stack_b);
		if (move == 1) // es rrb
		{
			write(1, "rrb\n", 4);
			if (bench)
			{
				bench->rrb++;
				bench->total++;
			}
		}
	}
	if (move == 2) // es rrr
	{
		write(1, "rrr\n", 4);
		if (bench)
		{
			bench->rrr++;
			bench->total++;
		}
	}
}
