/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:14:56 by emuckens          #+#    #+#             */
/*   Updated: 2017/12/08 14:40:48 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_little_square(int nb)
{
	int size;
	int i;

	i = 1;
	size = nb * 4;
	while ((i * i) < size)
		++i;
	return (i);
}

char		*ft_final_square(int size)
{
	int		i;
	char	*str;

	i = 2;
	str = ft_strnew((size + 1) * size * sizeof(*str));
	str = (char*)ft_memset((void*)str, '.', (size + 1) * size);
	if (!str)
		return (NULL);
	str[size] = '\n';
	while (i <= size)
	{
		str[(i * (size + 1)) - 1] = '\n';
		++i;
	}
	return (str);
}

char		*ft_read_tostr(char **argv)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = (char*)ft_strnew(600);
	fd = open(argv[1], O_RDONLY, S_IREAD);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, 600);
	buf[ret] = '\0';
	fd = close(fd);
	return (buf[0] ? buf : NULL);
}

static void	ft_dna_shrink(char **dna)
{
	int i;
	int j;

	i = -1;
	if (ft_strlen(*dna) == 13 || ft_strlen(*dna) == 4)
		return ;
	while ((*dna)[++i])
		if ((*dna)[i] == '.' && (*dna)[i + 1] == '#')
		{
			if ((*dna)[i - 1] == '#')
				(*dna)[i++] = 'A';
			else
			{
				j = i;
				while ((*dna)[j])
				{
					(*dna)[j] = (*dna)[j + 1];
					++j;
				}
				while ((*dna)[j - 1] != '#')
					--j;
				(*dna)[j + 1] = 0;
			}
		}
}

char		**ft_set_dna(char *str, int sqr_size, int nb_shapes)
{
	char	**dna;
	int		k;

	k = 0;
	dna = ft_extract_shapes(str, -1, 0);
	if (!dna)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	if (sqr_size == 2 && ft_strequ(dna[0], "##..##"))
	{
		ft_putstr("AA\nAA\n");
		return (0);
	}
	else
	{
		if (sqr_size < 4)
			while (k < nb_shapes)
			{
				ft_dna_shrink(&dna[k]);
				++k;
			}
	}
	return (dna);
}
