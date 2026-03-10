/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:52:43 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 21:07:48 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

float	compute_disorder(t_stack *stack)
{
	t_stack	*out;
	t_stack	*in;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	out = stack;
	while (out)
	{
		in = out->next;
		while (in)
		{
			total_pairs++;
			if (out->value > in->value)
				mistakes++;
			in = in->next;
		}
		out = out->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

void	ft_memset_ps(void *ptr, int value, int size)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < size)
	{
		p[i] = (unsigned char)value;
		i++;
	}
}
