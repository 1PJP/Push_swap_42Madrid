/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:02:01 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08                               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* cuenta cuantas flags hay al principio de los argumentos
   ejemplo: --bench --complex 5 4 3 → devuelve 2 */
static int	count_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	return (i - 1);
}

/* inicializa el stack a partir de los argumentos y valida la entrada */
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

	if (argc < 2) /* si no hay argumentos no hacemos nada */
		return (0);
	a = NULL;
	b = NULL;
	is_bench = 0;
	ft_memset_ps(&bench, 0, sizeof(t_bench)); /* inicializamos bench a 0 */
	flag = get_flag(argc, argv, &is_bench); /* detectamos que algoritmo usar y si hay --bench */
	has_flag = count_flags(argc, argv); /* contamos cuantas flags hay para saltar */
	a = init_stack(argc, argv, &args, &need_free, has_flag); /* construimos el stack A */
	if (!a) /* si no hay numeros validos terminamos */
		return (0);
	disorder = compute_disorder(a); /* calculamos el indice de desorden antes de ordenar */
	if (!is_sorted(a)) /* si ya esta ordenado no hacemos nada */
		select_algorithm(&a, &b, flag, is_bench ? &bench : NULL);
	if (is_bench) /* si hay --bench imprimimos las metricas por stderr */
		print_bench(&bench, disorder, flag);
	free_stack(&a); /* liberamos stack A */
	free_stack(&b); /* liberamos stack B */
	if (need_free) /* si usamos split liberamos el array de strings */
		free_split(args);
	return (0);
}