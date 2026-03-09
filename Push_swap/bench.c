/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:28:37 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/09 20:33:42 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* escribe un numero entero en el file descriptor dado
   se llama a si misma recursivamente para escribir digito a digito */
static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd); /* escribe los digitos anteriores primero */
	c = (n % 10) + '0'; /* convierte el ultimo digito a caracter */
	write(fd, &c, 1);
}

/* escribe un string caracter a caracter en el file descriptor dado */
static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* escribe un float con dos decimales en el file descriptor dado
   separa la parte entera de la decimal para escribirlas por separado */
static void	print_float(float f, int fd)
{
	int	integer;
	int	decimal;

	integer = (int)f; /* parte entera */
	decimal = (int)((f - integer) * 100); /* dos decimales */
	ft_putnbr_fd(integer, fd);
	write(fd, ".", 1);
	if (decimal < 10) /* si el decimal es menor que 10 añadimos un 0 delante */
		write(fd, "0", 1);
	ft_putnbr_fd(decimal, fd);
}

/* devuelve el nombre de la estrategia usada y su clase de complejidad
   si es adaptive, usa el indice de desorden para determinar cual se uso */
static char	*get_strategy_name(int flag, float disorder)
{
	if (flag == 1)
		return ("Simple / O(n^2)");
	if (flag == 2)
		return ("Medium / O(n*sqrt(n))");
	if (flag == 3)
		return ("Complex / O(n log n)");
	if (disorder < 0.2) /* desorden bajo → O(n) */
		return ("Adaptive / O(n)");
	if (disorder < 0.5) /* desorden medio → O(n*sqrt(n)) */
		return ("Adaptive / O(n*sqrt(n))");
	return ("Adaptive / O(n log n)"); /* desorden alto → O(n log n) */
}

/* imprime por stderr todas las metricas del modo benchmark:
   indice de desorden, estrategia usada, total de operaciones
   y desglose por tipo de operacion */
void	print_bench(t_bench *bench, float disorder, int flag)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_float(disorder * 100, 2); /* mostramos el desorden en porcentaje */
	write(2, "%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(get_strategy_name(flag, disorder), 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2); /* total de operaciones realizadas */
	write(2, "\n", 1);
	ft_putstr_fd("[bench] sa: ", 2);	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb: ", 2);		ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("  ss: ", 2);		ft_putnbr_fd(bench->ss, 2);//esto nevesito redicir lineas esprovicional
	ft_putstr_fd("  pa: ", 2);		ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("  pb: ", 2);		ft_putnbr_fd(bench->pb, 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] ra: ", 2);	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("  rb: ", 2);		ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("  rr: ", 2);		ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("  rra: ", 2);		ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("  rrb: ", 2);		ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);		ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}