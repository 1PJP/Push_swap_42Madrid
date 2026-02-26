/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:52:52 by jezambra          #+#    #+#             */
/*   Updated: 2026/02/26 21:19:15 by jezambra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*usamos el split para tomar en cuenta el caso en el que nos pasen algo como "1 2 3 4"
 ya que aqui solo toma en cuenta 2 argumentos el ./a.out y lo que esta dentro de las ""
 no es lo mismo que hagamos algo como 1 2 3 4 sin comillas aqui ya toma en cuenta 5 
 argumentos con el ./a.out*/

static void	words_in_box(char **str, char const *s, char c, int word)
{
	int	i;
	int	j;
	int	i2;

	i = 0;
	j = 0;
	while (j < word)
	{
		i2 = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			str[j][i2] = s[i];
			i2++;
			i++;
		}
		str[j][i2] = '\0';
		j++;
	}
}

static char	**free_memory(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

static char	**words_save_memory(char const *s, char c, int word)
{
	char	**str;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	str = malloc(sizeof(char const *) * (word + 1));
	if (!str)
		return (NULL);
	while (j < word)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[j] = malloc(i - start + 1);
		if (!str[j])
			return (free_memory(str, j));
		j++;
	}
	str[j] = NULL;
	return (str);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

char	**push_swap_split(char const *s, char c)
{
	char	**str;
	int		word;

	if (!s)
		return (NULL);
	word = count_words(s, c);
	str = words_save_memory(s, c, word);
	if (!str)
		return (NULL);
	words_in_box(str, s, c, word);
	return (str);
}