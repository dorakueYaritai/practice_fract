/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:02:41 by kakiba            #+#    #+#             */
/*   Updated: 2022/12/10 11:57:42 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	ft_lstlast(new)-> next = (*lst);
	*lst = new;
}


// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (lst == NULL || new == NULL)
// 		return ;
// 	if (*lst == NULL)
// 		new -> next = NULL;
// 	else
// 		ft_lstlast(new)-> next = (*lst);
// 	*lst = new;
// }
