/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:19:42 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/24 17:05:46 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//David esto es lista doble enlazada
//al igual que las listas de la libft creamos el primer nodo solo que es lista doble
t_stack	*new_node_stack(int value)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
	if (!nodo)
		ctrl_error ();
	nodo->value = value;//guardamos el numero 
	nodo->index = -1;//inicializamos el ideice, se pone -1 por que no se sabe la posicion
	nodo->next = NULL;//no hya nodo siguiente AUN
	nodo->prev = NULL;//no hay nodo anterior AUN
	return (nodo);//devolvemos el nodo creado
}
//agregamos nodo final al igual que la libft
void	stack_add_back(t_stack **stack, t_stack *nodo)
{
	t_stack	*last;
	
	if (!stack || !nodo)
		return ;
	if (!*stack)//si esta vacio
	{
		*stack = nodo;//el nuevo nodo sera el primero
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = nodo;//ultimo nodo apunta al nuevo
	nodo->prev = last;//el nuevo nodo apunta al anterior
}
/*Esta función construye la pila inicial del programa, recorre los argumentos
valida que sean números correctos, los convierte a int
crea nodos de una lista doble enlazada y los añade al final de stack_a.*/
t_stack	*put_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;
	long	nbr;
	int	i;

	stack_a = NULL;
	i = 1;//lo iniciamos en 1 por que 0 es el a.out
	while (i < argc)
	{
		if (!valid_nbr(argv[i]))//validamos str
			ctrl_error();
		nbr = ft_atoi_push_swap(argv[i]);//vonvertimos a numero con nuetra funcion
		stack_add_back(&stack_a, new_node_stack((int)nbr));//agregamos el nodo
		i++;
	}
	return (stack_a);
}
/*con esta funcion asigna a cada nodo un número (index) que representa su posición si la lista estuviera ordenada
*/
void	add_index(t_stack *stack)
{
	t_stack	*put_nbr;//nodo al que asignamos 
	t_stack	*cmp;//nodo de comparacion
	int	i;//contador

	put_nbr = stack;//empezamos desde el 1er nodo
	while (put_nbr)//recorrecomos lista nodo por nodo
	{
		i = 0;
		cmp = stack;//comparamos el 1er nodo
		while (cmp)
		{
			if (cmp->value < put_nbr->value)//si el valor del nodo que comparamos en menor que el valor del nodo actual
				i++;
			cmp = cmp->next;//avanzamos al sigiente nodo para hacer la misma co mparacion
		}
		put_nbr->index = i;//guardamos en i cuanros numeros son menosres
		put_nbr = put_nbr->next;//pasamos al sigiente nodo
	}
}