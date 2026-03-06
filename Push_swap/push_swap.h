/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:17:00 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/06 23:47:34 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

//David esta es la struct con lista doble te explico paso a paso que hace
typedef struct	s_stack
{
	int	value;//numero que queremos ordenar
	int	index;//indice para el ordenamineto
	struct s_stack	*next;//sigiiente nodo
	struct s_stack	*prev;//nodo anterior 
}		t_stack;

void	ctrl_error(void);
void	check_int_range(long nbr);
void	stack_add_back(t_stack **stack, t_stack *nodo);
void	duplicates(t_stack *stack);
void	add_index(t_stack *stack);
void 	sa_sb(t_stack **stack_a, t_stack **stack_b, int move);
void 	pa_pb(t_stack **stack_a, t_stack **stack_b, int move);
void	rotate_stack(t_stack **stack);
void	ra_rb_rr(t_stack **stack_a, t_stack **stack_b, int move);
void	revers_stack(t_stack **stack);
void	rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b, int move);
void	sort_stack(t_stack **a, t_stack **b);
void	tiny_sort(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	k_sort(t_stack **a, t_stack **b, int length);
void	push_back_to_a(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	free_split(char **str);

int		valid_nbr(char *str);
int		is_sorted(t_stack *stack);
int		size_stack(t_stack *stack);
long	ft_atoi_push_swap(const char *str);

char 	**push_swap_split(char const *s, char c);
char	**id_args(int argc, char **argv, int *need_free);

t_stack	*new_node_stack(int value);
t_stack	*put_stack_a(char **argv);

#endif