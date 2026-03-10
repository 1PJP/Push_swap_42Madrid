/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:03:28 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 20:31:05 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static int	get_pos(t_stack *stack, int target_idx)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_idx)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_idx;
	int	pos;
	int	size;

	while (*b)
	{
		max_idx = get_max_index(*b);
		pos = get_pos(*b, max_idx);
		size = size_stack(*b);
		if (pos <= size / 2)
		{
			while ((*b)->index != max_idx)
				ra_rb_rr(NULL, b, 1, bench);
		}
		else
		{
			while ((*b)->index != max_idx)
				rra_rrb_rrr(NULL, b, 1, bench);
		}
		pa_pb(a, b, 0, bench);
	}
}

void	k_sort(t_stack **a, t_stack **b, int length, t_bench *bench)
{
	int	i;
	int	range;

	i = 0;
	if (length <= 100)
		range = 15;
	else
		range = 35;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pa_pb(a, b, 1, bench);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pa_pb(a, b, 1, bench);
			ra_rb_rr(NULL, b, 1, bench);
			i++;
		}
		else
			ra_rb_rr(a, NULL, 0, bench);
	}
	push_back_to_a(a, b, bench);
}
