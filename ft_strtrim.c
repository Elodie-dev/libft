/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:41:20 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/09 12:56:09 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	ret = malloc((sizeof(char) * (ft_strlen(s1) - ft_strlen(set))) + 1);
	if (!ret)
		return (NULL);
	while (*s1)
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == *s1)
			{
				s1++;
				j++;
			}
			j++;
		}
		ret[i] = *s1;
		s1++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// int	main(void)
// {
// 	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char *strtrim;

// 	strtrim = ft_strtrim(s1, " ");
// 	if (!strtrim)
// 		printf("%s", "NULL");
// 	else
// 	{
// 		if (strtrim == s1)
// 			printf("%s", "\nA new string was not returned");
// 		else
// 			printf("%s", strtrim);
// 	}
// 	return (0);
// }