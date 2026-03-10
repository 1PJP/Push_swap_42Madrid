/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:02:01 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 21:48:04 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	return (i - 1);
}

static void	init_stack(t_ps *ps, int argc, char **argv)
{
	ps->args = id_args(argc, argv, &ps->need_free, ps->has_flag);
	ps->a = put_stack_a(ps->args);
	if (!ps->a)
		return ;
	duplicates(ps->a);
	add_index(ps->a);
}

static t_bench	*get_bench(t_ps *ps)
{
	if (ps->is_bench)
		return (&ps->bench);
	return (NULL);
}

static void	run(t_ps *ps, int argc, char **argv)
{
	float	disorder;

	init_stack(ps, argc, argv);
	if (!ps->a)
		return ;
	disorder = compute_disorder(ps->a);
	if (!is_sorted(ps->a))
		select_algorithm(&ps->a, &ps->b, ps->flag, get_bench(ps));
	if (ps->is_bench)
		print_bench(&ps->bench, disorder, ps->flag);
	free_stack(&ps->a);
	free_stack(&ps->b);
	if (ps->need_free)
		free_split(ps->args);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ps.a = NULL;
	ps.b = NULL;
	ps.is_bench = 0;
	ps.need_free = 0;
	ft_memset_ps(&ps.bench, 0, sizeof(t_bench));
	ps.flag = get_flag(argc, argv, &ps.is_bench);
	ps.has_flag = count_flags(argc, argv);
	run(&ps, argc, argv);
	return (0);
}
