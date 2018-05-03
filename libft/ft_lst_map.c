/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:12:03 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/23 00:12:16 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_map(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*curr;

	if (!(lst))
		return (NULL);
	if (!(curr = ft_lst_new(lst->content, lst->content_size)))
		return (NULL);
	curr = f(curr);
	curr->next = ft_lst_map(lst->next, f);
	return (curr);
}
