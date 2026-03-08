/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split_ulties.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:40:36 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/08 22:10:29 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

//aqui vamos a liberar el split para las fugas
void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
/*esta funcion identifica si se usa o no el split, si solo ve 2 arg usa split
de lo contrario usa arg normal*/
char	**id_args(int argc, char **argv, int *need_free, int has_flag)
{
	char	**id;
	int		start;

	*need_free = 0;
	start = 1 + has_flag; /* saltamos ./push_swap + todas las flags */
	if (argc - has_flag == 2) /* solo un argumento de números (con "") */
	{
		id = push_swap_split(argv[start], ' ');
		if (!id)
			ctrl_error();
		*need_free = 1;
	}
	else
		id = argv + start;
	return (id);
}
static int	ft_strcmp_ps(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/* Detecta si el primer argumento es una flag y devuelve qué algoritmo usar.
   0 = adaptive (defecto)
   1 = simple
   2 = medium
   3 = complex */
int	get_flag(int argc, char **argv, int *is_bench)
{
	int	i;
	int	flag;

	flag = 0;
	*is_bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp_ps(argv[i], "--simple") == 0)
			flag = 1;
		else if (ft_strcmp_ps(argv[i], "--medium") == 0)
			flag = 2;
		else if (ft_strcmp_ps(argv[i], "--complex") == 0)
			flag = 3;
		else if (ft_strcmp_ps(argv[i], "--adaptive") == 0)
			flag = 0;
		else if (ft_strcmp_ps(argv[i], "--bench") == 0)
			*is_bench = 1;
		else
			ctrl_error();
		i++;
	}
	return (flag);
}
