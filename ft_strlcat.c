/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:54 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/03 12:15:30 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (i < size)
	{
		while (j < size - i)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (i + j + 2);
}
