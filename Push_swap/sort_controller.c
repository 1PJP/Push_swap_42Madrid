/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:55:20 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 21:26:54 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa_sb(a, NULL, 0, bench);
	else if (first > second && second > third)
	{
		sa_sb(a, NULL, 0, bench);
		rra_rrb_rrr(a, NULL, 0, bench);
	}
	else if (first > second && second < third && first > third)
		ra_rb_rr(a, NULL, 0, bench);
	else if (first < second && second > third && first < third)
	{
		sa_sb(a, NULL, 0, bench);
		ra_rb_rr(a, NULL, 0, bench);
	}
	else if (first < second && second > third && first > third)
		rra_rrb_rrr(a, NULL, 0, bench);
}

void	sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
	while (size_stack(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pa_pb(a, b, 1, bench);
		else
			ra_rb_rr(a, NULL, 0, bench);
	}
	tiny_sort(a, bench);
	while (*b)
		pa_pb(a, b, 0, bench);
	if ((*a)->index > (*a)->next->index)
		sa_sb(a, NULL, 0, bench);
}

static void	adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	float	disorder;
	int		size;

	size = size_stack(*a);
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		insertion_sort(a, b, bench);
	else if (disorder < 0.5)
		k_sort(a, b, size, bench);
	else
		radix_sort(a, b, bench);
}

void	select_algorithm(t_stack **a, t_stack **b, int flag, t_bench *bench)
{
	int	size;

	size = size_stack(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (sa_sb(a, b, 0, bench));
	if (size == 3)
		return (tiny_sort(a, bench));
	if (size <= 5)
		return (sort_five(a, b, bench));
	if (flag == 1)
		insertion_sort(a, b, bench);
	else if (flag == 2)
		k_sort(a, b, size, bench);
	else if (flag == 3)
		radix_sort(a, b, bench);
	else
		adaptive(a, b, bench);
}
