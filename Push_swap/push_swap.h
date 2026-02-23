/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:17:00 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/23 22:21:01 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

//struct con lista doble
typedef struct	s_stack
{
	int	value;//numero que queremos ordenar
	int	index;//indice para el ordenamineto
	struct s_stack	*next;//sigiiente nodo
	struct s_stack	*prev;//nodo anterior 
}		t_stack;

void	ctrl_error(void);
int		valid_nbr(char *str);
long	ft_atoi_push_swap(const char *str);


#endif