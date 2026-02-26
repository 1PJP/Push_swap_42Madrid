/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split_ulties.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:40:36 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/26 21:12:41 by jezambra         ###   ########.fr       */
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
char	**id_args(int argc, char **argv, int *need_free)
{
	char	**id;

	*need_free = 0;//iniciamos en 0 por que aun no hay que liberar nada
	if (argc == 2)//si hay solo 2 args o mas si hay hacemos split
	{
		id = push_swap_split(argv[1], ' ');//separamos los numeros si estan ""
		if (!id)
			ctrl_error();//si falla da error y sale del programa
		*need_free = 1;//hay que liberar luego
	}
	else
		id = argv + 1;//// apuntamos a los números, saltando ./a.out eso quiere decir que no se usa split
	return (id);
}