/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:05:31 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/14 15:45:29 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *ret;
    t_list  *value;

    ret = NULL;
    while (lst)
    {
        value = ft_lstnew(f(lst->content));
        if (!value)
        {
            ft_lstclear(&ret, del);
            return (NULL);
        }
        ft_lstadd_back(&ret, value);
        lst = lst->next;
    }
    return (ret);
}
