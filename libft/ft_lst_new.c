/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:10:03 by lmeyre            #+#    #+#             */
/*   Updated: 2017/11/23 00:10:07 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_new(void const *content, size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		ptr->content = ft_memalloc(content_size);
		ptr->content = ft_strcpy(ptr->content, content);
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
