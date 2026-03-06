/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:02:01 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/07 00:13:21 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Función simple para ver cómo están los números en el stack
void	print_stack(t_stack *s, char *name)
{
	printf("Stack %s: ", name);
	if (!s)
	{
		printf("(vacio)\n");
		return ;
	}
	while (s)
	{
		printf("%d ", s->value);
		s = s->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int	need_free;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	args = id_args(argc, argv, &need_free);
	a = put_stack_a(args);
	if (!a)
		return (0);
	duplicates(a);

// 1. Muestra el orden inicial
	printf("\nORDEN INICIAL:\n");
	print_stack(a, "A");
	printf("---------------------------\n");

// 2. Ejecuta el algoritmo (aquí se imprimirán los sa, pb, etc.)
	sort_stack(&a, &b);

	// 3. Muestra el orden final
	printf("---------------------------\n");
	printf("ORDEN FINAL:\n");
	print_stack(a, "A");
	print_stack(b, "B");

// 4. Verificación de seguridad
	if (is_sorted(a) && size_stack(b) == 0)
		printf("\nRESULTADO: OK (Ordenado correctamente)\n");
	else
		printf("\nRESULTADO: KO (Sigue desordenado)\n");

	free_stack(&a);
	if (need_free)
		free_split(args);
	return (0);
}