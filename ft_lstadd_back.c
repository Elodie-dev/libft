/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:30 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/14 14:48:34 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;
    
    if (!*lst)
        *lst = new;
    else
    {
        temp = *lst;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}