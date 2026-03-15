/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nueva_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:17:48 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/11 21:19:26 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*ESTRUCTURAS*/
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	out_fd; /* [COUNT-ONLY] 1=imprimir ops, 0=solo contar sin imprimir */
}		t_bench;

/*ESTRUCTURA PARA EL MAIN POR MUCHAS VARIABLES*/
typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	char	**args;
	int		flag;
	int		has_flag;
	int		is_bench;
	int		need_free;
	int		count_only; /* [COUNT-ONLY] 1 si se uso --count-only */
}		t_ps;

/*VALIDACION Y UTILIDADES*/

void	ctrl_error(void);
void	check_int_range(long nbr);
void	duplicates(t_stack *stack);
void	ft_memset_ps(void *ptr, int value, int size);

int		valid_nbr(char *str);
long	ft_atoi_push_swap(const char *str);
float	compute_disorder(t_stack *stack);

/*CONSTRUCCION DEL STACK*/

void	stack_add_back(t_stack **stack, t_stack *nodo);
void	add_index(t_stack *stack);
void	free_stack(t_stack **stack);

int		is_sorted(t_stack *stack);
int		size_stack(t_stack *stack);

t_stack	*new_node_stack(int value);
t_stack	*put_stack_a(char **argv);

/*GESTION DE ARGUMENTOS*/

void	free_split(char **str);
int		get_flag(int argc, char **argv, int *is_bench);
char	**push_swap_split(char const *s, char c);
char	**id_args(int argc, char **argv, int *need_free, int has_flag);
char	*get_strategy_name(int flag, float disorder);

/*MOVIMIENTOS*/

void	sa_sb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench);
void	pa_pb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench);
void	rotate_stack(t_stack **stack);
void	ra_rb_rr(t_stack **stack_a, t_stack **stack_b,
			int move, t_bench *bench);
void	rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b,
			int move, t_bench *bench);
void	revers_stack(t_stack **stack);

/*ALGORITMOS*/

void	tiny_sort(t_stack **a, t_bench *bench);
void	sort_five(t_stack **a, t_stack **b, t_bench *bench);
void	insertion_sort(t_stack **a, t_stack **b, t_bench *bench);
void	k_sort(t_stack **a, t_stack **b, int length, t_bench *bench);
void	radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench);
void	select_algorithm(t_stack **a, t_stack **b, int flag, t_bench *bench);

/*BENCHMARK*/

void	print_bench(t_bench *bench, float disorder, int flag);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	print_float(float f, int fd);

#endif
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
		/* [COUNT-ONLY] solo escribe si bench es NULL (modo normal)
		   o si out_fd == 1 (bench/count-only no suprime) */
		if (move == 0 && (!bench || bench->out_fd))
			write(1, "sa\n", 3);
	}
	if (move == 1 || move == 2)
	{
		swap_stack(stack_b);
		if (move == 1 && (!bench || bench->out_fd))
			write(1, "sb\n", 3);
	}
	if (move == 2 && (!bench || bench->out_fd))
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
		/* [COUNT-ONLY] misma logica: escribe solo si no hay bench
		   o si out_fd == 1 */
		if (!bench || bench->out_fd)
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
		if (!bench || bench->out_fd)
			write(1, "pb\n", 3);
		if (bench)
		{
			bench->pb++;
			bench->total++;
		}
	}
}
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
		/* [COUNT-ONLY] escribe solo si no hay bench (modo normal)
		   o si out_fd == 1 (bench activo con escritura) */
		if (move == 0 && (!bench || bench->out_fd))
			write(1, "ra\n", 3);
	}
	if (move == 1 || move == 2)
	{
		rotate_stack(stack_b);
		if (move == 1 && (!bench || bench->out_fd))
			write(1, "rb\n", 3);
	}
	if (move == 2 && (!bench || bench->out_fd))
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
		/* [COUNT-ONLY] misma logica en todos los writes */
		if (move == 0 && (!bench || bench->out_fd))
			write(1, "rra\n", 4);
	}
	if (move == 1 || move == 2)
	{
		revers_stack(stack_b);
		if (move == 1 && (!bench || bench->out_fd))
			write(1, "rrb\n", 4);
	}
	if (move == 2 && (!bench || bench->out_fd))
		write(1, "rrr\n", 4);
	count_rra_rrb_rrr(bench, move);
}
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

/*
** [COUNT-ONLY] get_bench ahora tambien devuelve &bench cuando
** count_only == 1, pero con out_fd = 0 para suprimir los writes.
** Modo normal (sin bench ni count-only): devuelve NULL, out_fd no importa.
** Modo bench: devuelve &bench con out_fd = 1 (escribe ops normalmente).
** Modo count-only: devuelve &bench con out_fd = 0 (cuenta pero no escribe).
*/
static t_bench	*get_bench(t_ps *ps)
{
	if (ps->is_bench)
	{
		ps->bench.out_fd = 1;
		return (&ps->bench);
	}
	if (ps->count_only)
	{
		ps->bench.out_fd = 0;
		return (&ps->bench);
	}
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
	/* [COUNT-ONLY] imprime solo el total de operaciones por stdout */
	if (ps->count_only)
	{
		ft_putnbr_fd(ps->bench.total, 1);
		write(1, "\n", 1);
	}
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
	ps.count_only = 0;
	ft_memset_ps(&ps.bench, 0, sizeof(t_bench));
	ps.flag = get_flag(argc, argv, &ps.is_bench);
	ps.has_flag = count_flags(argc, argv);
	/* [COUNT-ONLY] get_flag devuelve 5 cuando detecta --count-only */
	if (ps.flag == 5)
	{
		ps.count_only = 1;
		ps.flag = 0; /* usa adaptive por defecto */
	}
	run(&ps, argc, argv);
	return (0);
}