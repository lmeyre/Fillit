/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:14:13 by emuckens          #+#    #+#             */
/*   Updated: 2017/12/05 14:14:18 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char		*ft_begin_cmp(const char *haystack,
		char *needle, int sqr_size, int i)
{
	int		prob;
	int		delta;
	int		j;

	j = 0;
	delta = sqr_size - 4;
	prob = 0;
	while ((haystack[i] == '.') && !prob)
	{
		++i;
		++j;
		if (needle[j] == '.')
		{
			i += delta + 1;
			while (needle[j] == '.')
			{
				++i;
				++j;
			}
		}
		haystack[i] == '\n' ? ++prob : prob;
		if (needle[j] == '\0')
			return ((char*)haystack);
	}
	return (NULL);
}

static	char		*ft_begin_cmp_littlsqr(const char *haystack,
		char *needle, int i, int j)
{
	int	prob;

	prob = 0;
	while (((haystack[i] == '.') || (needle[j] == '.'
					&& haystack[i] != '\n')) && !prob)
	{
		++i;
		++j;
		if (needle[j] == 'A' && haystack[i] != '\n')
			++prob;
		if (needle[j] == 'A' && haystack[i] == '\n')
			++j;
		if (haystack[i] == '\n' && needle[j] == '#' && needle[j - 1] == '#')
			++prob;
		if (haystack[i] == '\n')
			++i;
		if (needle[j] == '\0')
			return ((char*)haystack);
	}
	return (NULL);
}

char				*ft_strstrp(const char *haystack, char *needle,
		int sqr_size)
{
	char	*str;

	if (sqr_size > 3)
	{
		if ((str = ft_begin_cmp(haystack, needle, sqr_size, 0)))
			return (str);
		else
			return (NULL);
	}
	if ((str = ft_begin_cmp_littlsqr(haystack, needle, 0, 0)))
		return (str);
	return (NULL);
}

char				*ft_strcpy_avoid(char *dst, const char *src,
		int index, int sqr_size)
{
	int i;
	int j;
	int delta;

	delta = sqr_size - 4;
	i = 0;
	j = -1;
	while (src[++j])
	{
		if (src[j] == '.' && sqr_size > 3)
		{
			i += delta + 1;
			while (src[j] == '.')
			{
				++i;
				++j;
			}
		}
		dst[i] == '\n' ? ++i : i;
		src[j] == 'A' ? ++j : j;
		if (src[j] != '.' && src[j] != '\n')
			dst[i] = src[j] + 30 + index;
		++i;
	}
	return (dst);
}
