/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split_ulties.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:40:36 by jezambra          #+#    #+#             */
/*   Updated: 2026/03/10 20:52:45 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

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

char	**id_args(int argc, char **argv, int *need_free, int has_flag)
{
	char	**id;
	int		start;

	*need_free = 0;
	start = 1 + has_flag;
	if (argc - has_flag == 2)
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
