/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:14:29 by emuckens          #+#    #+#             */
/*   Updated: 2018/03/21 14:47:51 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_put_piece(char *square, char *piece, int sqr_size, int index)
{
	char	*str;

	str = ft_strstrp(square, piece, sqr_size);
	if (!(str))
		return (0);
	ft_strcpy_avoid(str, piece, index, sqr_size);
	return (1);
}

static	int		ft_find_pos(t_struct data, int position, char *square)
{
	if (data.space < data.diez_stop)
	{
		data.space = 0;
		while (data.space < data.diez_stop && square[position])
		{
			if (square[position] != '.')
				data.space = 0;
			else if (square[position] == '.')
				++(data.space);
			++position;
		}
		if (data.space == data.diez_stop)
			return (position - data.space);
		else
			return (-1);
	}
	while (square[position] != '.')
	{
		++position;
		if (!(square[position]))
			return (-1);
	}
	return (position);
}

static	int		ft_do_the_big_job(char *square,
		char **all_piece, int sqr_size, t_struct data)
{
	int position;

	position = 0;
	while (square[position])
	{
		if ((position = ft_find_pos(data, position, square)) == -1)
			return (-1);
		if (ft_put_piece(square + position,
					all_piece[data.index], sqr_size, data.index))
		{
			if (ft_do_the_job(square, all_piece, sqr_size, data.index + 1) == 1)
				return (1);
			ft_uncopy(square + position, all_piece[data.index], '\n', sqr_size);
		}
		++position;
	}
	return (-1);
}

int				ft_do_the_job(char *square, char **all_piece,
		int sqr_size, int index)
{
	int			count;
	int			i;
	t_struct	data;

	data.space = 0;
	i = -1;
	count = 1;
	data.diez_stop = 0;
	data.index = index;
	if (all_piece[index] == NULL)
		return (1);
	while (all_piece[index][++i] == '#')
		++(data.diez_stop);
	data.diez_stop < 3 ? data.diez_stop = -1 : data.diez_stop;
	if ((ft_do_the_big_job(square, all_piece, sqr_size, data) == 1))
		return (1);
	return (-1);
}

void			ft_uncopy(char *dst, const char *src, char c, int sqr_size)
{
	int i;
	int j;
	int delta;

	delta = sqr_size - 4;
	i = 0;
	j = 0;
	while (src[j])
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
		if (dst[i] == c)
			i++;
		if (src[j] == '#' || src[j] == 'A')
			dst[i] = '.';
		i++;
		j++;
	}
}
