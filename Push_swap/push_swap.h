/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:17:48 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 21:47:32 by jezambra         ###   ########.fr       */
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