
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:17:00 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08 23:14:11 by jezambra         ###   ########.fr       */
/*                                                                            */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>


/*ESTRUCTURAS*/


/* nodo de la lista doblemente enlazada
   cada numero a ordenar vive en un nodo */
typedef struct	s_stack
{
	int	value;			/* numero que queremos ordenar */
	int	index;			/* posicion que ocuparia si la lista estuviera ordenada */
	struct s_stack	*next;		/* puntero al nodo siguiente */
	struct s_stack	*prev;		/* puntero al nodo anterior */
}		t_stack;

/* contador de operaciones para el modo benchmark
   un campo por cada tipo de movimiento posible */
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
	int	total;	/* suma de todas las operaciones */
}	t_bench;


/*VALIDACION Y UTILIDADES*/

void	ctrl_error(void);			/* imprime Error y termina el programa */
void	check_int_range(long nbr);		/* comprueba que el numero cabe en un int */
void	duplicates(t_stack *stack);		/* da error si hay numeros repetidos */
void	ft_memset_ps(void *ptr, int value, int size); /* inicializa memoria a 0 */

int		valid_nbr(char *str);		/* comprueba que el string es un numero valido */
long	ft_atoi_push_swap(const char *str);	/* convierte string a numero long */
float	compute_disorder(t_stack *stack);	/* calcula el indice de desorden 0.0-1.0 */

/*CONSTRUCCION DEL STACK*/

void	stack_add_back(t_stack **stack, t_stack *nodo); /* añade nodo al final */
void	add_index(t_stack *stack);	/* asigna a cada nodo su posicion ordenada */
void	free_stack(t_stack **stack);	/* libera toda la memoria de la lista */

int		is_sorted(t_stack *stack);	/* devuelve 1 si la lista esta ordenada */
int		size_stack(t_stack *stack);	/* devuelve el numero de nodos de la lista */

t_stack	*new_node_stack(int value);	/* crea un nodo nuevo con un numero */
t_stack	*put_stack_a(char **argv);	/* construye el stack A desde los argumentos */

/*GESTION DE ARGUMENTOS*/

void	free_split(char **str);		/* libera la memoria del split */
int		get_flag(int argc, char **argv, int *is_bench); /* detecta las flags */
char	**push_swap_split(char const *s, char c); /* separa string por delimitador */
char	**id_args(int argc, char **argv, int *need_free, int has_flag); /* identifica argumentos */

/*MOVIMIENTOS*/

void	sa_sb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench); /* swap */
void	pa_pb(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench); /* push */
void	rotate_stack(t_stack **stack);	/* rota una lista: primero va al final */
void	ra_rb_rr(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench); /* rotate */
void	revers_stack(t_stack **stack);	/* rota inversa: ultimo va al principio */
void	rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b, int move, t_bench *bench); /* reverse rotate */

/*ALGORITMOS*/

void	tiny_sort(t_stack **a, t_bench *bench);			/* ordena 3 elementos */
void	sort_five(t_stack **a, t_stack **b, t_bench *bench);	/* ordena 4-5 elementos */
void	insertion_sort(t_stack **a, t_stack **b, t_bench *bench);/* O(n^2) */
void	k_sort(t_stack **a, t_stack **b, int length, t_bench *bench); /* O(n*sqrt(n)) */
void	radix_sort(t_stack **a, t_stack **b, t_bench *bench);	/* O(n log n) */
void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench); /* vacia B hacia A ordenado */
void	select_algorithm(t_stack **a, t_stack **b, int flag, t_bench *bench); /* decide algoritmo */

/*BENCHMARK*/

void	print_bench(t_bench *bench, float disorder, int flag); /* imprime metricas por stderr */

#endif