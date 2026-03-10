/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:11:36 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/09 20:41:12 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_stack *a)
{
	int		pos;
	int		min_pos;
	int		min_idx;

	pos = 0;
	min_pos = 0;
	min_idx = a->index;
	while (a)
	{
		if (a->index < min_idx)
		{
			min_idx = a->index;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}

void	insertion_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	half;

	while (size_stack(*a) > 0)
	{
		pos = get_min_pos(*a);
		half = size_stack(*a) / 2;
		if (pos <= half)
		{
			while (get_min_pos(*a) != 0)
				ra_rb_rr(a, NULL, 0, bench);
		}
		else
		{
			while (get_min_pos(*a) != 0)
				rra_rrb_rrr(a, NULL, 0, bench);
		}
		pa_pb(a, b, 1, bench);
	}
	while (*b)
		pa_pb(a, b, 0, bench);
}
