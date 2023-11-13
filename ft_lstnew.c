/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:45:52 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/13 20:22:40 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list  *ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
    ret->content = content;
    ret->next = NULL;
	return (ret);
}
