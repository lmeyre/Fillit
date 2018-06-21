/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:45:07 by emuckens          #+#    #+#             */
/*   Updated: 2017/12/05 17:26:01 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_launch_job(char *input, int nb_shapes)
{
	char	**dna;
	char	*final_str;
	int		sqr_size;

	sqr_size = ft_little_square(nb_shapes);
	while (1)
	{
		if (!(dna = ft_set_dna(input, sqr_size, nb_shapes)))
			return ;
		final_str = ft_final_square(sqr_size);
		if (ft_do_the_job(final_str, dna, sqr_size, 0) == 1)
		{
			ft_putstr(final_str);
			ft_memdel((void**)&final_str);
			free(input);
			ft_free_strtab(dna);
			return ;
		}
		else
		{
			++sqr_size;
			ft_free_strtab(dna);
			ft_memdel((void**)&final_str);
		}
	}
}

int			main(int argc, char **argv)
{
	char	*str;
	int		nb_shapes;

	if (!(str = ft_is_valid_input(argc, argv, &nb_shapes)))
		return (-1);
	ft_launch_job(str, nb_shapes);
	return (0);
}
