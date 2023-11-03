/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:57:03 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/03 12:09:55 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (&((char *)s)[i]);
	else
	{
		while (i >= 0)
		{
			if (s[i] == c)
				return (&((char *)s)[i]);
			i--;
		}
	}
	return (NULL);
}
/*
int main () {
   const char str[] = "https://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;
   char *myret;

   ret = strrchr(str, ch);
   myret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("String after |%c| is - |%s|\n", ch, myret);

   return(0);
}*/