/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:55:20 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08                               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ordena 3 elementos en A usando el minimo de movimientos posibles
   cubre los 6 casos posibles de ordenacion */
void	tiny_sort(t_stack **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third) /* 2 1 3 */
		sa_sb(a, NULL, 0, bench);
	else if (first > second && second > third) /* 3 2 1 */
	{
		sa_sb(a, NULL, 0, bench);
		rra_rrb_rrr(a, NULL, 0, bench);
	}
	else if (first > second && second < third && first > third) /* 3 1 2 */
		ra_rb_rr(a, NULL, 0, bench);
	else if (first < second && second > third && first < third) /* 1 3 2 */
	{
		sa_sb(a, NULL, 0, bench);
		ra_rb_rr(a, NULL, 0, bench);
	}
	else if (first < second && second > third && first > third) /* 2 3 1 */
		rra_rrb_rrr(a, NULL, 0, bench);
}

/* ordena 4-5 elementos pasando los 2 menores a B y ordenando los 3 restantes */
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

/* selecciona el algoritmo segun la flag o el indice de desorden */
void	select_algorithm(t_stack **a, t_stack **b, int flag, t_bench *bench)
{
	int		size;
	float	disorder;

	size = size_stack(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		sa_sb(a, b, 0, bench);
		return ;
	}
	if (size == 3)
	{
		tiny_sort(a, bench);
		return ;
	}
	if (size <= 5)
	{
		sort_five(a, b, bench);
		return ;
	}
	if (flag == 1)
		insertion_sort(a, b, bench);
	else if (flag == 2)
		k_sort(a, b, size, bench);
	else if (flag == 3)
		radix_sort(a, b, bench);
	else
	{
		disorder = compute_disorder(*a);
		if (disorder < 0.2)
			insertion_sort(a, b, bench);
		else if (disorder < 0.5)
			k_sort(a, b, size, bench);
		else
			radix_sort(a, b, bench);
	}
}