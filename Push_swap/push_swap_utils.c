/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:31:26 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/24 17:17:22 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//David esta son las funciones que estamos utilizando, dejo un comentario en cada una.
//imprime un mensaje de error y termina el programa
void	ctrl_error(void)
{
	write(2, "Error\n", 6);
	exit (1);//con esto termina el programa inmediatamnte
}
/*con esta funcion validamos que el string sea entero valido, pordiamos usar la funcion
de la libft que tambien sirve, pero estoy probando esta, si algo no te cuadra la modificas*/
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
/*convierte un strig a numero es un atoi de toda la vida pero sin los espacios, al igual si
algo no te convence lo cambias*/
long	ft_atoi_push_swap(const char *str)
{
	long	nbr;
	int	sign;
	int	i;

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
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
/*esta funcion nos sirve para comparar enteroes duplucados, si estan duplicados retorna error y 
termina el programa*/
void	duplicates(t_stack *stack)
{
	t_stack	*put_nbr;//nodo que comparamos
	t_stack	*cmp;//nodo que usamos para comparar el siguiente

	put_nbr = stack;
	while (put_nbr)
	{
		cmp = put_nbr->next;
		while (cmp)
		{
			if (put_nbr->value == cmp->value)//si encuetra otro nodo con el mismo valor da error y termina el programa
				ctrl_error ();
			cmp = cmp->next;//avanza al siguiente nodo para continuar comparando
		}
		put_nbr = put_nbr->next;//pasa al siguinete noto y repite todo
	}
}