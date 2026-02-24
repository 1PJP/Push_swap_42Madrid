/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:17:00 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/24 15:47:26 by jezambra         ###   ########.fr       */
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
void	stack_add_back(t_stack **stack, t_stack *nodo);
int		valid_nbr(char *str);
long	ft_atoi_push_swap(const char *str);
t_stack	*new_node_stack(int value);
t_stack	*put_stack_a(int argc, char **argv);

#endif