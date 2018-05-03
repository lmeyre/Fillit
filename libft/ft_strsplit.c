/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:03:00 by lmeyre            #+#    #+#             */
/*   Updated: 2017/12/03 16:40:27 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			words_nbr(const char *s, char c)
{
	int i;
	int count;
	int boool;

	boool = 1;
	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			i++;
			boool == 1 ? count++ : boool;
			boool == 1 ? boool-- : boool;
		}
		else if (s[i] == c)
		{
			boool = 1;
			while (s[i] == c)
				i++;
		}
	}
	return (count);
}

static char			**ft_tab(char **tab, char const *s, int k, int c)
{
	int i;
	int start;

	i = 0;
	while (s[i])
	{
		s[i] == c ? i++ : i;
		if (s[i] != c && s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[k] = ft_strsub(s, start, i - start);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	if (!(s))
		return (0);
	k = 0;
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (words_nbr(s, c) + 1))))
		return (0);
	i = words_nbr(s, c);
	i = 0;
	tab = ft_tab(tab, s, k, c);
	return (tab);
}
