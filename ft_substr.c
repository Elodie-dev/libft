/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:49:47 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/09 13:48:38 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		ret = malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
