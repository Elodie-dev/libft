/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:33:01 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/03 11:55:45 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (&((char *)s)[i]);
	else
		return (NULL);
}
/*
int main () {
   const char str[] = "https://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;
   char *myret;

   ret = strchr(str, ch);
   myret = ft_strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("String after |%c| is - |%s|\n", ch, myret);

   return(0);
}*/