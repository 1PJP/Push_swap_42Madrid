/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:28:37 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 21:09:54 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops_line1(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n", 1);
}

static void	print_ops_line2(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}

void	print_bench(t_bench *bench, float disorder, int flag)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_float(disorder * 100, 2);
	write(2, "%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(get_strategy_name(flag, disorder), 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2);
	write(2, "\n", 1);
	print_ops_line1(bench);
	print_ops_line2(bench);
}
