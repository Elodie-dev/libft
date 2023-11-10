/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:41:20 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/09 18:24:30 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*ft_defstart(char const *s1, char const	*set)
// {
// 	int	i;
// 	char

// 	i = 0;
// 	while (*s1)
// 	{
		
// 	}	
// }



char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;
	size_t	endlen;

	if (!s1)
	{
		ret = malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
	}
	start = ft_strchr(s1, ft_strlen(set));
	end = ft_strrchr(start, ft_strlen(set));
	endlen = ft_strlen(end);	
	ret = malloc(endlen + 2);
	ret = end;
	ret[endlen] = '\0';
	return (ret);
}
