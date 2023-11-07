/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:41:20 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/07 12:12:42 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) - ft_strlen(set)) + 1);
	if (ret == NULL)
		return (NULL);
	while (*s1)
	{
		if (*s1 == set[j])
			j++;
		else
		{
			ret[i] = *s1;
			i++;
		}
		s1++;
	}
	ret[i] = '\0';
	return (ret);
}
