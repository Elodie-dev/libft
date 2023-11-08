/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:54 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/08 10:37:22 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(dest));
	else
	{
		while (i < size - 1)
			i++;
		if (dest[i] != '\0')
			return (ft_strlen(dest) + size);
		else
		{
			if (size > i + 1)
			{
				while (j < size - i)
					dest[i++] = src[j++];
				dest[i] = '\0';
				return (ft_strlen(dest) + j);
			}
			else
				return (ft_strlen(dest));
		}
	}
}
