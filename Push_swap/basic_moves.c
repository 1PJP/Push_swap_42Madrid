/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:28:19 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/28 12:15:41 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*vamos hacer el sa y sb, osea a intercambiar los primeros elemento de la 
pila ejemplo 1 2 3 4 con el comando sa, sb y ss quedando 2 1 3 4*/
void	swap_stack(t_stack **stack)
{
	t_stack	*frt;
	t_stack	*scnd;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	frt = *stack;//guardomos el primer nodo
	scnd = frt->next;//guardamos el segundo nodo
	frt->next = scnd->next;//el primer nodo apunta ahora al 3ro si hay
	if (scnd->next)
		scnd->next->prev = frt;//si hay un 3er nodo actualiza la lista
	scnd->prev = NULL;//el 2do nodo sera la cabecera ahi que nodo anterios es null
	scnd->next = frt;//el segundo nodo apunta al que sigue
	frt->prev = scnd;//el nodo frt apunta al anterior osea scnd 
	*stack = scnd;//aqui actualizamos cabecera que sera scnd
}
/*funcion para los movimientos sa, sb, ss*/
void	sa_sb(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == 0 || move == 2)// aqui mira si es sa o ss
	{
		swap_stack(stack_a);
		if (move == 0)//es sa
			write(1, "sa\n", 3);
	}
	if (move == 1 || move == 2)//aqui meira si es sb o ss
	{
		swap_stack(stack_b);
		if (move == 1)//es sb
			write(1, "sb\n", 3);
	}
	if (move == 2)//aqui es ss
		write(1, "ss\n", 3);
}
/*esta funcion se encarga de mover os nodos de un strack a otro */
void	push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*save;
	
	if (!stack_a || !*stack_a)
		return ;
	save = *stack_a;//guardamos el primer nodo
	*stack_a = save->next;//el segundo pasa a ser 1ro
	if (*stack_a)
		(*stack_a)->prev = NULL;//el nodo anteriro del primero es null
	save->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = save;
	save->prev = NULL;//el nodo anterior del primro es ahora null
	*stack_b = save;//actualizamos la cabecera de stack b
}
/*esta funcion es para los movimientos*/
void	pa_pb(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == 0)//movimineto pa
	{
		push_stack(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	else if (move == 1)//movimiento pb
	{
		push_stack(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
}