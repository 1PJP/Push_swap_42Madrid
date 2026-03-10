/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:19:42 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 20:39:59 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node_stack(int value)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
	if (!nodo)
		ctrl_error ();
	nodo->value = value;
	nodo->index = -1;
	nodo->next = NULL;
	nodo->prev = NULL;
	return (nodo);
}

void	stack_add_back(t_stack **stack, t_stack *nodo)
{
	t_stack	*last;

	if (!stack || !nodo)
		return ;
	if (!*stack)
	{
		*stack = nodo;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = nodo;
	nodo->prev = last;
}

t_stack	*put_stack_a(char **argv)
{
	t_stack	*stack_a;
	long	nbr;
	int		i;

	stack_a = NULL;
	i = 0;
	while (argv[i])
	{
		if (!valid_nbr(argv[i]))
			ctrl_error();
		nbr = ft_atoi_push_swap(argv[i]);
		stack_add_back(&stack_a, new_node_stack((int)nbr));
		i++;
	}
	return (stack_a);
}

void	add_index(t_stack *stack)
{
	t_stack	*put_nbr;
	t_stack	*cmp;
	int		i;

	put_nbr = stack;
	while (put_nbr)
	{
		i = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < put_nbr->value)
				i++;
			cmp = cmp->next;
		}
		put_nbr->index = i;
		put_nbr = put_nbr->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
