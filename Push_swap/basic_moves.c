/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:28:19 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 21:13:12 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
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

static void	count_sa_sb(t_bench *bench, int move)
{
	if (move == 0 && bench)
	{
		bench->sa++;
		bench->total++;
	}
	if (move == 1 && bench)
	{
		bench->sb++;
		bench->total++;
	}
	if (move == 2 && bench)
	{
		bench->ss++;
		bench->total++;
	}
}

void	sa_sb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench)
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
	count_sa_sb(bench, move);
}

void	push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*save;

	if (!stack_a || !*stack_a)
		return ;
	save = *stack_a;
	*stack_a = save->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	save->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = save;
	save->prev = NULL;
	*stack_b = save;
}

void	pa_pb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench)
{
	if (move == 0)
	{
		push_stack(stack_b, stack_a);
		write(1, "pa\n", 3);
		if (bench)
		{
			bench->pa++;
			bench->total++;
		}
	}
	else if (move == 1)
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
