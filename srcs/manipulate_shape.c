/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_shape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:14:43 by emuckens          #+#    #+#             */
/*   Updated: 2017/12/06 15:10:37 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_free_strtab(char **tab)
{
	int i;

	i = 0;
	while ((tab)[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static void		ft_remove_nl(char **s)
{
	int		i;
	int		j;

	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '\n')
		{
			j = i;
			while ((*s)[j])
			{
				(*s)[j] = (*s)[j + 1];
				j++;
			}
			(*s)[j] = '\0';
		}
		++i;
	}
}

static int		ft_custrim(char **s)
{
	int			len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = 15;
	if (!s)
		return (-1);
	ft_remove_nl(s);
	while ((*s)[len] == '.')
		len--;
	(*s)[len + 1] = '\0';
	while ((*s)[j] == '.')
		j++;
	while (j && (*s)[j])
	{
		(*s)[i] = (*s)[j];
		(*s)[j] = 0;
		++j;
		++i;
	}
	while (j && (*s)[--j] != '#')
		(*s)[j] = 0;
	return (0);
}

static int		ft_strstr_int(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	int			k;

	if (!(needle[0]) || !needle || !haystack)
		return (0);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		k = i;
		while ((needle[j] == '#' && haystack[i] == '1')
				|| (needle[j] == '.' && haystack[i] == '0'))
		{
			++i;
			++j;
			if (needle[j] == '\0')
				return (1);
		}
		j = 0;
		i = k;
		++i;
	}
	return (0);
}

char			**ft_extract_shapes(char *str, int i, int size)
{
	char	**all_pieces;
	char	**tab;

	tab = NULL;
	if (!(all_pieces = ft_strsplit(str, 'Y')))
		return (NULL);
	if (!(tab = ft_create_table(tab)))
		return (NULL);
	while (all_pieces[++i] != NULL)
	{
		if (ft_custrim(&all_pieces[i]) == -1)
		{
			ft_free_strtab(tab);
			return (NULL);
		}
		size = ft_strlen(all_pieces[i]) - 4;
		if (!ft_strstr_int(tab[size], all_pieces[i]))
		{
			ft_free_strtab(tab);
			return (NULL);
		}
	}
	ft_free_strtab(tab);
	return (all_pieces);
}
