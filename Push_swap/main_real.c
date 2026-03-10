/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:02:01 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 20:33:12 by jezambra         ###   ########.fr       */
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

static t_stack	*init_stack(int argc, char **argv, char ***args,
				int *need_free, int has_flag)
{
	t_stack	*a;

	*args = id_args(argc, argv, need_free, has_flag);
	a = put_stack_a(*args);
	if (!a)
		return (NULL);
	duplicates(a);
	add_index(a);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		need_free;
	int		flag;
	int		has_flag;
	int		is_bench;
	t_bench	bench;
	float	disorder;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	is_bench = 0;
	ft_memset_ps(&bench, 0, sizeof(t_bench));
	flag = get_flag(argc, argv, &is_bench);
	has_flag = count_flags(argc, argv);
	a = init_stack(argc, argv, &args, &need_free, has_flag);
	if (!a)
		return (0);
	disorder = compute_disorder(a);
	if (!is_sorted(a))
		select_algorithm(&a, &b, flag, is_bench ? &bench : NULL);
	if (is_bench)
		print_bench(&bench, disorder, flag);
	free_stack(&a);
	free_stack(&b);
	if (need_free)
		free_split(args);
	return (0);
}
