/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:31:26 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/23 22:09:33 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//imprime un mensaje de error y termina el programa
void	ctrl_error(void)
{
	write(2, "Error\n", 6);
	exit (1);//con esto termina el programa inmediatamnte
}
//con esta funcion validamos que el string sea entero valido
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
//convierte un strig a numero 
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