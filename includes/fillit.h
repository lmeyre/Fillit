/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:53:20 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/21 19:50:26 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_struct
{
	int check_stop;
	int diez_stop;
	int index;
	int space;
}				t_struct;

void			ft_free_strtab(char **tab);
char			*ft_is_valid_input(int argc, char **argv, int *nb);
void			ft_uncopy(char *dst, const char *src, char c, int sqr_size);
char			*ft_strstrp(const char *haystack, char *needle, int sqr_size);
int				ft_little_square(int nb);
char			*ft_read_tostr(char **argv);
char			*ft_final_square(int size);
int				ft_do_the_job(char *square, char **all_piece,
				int sqr_size, int index);
char			*ft_strcpy_avoid(char *dest, const char *src,
				int index, int sqr_size);
char			**ft_extract_shapes(char *str, int i, int size);
char			**ft_create_table(char **tab);
char			**ft_set_dna(char *str, int sqr_size, int nb_shapes);

#endif
