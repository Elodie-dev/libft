/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:41:20 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/10 17:27:03 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	start;
	char	*ret;
	
	i = 0;
	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (start < end && ft_isset(set, s1[start]))
		start++;
	while (end > start && ft_isset(set, s1[end - 1]))
		end--;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (NULL);
	while (start < end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}

// int main(void)
// {
//   char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
//   char *strtrim = ft_strtrim(s1, " ");
  
//   if (!strtrim)
//     printf("%s", "NULL");
//   else if (strtrim == s1)
//     printf("%s", "\nA new string was not returned");
//   else
//     printf("%s", strtrim);
//   return (0);
// }
