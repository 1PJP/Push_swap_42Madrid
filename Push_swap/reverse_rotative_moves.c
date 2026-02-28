/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotative_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:54:18 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/28 12:33:32 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*en esta funcion movemos elmprimer nodo al final de la lista*/
void	rotate_stack(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)//recorre hasta el final de la lista
		last = last->next;
	*stack = first->next;//la cabecera pasa a ser 2do nodo
	(*stack)->prev = NULL;//actualiza el nodo anterior de nuevo
	last->next = first;//el nodo antigulo 1ro va hacer el final
	first->prev = last;//actualiza el nodo anterior del antiguo 1ro
	first->next = NULL;//actualiza el next del antiguio primero
}
/*estos son los moviminetos ra, rb, rr*/
void	ra_rb_rr(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == 0 || move == 2)//aqui mira si es ra o rr
	{
		rotate_stack(stack_a);
		if (move == 0)//es ra
			write(1, "ra\n", 3);
	}
	if (move == 1 || move == 2)//aqui mira si es rb o rr
	{
		rotate_stack(stack_b);
		if (move == 1)//es rb
			write(1, "rb\n", 3);
	}
	if (move == 2)//aqui sin mas es rr
		write(1, "rr\n", 3);
}
/*en esta funcion movemos el ultimos nodo al principo de la lista*/
void	revers_stack(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)//encontramos el ultimo nodo
		last = last->next;
	last->prev->next = NULL;//aqui desvincilamos el untimo nodo de la posiscion
	last->prev = NULL;//el nodo anterios va hacer null por que va hacer el 1ro
	last->next = *stack;//apuntamos el next al antuguio primer nodo
	(*stack)->prev = last;//actializa el nodo anterior del primero
	*stack = last;//actializa la lista y nombra nuevp primer nodo
}
/*en esta funcion hacemos los movimientos rra, rrb y rrr*/
void	rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b, int move)
{
	
	if (move == 0 || move == 2)//aqui mira si es rra o rrr
	{
		revers_stack(stack_a);
		if (move == 0)//es rra
			write(1, "rra\n", 4);
	}
	if (move == 1 || move == 2)//aqui mira si es rrb o rrr
	{
		revers_stack(stack_b);
		if (move == 1)//es rrb
			write(1, "rrb\n", 4);
	}
	if (move == 2)//aqui sin mas es rrr
		write(1, "rrr\n", 4);
}