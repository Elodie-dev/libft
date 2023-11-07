/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:30:54 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/07 10:57:37 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c || *(s + 1) == '\0')
			count++;
		s++;
	}
	return (count);
}

int	*ft_countwordsize(int count, char const *s, char c)
{
	int	size;
	int	*ret;
	int	i;

	size = 0;
	i = 0;
	ret = malloc(sizeof(int) * count);
	if (ret == NULL)
		return (0);
	while (*s)
	{
		if (*s == c || *(s + 1) == '\0')
		{
			if (*(s + 1) == '\0')
				ret[i] = size + 1;
			else
				ret[i] = size;
            size = 0;
            i++;
		}
		else
			size++;
		s++;
	}
	return (ret);
}

char	**ft_setmem(int count)
{
	char	**ret;

	ret = malloc(sizeof(char *) * (count + 1));
	if (ret == NULL)
		return (0);
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	// int		j;
	int		count;
    int     *val;
	char	**ret;

	i = 0;
	count = ft_countword(s, c);
    val = ft_countwordsize(count, s, c);
	ret = ft_setmem(count);
	while (i < count)
	{
		// j = 0;
		*ret = malloc((sizeof(char) * val[i]) + 1);
		while (*s != c && *s != '\0')
		{
			**ret = *s;
			// j++;
			s++;
            *ret++;
		}
		**ret = '\0';
		i++;
		s++;
        ret++;
	}
	*ret = NULL;
    free (val);
	return (ret);
}

int	main(void)
{
	char const *s = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
	char c = ',';
    char **str;
	int i;

	i = 0;
    str = ft_split(s, c);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}