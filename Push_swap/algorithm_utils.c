/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:52:43 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/28 16:14:55 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*esta funcion lo que hace es calcular cuantos elementos tiene nuestro stack
poco que comentar se entiene facil*/
int	size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
/*esta funcion lo que hace es calcular el indice de desorden y retotra 1 o 0 ejm.
0 = ordenado
1 = desordenado */
float	compute_disorder(t_stack *stack)
{
	t_stack	*out;//nodo externo para comparar
	t_stack *in;//nodo interno que comparamos
	float	mistakes;//cantidad de pares que estan mal ordenados
	float	total_pairs;//total posible 

	mistakes = 0;
	total_pairs = 0;
	out = stack;
	while (out)
	{
		in = out->next;//comparamos desde el siguinete nodo
		while (in)
		{
			total_pairs++;//almacenamos pada par
			if (out->value > in->value)//si esta mal ordenado el par
				mistakes++;//almacenamos un error
			in = in->next;//avamzamos al sihuiente nodo 
		}
		out = out->next;//hacemos next al nodo externo
	}
	if (total_pairs == 0)
		return (0);//si la lista esta vacio o tine un nodo retorna 0
	return (mistakes / total_pairs);//devolvemos una proporcion de erres
}