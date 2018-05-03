/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:13:52 by emuckens          #+#    #+#             */
/*   Updated: 2017/12/06 15:13:12 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_create_table(char **tab)
{
	if (!(tab = (char **)malloc(sizeof(char*) * 14 + 1)))
		return (NULL);
	tab[0] = ft_strnew(4);
	tab[1] = ft_strnew(17);
	tab[2] = ft_strnew(20);
	tab[3] = ft_strnew(23);
	tab[4] = ft_strnew(8);
	tab[5] = ft_strnew(39);
	tab[6] = ft_strnew(32);
	tab[9] = ft_strnew(13);
	if (!(tab[0] && tab[1] && tab[2] && tab[3] && tab[4] && tab[5]
				&& tab[6] && tab[9]))
		return (NULL);
	ft_strcpy(tab[0], "1111");
	ft_strcpy(tab[1], "11011X11101X10111");
	ft_strcpy(tab[2], "110011X100111X111001");
	ft_strcpy(tab[3], "1100011X1110001X1000111");
	ft_strcpy(tab[4], "10011001");
	ft_strcpy(tab[5], "100011001X110010001X100110001X100010011");
	ft_strcpy(tab[6], "1000110001X1000100011X1100010001");
	ft_strcpy(tab[9], "1000100010001");
	tab[7] = NULL;
	tab[8] = NULL;
	return (tab);
}

static int	ft_check_end_shape(char **str, int *i, int *nblines, int *nb_shapes)
{
	if ((*str)[*i + 1] == '\n' || !((*str)[*i + 1]))
	{
		if (*nblines != 4)
			return (0);
		*nblines = 1;
		(*nb_shapes)++;
		++(*i);
		(*str)[*i] == '\n' ? (*str)[*i] = 'Y' : (*str)[*i];
		if (*nblines == 4 && (*str)[*i + 1])
			return (0);
	}
	return (1);
}

static int	ft_nb_shapes(char *str)
{
	int		i;
	int		nb_shapes;
	int		linelen;
	int		nblines;

	i = -1;
	linelen = 0;
	nblines = 1;
	nb_shapes = 0;
	while (str[++i])
	{
		while (str[i] != '\n' && str[i++])
			++linelen;
		if (str[i - 1] == '\0')
			return (0);
		if (linelen != 4 || (linelen == 4 && str[i] != '\n'))
			return (0);
		str[i + 1] != '\n' && str[i + 1] != '\0' ? ++nblines : nblines;
		str[i + 1] != '\n' && str[i + 1] != '\0' ? linelen = 0 : linelen;
		if (!(ft_check_end_shape(&str, &i, &nblines, &nb_shapes)))
			return (0);
		linelen = 0;
	}
	return (!str[i] && str[i - 1] != 'Y' ? nb_shapes : 0);
}

char		*ft_is_valid_input(int argc, char **argv, int *nb)
{
	char *str;

	if (argc != 2)
	{
		ft_putstr("Usage: fillit input_file\n");
		return (NULL);
	}
	str = ft_read_tostr(argv);
	if (!str)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	*nb = ft_nb_shapes(str);
	if (!(*nb))
	{
		ft_putstr("error\n");
		return (NULL);
	}
	return (str);
}
