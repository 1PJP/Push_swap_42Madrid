/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:28:19 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08                               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* intercambiamos los dos primeros elementos de la pila
   ejemplo: 1 2 3 4 -> 2 1 3 4 */
void	swap_stack(t_stack **stack)
{
	t_stack	*frt;
	t_stack	*scnd;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	frt = *stack; // guardamos el primer nodo
	scnd = frt->next; // guardamos el segundo nodo
	frt->next = scnd->next; // el primer nodo apunta ahora al 3ro si hay
	if (scnd->next)
		scnd->next->prev = frt; // si hay un 3er nodo actualizamos su prev
	scnd->prev = NULL; // el 2do nodo sera la cabecera, nodo anterior es null
	scnd->next = frt; // el segundo nodo apunta al primero
	frt->prev = scnd; // el nodo frt apunta al anterior osea scnd
	*stack = scnd; // actualizamos cabecera que sera scnd
}

/* movimientos sa, sb, ss
   move == 0 → sa (swap stack a)
   move == 1 → sb (swap stack b)
   move == 2 → ss (sa y sb a la vez)
   bench → si no es NULL, contamos la operacion para el modo benchmark */
void	sa_sb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench)
{
	if (move == 0 || move == 2) // sa o ss
	{
		swap_stack(stack_a);
		if (move == 0) // es sa
		{
			write(1, "sa\n", 3);
			if (bench) // si estamos en modo benchmark contamos
			{
				bench->sa++;
				bench->total++;
			}
		}
	}
	if (move == 1 || move == 2) // sb o ss
	{
		swap_stack(stack_b);
		if (move == 1) // es sb
		{
			write(1, "sb\n", 3);
			if (bench)
			{
				bench->sb++;
				bench->total++;
			}
		}
	}
	if (move == 2) // es ss
	{
		write(1, "ss\n", 3);
		if (bench)
		{
			bench->ss++;
			bench->total++;
		}
	}
}

/* mueve el primer nodo de stack_a al principio de stack_b */
void	push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*save;

	if (!stack_a || !*stack_a)
		return ;
	save = *stack_a; // guardamos el primer nodo
	*stack_a = save->next; // el segundo pasa a ser primero
	if (*stack_a)
		(*stack_a)->prev = NULL; // el nodo anterior del nuevo primero es null
	save->next = *stack_b; // el nodo guardado apunta al inicio de stack_b
	if (*stack_b)
		(*stack_b)->prev = save; // actualizamos el prev del antiguo primero de b
	save->prev = NULL; // el nodo anterior del nuevo primero de b es null
	*stack_b = save; // actualizamos la cabecera de stack b
}

/* movimientos pa, pb
   move == 0 → pa (push a: mueve el primero de b al principio de a)
   move == 1 → pb (push b: mueve el primero de a al principio de b)
   bench → si no es NULL, contamos la operacion para el modo benchmark */
void	pa_pb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench)
{
	if (move == 0) // movimiento pa
	{
		push_stack(stack_b, stack_a);
		write(1, "pa\n", 3);
		if (bench) // si estamos en modo benchmark contamos
		{
			bench->pa++;
			bench->total++;
		}
	}
	else if (move == 1) // movimiento pb
	{
		push_stack(stack_a, stack_b);
		write(1, "pb\n", 3);
		if (bench)
		{
			bench->pb++;
			bench->total++;
		}
	}
}