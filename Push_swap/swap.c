/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:28:19 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/26 21:49:26 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*vamos hacer el sa y sb, osea a intercambiar los primeros elemento de la 
pila ejemplo 1 2 3 4 con el comando sa, sb y ss quedando 2 1 3 4*/
void	swpa_stack(t_stack **stack)
{
	t_stack	*frt;
	t_stack	*scnd;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	frt = *stack;
	scnd = frt->next;
	frt->next = scnd->next;
	if (scnd->next)
		scnd->next->prev = frt;
	scnd->prev = NULL;
	scnd->next = frt;
	frt->prev = scnd;
	*stack = scnd;
}
/*funcion para los movimientos sa, sb, ss*/
void	sa_sb(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (move == 0 || move == 2)
	{
		swap_stack(stack_a);
		if (move == 0)
			write(1, "sa\n", 3);
	}
	if (move == 1 || move == 2)
	{
		swap_stack(stack_b);
		if (move == 1)
			write(1, "sb\n", 3);
	}
	if (move == 2)
		write(1, "ss\n", 3);
}