/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:58:52 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/07 00:01:33 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*David este es un main que hice para probar si o que estoy haciendo
con esto vamos viendo primero los movimientos, antes de meter la algoritmia
estoy hacuendo una base buena, me queda por ver lo de los nuemros por que los 
movimientos no los tengo regustrados como sa, sb, ss, pa, pb sino con numero 
veras en el apartado de movimeetos que te go algo como if (move == 0) que seria
el moviento en cuestion */
// función de ayuda para imprimir la pila
void	print_stack(t_stack *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;

	// Crear pila de prueba: 1 2 3 4
	stack_add_back(&stack_a, new_node_stack(1));
	stack_add_back(&stack_a, new_node_stack(2));
	stack_add_back(&stack_a, new_node_stack(3));
	stack_add_back(&stack_a, new_node_stack(4));

	printf("Estado inicial:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Movimientos de swap
	sa_sb(&stack_a, &stack_b, 0); // sa
	printf("\nDespués de sa:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	sa_sb(&stack_a, &stack_b, 1); // sb
	printf("\nDespués de sb:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	sa_sb(&stack_a, &stack_b, 2); // ss
	printf("\nDespués de ss:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Movimientos de push
	pa_pb(&stack_a, &stack_b, 1); // pb
	printf("\nDespués de pb:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	pa_pb(&stack_a, &stack_b, 0); // pa
	printf("\nDespués de pa:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Movimientos de rotación
	ra_rb_rr(&stack_a, &stack_b, 0); // ra
	printf("\nDespués de ra:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	ra_rb_rr(&stack_a, &stack_b, 1); // rb
	printf("\nDespués de rb:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	ra_rb_rr(&stack_a, &stack_b, 2); // rr
	printf("\nDespués de rr:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Movimientos de reverse-rotación
	rra_rrb_rrr(&stack_a, &stack_b, 0); // rra
	printf("\nDespués de rra:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	rra_rrb_rrr(&stack_a, &stack_b, 1); // rrb
	printf("\nDespués de rrb:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	rra_rrb_rrr(&stack_a, &stack_b, 2); // rrr
	printf("\nDespués de rrr:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	return 0;
}


#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	**args;
	int		need_free;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	args = id_args(argc, argv, &need_free);
	a = put_stack_a(args);
	if (!a) // Siempre comprueba si el stack se creó bien
		return (0);
	duplicates(a);
	sort_stack(&a, &b);
	free_stack(&a); // ¡No olvides liberar al final!
	if (need_free)
		free_split(args); // Usa la función que ya tienes para el split
	return (0);
}