/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:31:26 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 20:50:14 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ctrl_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	valid_nbr(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi_push_swap(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ctrl_error();
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr = nbr * sign;
	check_int_range(nbr);
	return (nbr);
}

void	check_int_range(long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		ctrl_error();
}

void	duplicates(t_stack *stack)
{
	t_stack	*put_nbr;
	t_stack	*cmp;

	put_nbr = stack;
	while (put_nbr)
	{
		cmp = put_nbr->next;
		while (cmp)
		{
			if (put_nbr->value == cmp->value)
				ctrl_error ();
			cmp = cmp->next;
		}
		put_nbr = put_nbr->next;
	}
}
