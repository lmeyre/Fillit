/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:14:30 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/23 00:14:31 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr;
	t_list	*tmp2;

	if (!(del) || !(alst) || !(*alst))
		return ;
	del((*alst)->content, (*alst)->content_size);
	curr = (*alst)->next;
	while (curr != NULL)
	{
		del(curr->content, curr->content_size);
		tmp2 = curr->next;
		free(curr);
		curr = tmp2;
	}
	free(*alst);
	*alst = NULL;
}
