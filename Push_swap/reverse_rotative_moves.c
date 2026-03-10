/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotative_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:54:18 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 21:23:02 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_ra_rb_rr(t_bench *bench, int move)
{
	if (move == 0 && bench)
	{
		bench->ra++;
		bench->total++;
	}
	if (move == 1 && bench)
	{
		bench->rb++;
		bench->total++;
	}
	if (move == 2 && bench)
	{
		bench->rr++;
		bench->total++;
	}
}

void	ra_rb_rr(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench)
{
	if (move == 0 || move == 2)
	{
		rotate_stack(stack_a);
		if (move == 0)
			write(1, "ra\n", 3);
	}
	if (move == 1 || move == 2)
	{
		rotate_stack(stack_b);
		if (move == 1)
			write(1, "rb\n", 3);
	}
	if (move == 2)
		write(1, "rr\n", 3);
	count_ra_rb_rr(bench, move);
}

static void	count_rra_rrb_rrr(t_bench *bench, int move)
{
	if (move == 0 && bench)
	{
		bench->rra++;
		bench->total++;
	}
	if (move == 1 && bench)
	{
		bench->rrb++;
		bench->total++;
	}
	if (move == 2 && bench)
	{
		bench->rrr++;
		bench->total++;
	}
}

void	rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b, int move,
			t_bench *bench)
{
	if (move == 0 || move == 2)
	{
		revers_stack(stack_a);
		if (move == 0)
			write(1, "rra\n", 4);
	}
	if (move == 1 || move == 2)
	{
		revers_stack(stack_b);
		if (move == 1)
			write(1, "rrb\n", 4);
	}
	if (move == 2)
		write(1, "rrr\n", 4);
	count_rra_rrb_rrr(bench, move);
}
