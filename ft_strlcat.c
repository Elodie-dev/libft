/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:54 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/03 10:31:42 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <bsd/string.h>

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

// int main()
// {
//     char dst[100] = "1234";
//     char src[100] = "ABCD";
//     char dst1[100] = "1234";
//     char src1[100] = "ABCD";

//     strlcat(dst, src, 2);
//     printf("%s\n", dst);
//     ft_strlcat(dst1, src1, 2);
//     printf("%s\n", dst);
//     printf("%zu\n%zu", strlcat(dst, src, 2), ft_strlcat(dst1, src1, 2));
// }